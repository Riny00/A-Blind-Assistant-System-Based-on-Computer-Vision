#pragma once
#include"TaskQueue.h"

class ThreadPool
{
private:
    //任务队列
    TaskQueue* taskQ;
    
    pthread_t managerID;    //管理者线程ID  
    pthread_t* threadIDs;   //工作的线程ID
    int minNum;             //最小线程数量
    int maxNum;             //最大线程数量
    int busyNum;            //忙的线程个数
    int liveNum;            //存活的线程个数
    int exitNum;            //销毁的线程个数

    pthread_mutex_t mutexpool;  //锁整个线程池（互斥访问）
    pthread_cond_t notEmpty;     //任务队列是否空(条件变量)

    static const int NUMBER = 2;

    bool shutdown=false;               //是否销毁线程池,销毁为1，否则为0
public:
    //创建线程池并初始化
    ThreadPool(int min, int max);

    //销毁线程池
    ~ThreadPool();

    //给线程池添加任务
    void addTask(Task task);

    //获取线程池中工作的线程的个数
    int getBusyNum();

    //获取线程池中活着的线程的个数
    int getAliveNum();

private:
    //消费者线程（工作的线程）
    static void* worker(void* arg);

    //管理者线程
    static void* manager(void* arg);

    //单个线程退出
    void threadExit();
};

