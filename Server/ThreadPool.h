#pragma once
#include"TaskQueue.h"

class ThreadPool
{
private:
    //�������
    TaskQueue* taskQ;
    
    pthread_t managerID;    //�������߳�ID  
    pthread_t* threadIDs;   //�������߳�ID
    int minNum;             //��С�߳�����
    int maxNum;             //����߳�����
    int busyNum;            //æ���̸߳���
    int liveNum;            //�����̸߳���
    int exitNum;            //���ٵ��̸߳���

    pthread_mutex_t mutexpool;  //�������̳߳أ�������ʣ�
    pthread_cond_t notEmpty;     //��������Ƿ��(��������)

    static const int NUMBER = 2;

    bool shutdown=false;               //�Ƿ������̳߳�,����Ϊ1������Ϊ0
public:
    //�����̳߳ز���ʼ��
    ThreadPool(int min, int max);

    //�����̳߳�
    ~ThreadPool();

    //���̳߳��������
    void addTask(Task task);

    //��ȡ�̳߳��й������̵߳ĸ���
    int getBusyNum();

    //��ȡ�̳߳��л��ŵ��̵߳ĸ���
    int getAliveNum();

private:
    //�������̣߳��������̣߳�
    static void* worker(void* arg);

    //�������߳�
    static void* manager(void* arg);

    //�����߳��˳�
    void threadExit();
};

