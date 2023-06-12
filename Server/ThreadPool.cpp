#include "ThreadPool.h"
#include<string.h>
#include<string>
#include<unistd.h>
using namespace std;

ThreadPool::ThreadPool(int min, int max)
{
    do {
        minNum = min;
        maxNum = max;
        busyNum = 0;
        liveNum = min;//和最小个数相等
        exitNum = 0;
        shutdown = false;

        //实例化任务队列
        taskQ = new TaskQueue;
        if (taskQ == NULL)
        {
            cout << "malloc taskQ fail!\n" << endl;
            break;
        }

        threadIDs = new pthread_t[max];
        if (threadIDs == NULL)
        {
            cout << "malloc threadIDs fail!\n" << endl;
            break;
        }
        memset(threadIDs, 0, sizeof(pthread_t) * max);
        

        //如果初始化失败
        if (pthread_mutex_init(&mutexpool, NULL) != 0 ||
            pthread_cond_init(&notEmpty, NULL) != 0 )
        {
            cout << "mutex or condition init fail...\n" << endl;
            break;
        }

        //创建线程
        pthread_create(&managerID, NULL, manager, this);
        for (int i = 0; i < min; i++)
        {
            //子线程需要访问task，所以传入pool
            pthread_create(&threadIDs[i], NULL, worker, this);
            cout << "创建子线程, ID: " << to_string(threadIDs[i]) << endl;
        }
        return;
    } while (0);

    //释放资源
    if (threadIDs)delete[]threadIDs;
    if (taskQ)delete taskQ;
}

void* ThreadPool::worker(void* arg)//传递过来的线程池对象
{
    ThreadPool* pool = static_cast<ThreadPool*>(arg);
    while (1)
    {
        pthread_mutex_lock(&pool->mutexpool);
        //当前队列任务是否为空
        while (pool->taskQ->taskNumber() == 0 && !pool->shutdown)
        {
            //1、阻塞工作线程 2、如果队列不为空则基于notEmpty唤醒，向下执行
            pthread_cond_wait(&pool->notEmpty, &pool->mutexpool);

            //判断是不是要销毁线程
            if (pool->exitNum > 0)
            {
                pool->exitNum--;
                if (pool->liveNum > pool->minNum)
                {
                    pool->liveNum--;
                    pthread_mutex_unlock(&pool->mutexpool);
                    pool->threadExit();
                }
            }
        }

        //判断线程池是否被关闭
        if (pool->shutdown)
        {
            pthread_mutex_unlock(&pool->mutexpool);//避免死锁 
            pool->threadExit();
        }

        //从任务队列中取出一个任务
        Task task = pool->taskQ->takeTask();
        //环形队列，移动头节点
        //解锁
        pool->busyNum++;
        pthread_mutex_unlock(&pool->mutexpool);

        printf("thread %ld start working....\n", pthread_self());

        //执行函数
        task.function(task.arg);
        delete(task.arg);
        task.arg = NULL;

        printf("thread %ld end working..\n", pthread_self());
        pthread_mutex_lock(&pool->mutexpool);
        pool->busyNum--;
        pthread_mutex_unlock(&pool->mutexpool);
    }
    return NULL;
}

//用于创建和销毁线程
void* ThreadPool::manager(void* arg)
{
    ThreadPool* pool = (ThreadPool*)arg;
    while (!pool->shutdown)
    {
        //每隔3s检测一次
        sleep(3);

        //取出线程池中任务的数量和当前线程的数量
        //取出忙的线程数量
        pthread_mutex_lock(&pool->mutexpool);
        int queueSize = pool->taskQ->taskNumber();
        int liveNum = pool->liveNum;
        int busyNum = pool->busyNum;
        pthread_mutex_unlock(&pool->mutexpool);

        //添加线程
        // 任务个数> 存活的线程个数 && 存活的线程数 < 最大线程数
        if (queueSize > liveNum && liveNum < pool->maxNum)
        {
            pthread_mutex_lock(&pool->mutexpool);
            int counter = 0;
            for (int i = 0; i < pool->maxNum && counter < NUMBER
                && pool->liveNum < pool->maxNum; i++)
            {
                if (pool->threadIDs[i] == 0)//判断那个位置可以创建线程
                {
                    pthread_create(&pool->threadIDs[i], NULL, worker, pool);
                    counter++;
                    pool->liveNum++;
                }
            }
            pthread_mutex_unlock(&pool->mutexpool);
        }

        //销毁线程
        //忙的线程*2 <存活的线程数 && 存活的线程 >最小线程数
        if (busyNum * 2 < liveNum && liveNum > pool->minNum)
        {
            pthread_mutex_lock(&pool->mutexpool);
            pool->exitNum = NUMBER;
            pthread_mutex_unlock(&pool->mutexpool);

            //让工作的线程自杀（引导操作)
            for (int i = 0; i < NUMBER; i++)
            {
                pthread_cond_signal(&pool->notEmpty);
            }
        }
    }
    return NULL;
}
void ThreadPool::threadExit()
{

    pthread_t tid = pthread_self();
    cout << "maxNum:" << maxNum << endl;
    for (int i = 0; i <maxNum; ++i)
    {
        if (threadIDs[i] == tid)
        {
            threadIDs[i] = 0;
            printf("threadExit called %ld exiting\n", tid);
            break;
        }
    }
    pthread_exit(NULL);
    return;
}
void ThreadPool::addTask(Task task)
{
    //队列满了,不能继续添加任务，并且线程池未销毁
    if (shutdown)//如果线程池被销毁
    {
        return;
    }
    //添加任务
    taskQ->addTask(task);
    pthread_cond_signal(&notEmpty);
}
int ThreadPool::getBusyNum()
{
    pthread_mutex_lock(&mutexpool);
    int busyNum = this->busyNum;
    pthread_mutex_unlock(&mutexpool);
    return busyNum;
}
int ThreadPool::getAliveNum()
{
    pthread_mutex_lock(&mutexpool);
    int aliveNum = this->liveNum;
    pthread_mutex_unlock(&mutexpool);
    return aliveNum;
}
ThreadPool::~ThreadPool()
{
    //关闭线程池
    shutdown = true;
    //阻塞回收管理者线程

    //如果还有子线程在运行，调用该函数就会阻塞，子线程退出函数解除阻塞进行资源的回收，
    //函数被调用一次，只能回收一个子线程
    pthread_join(managerID, NULL);
    //唤醒阻塞的消费者
    for (int i = 0; i < liveNum; i++)
    {
        //唤醒后worker函数依次退出
        pthread_cond_signal(&notEmpty);
    }
    //释放堆内存
    if (taskQ)
    {
        delete taskQ;
    }
    if (threadIDs)
    {
        delete[]threadIDs;
    }

    pthread_mutex_destroy(&mutexpool);
    pthread_cond_destroy(&notEmpty);

}