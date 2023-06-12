#pragma once
#include<queue>
#include<pthread.h>
#include<iostream>

using namespace std;
using callback = void(*)(void* arg);//C++11������

struct Task
{
    Task()
    {
        function = nullptr;
        arg = nullptr;
    }
    Task(callback f, void* arg)
    {
        this->arg = arg;
        function = f;
    }
    callback function;//��������ֵ����Ҫ����
    void* arg;
};

class TaskQueue
{
public:
    TaskQueue();
    ~TaskQueue();

    //�������
    void addTask(Task task);
    void addTask(callback f,void* arg);
    //ȡ������
    Task takeTask();
    //��ȡ��ǰ�������
    inline size_t taskNumber()
    {
        return m_taskQ.size();
    }
private:
    pthread_mutex_t m_mutex;

	queue<Task>m_taskQ;

};

