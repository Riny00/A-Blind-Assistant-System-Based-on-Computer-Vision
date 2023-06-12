#pragma once
#include<queue>
#include<pthread.h>
#include<iostream>

using namespace std;
using callback = void(*)(void* arg);//C++11新特性

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
    callback function;//函数返回值不需要操作
    void* arg;
};

class TaskQueue
{
public:
    TaskQueue();
    ~TaskQueue();

    //添加任务
    void addTask(Task task);
    void addTask(callback f,void* arg);
    //取出任务
    Task takeTask();
    //获取当前任务个数
    inline size_t taskNumber()
    {
        return m_taskQ.size();
    }
private:
    pthread_mutex_t m_mutex;

	queue<Task>m_taskQ;

};

