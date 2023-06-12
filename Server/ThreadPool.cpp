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
        liveNum = min;//����С�������
        exitNum = 0;
        shutdown = false;

        //ʵ�����������
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
        

        //�����ʼ��ʧ��
        if (pthread_mutex_init(&mutexpool, NULL) != 0 ||
            pthread_cond_init(&notEmpty, NULL) != 0 )
        {
            cout << "mutex or condition init fail...\n" << endl;
            break;
        }

        //�����߳�
        pthread_create(&managerID, NULL, manager, this);
        for (int i = 0; i < min; i++)
        {
            //���߳���Ҫ����task�����Դ���pool
            pthread_create(&threadIDs[i], NULL, worker, this);
            cout << "�������߳�, ID: " << to_string(threadIDs[i]) << endl;
        }
        return;
    } while (0);

    //�ͷ���Դ
    if (threadIDs)delete[]threadIDs;
    if (taskQ)delete taskQ;
}

void* ThreadPool::worker(void* arg)//���ݹ������̳߳ض���
{
    ThreadPool* pool = static_cast<ThreadPool*>(arg);
    while (1)
    {
        pthread_mutex_lock(&pool->mutexpool);
        //��ǰ���������Ƿ�Ϊ��
        while (pool->taskQ->taskNumber() == 0 && !pool->shutdown)
        {
            //1�����������߳� 2��������в�Ϊ�������notEmpty���ѣ�����ִ��
            pthread_cond_wait(&pool->notEmpty, &pool->mutexpool);

            //�ж��ǲ���Ҫ�����߳�
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

        //�ж��̳߳��Ƿ񱻹ر�
        if (pool->shutdown)
        {
            pthread_mutex_unlock(&pool->mutexpool);//�������� 
            pool->threadExit();
        }

        //�����������ȡ��һ������
        Task task = pool->taskQ->takeTask();
        //���ζ��У��ƶ�ͷ�ڵ�
        //����
        pool->busyNum++;
        pthread_mutex_unlock(&pool->mutexpool);

        printf("thread %ld start working....\n", pthread_self());

        //ִ�к���
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

//���ڴ����������߳�
void* ThreadPool::manager(void* arg)
{
    ThreadPool* pool = (ThreadPool*)arg;
    while (!pool->shutdown)
    {
        //ÿ��3s���һ��
        sleep(3);

        //ȡ���̳߳�������������͵�ǰ�̵߳�����
        //ȡ��æ���߳�����
        pthread_mutex_lock(&pool->mutexpool);
        int queueSize = pool->taskQ->taskNumber();
        int liveNum = pool->liveNum;
        int busyNum = pool->busyNum;
        pthread_mutex_unlock(&pool->mutexpool);

        //����߳�
        // �������> �����̸߳��� && �����߳��� < ����߳���
        if (queueSize > liveNum && liveNum < pool->maxNum)
        {
            pthread_mutex_lock(&pool->mutexpool);
            int counter = 0;
            for (int i = 0; i < pool->maxNum && counter < NUMBER
                && pool->liveNum < pool->maxNum; i++)
            {
                if (pool->threadIDs[i] == 0)//�ж��Ǹ�λ�ÿ��Դ����߳�
                {
                    pthread_create(&pool->threadIDs[i], NULL, worker, pool);
                    counter++;
                    pool->liveNum++;
                }
            }
            pthread_mutex_unlock(&pool->mutexpool);
        }

        //�����߳�
        //æ���߳�*2 <�����߳��� && �����߳� >��С�߳���
        if (busyNum * 2 < liveNum && liveNum > pool->minNum)
        {
            pthread_mutex_lock(&pool->mutexpool);
            pool->exitNum = NUMBER;
            pthread_mutex_unlock(&pool->mutexpool);

            //�ù������߳���ɱ����������)
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
    //��������,���ܼ���������񣬲����̳߳�δ����
    if (shutdown)//����̳߳ر�����
    {
        return;
    }
    //�������
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
    //�ر��̳߳�
    shutdown = true;
    //�������չ������߳�

    //����������߳������У����øú����ͻ����������߳��˳������������������Դ�Ļ��գ�
    //����������һ�Σ�ֻ�ܻ���һ�����߳�
    pthread_join(managerID, NULL);
    //����������������
    for (int i = 0; i < liveNum; i++)
    {
        //���Ѻ�worker���������˳�
        pthread_cond_signal(&notEmpty);
    }
    //�ͷŶ��ڴ�
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