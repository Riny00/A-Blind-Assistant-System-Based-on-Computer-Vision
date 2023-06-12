#include"TCP_Server.h"
#include"ThreadPool.h"
#include<unistd.h>
#include<stdio.h>

//int main()
//{
//    TCP_Server s(9999, "172.24.155.18");
//    s.task();
//
//    return 0;
//}
void taskFunc(void* arg)
{
    int num = *(int*)arg;
    printf("thread %ld is working, number = %d\n",
        pthread_self(), num);
    cout << "workinginging" << endl;
    sleep(1);
}

int main()
{
    // 创建线程池
    ThreadPool pool(3, 10);
    for (int i = 0; i < 10; ++i)
    {
        int* num = (int*)malloc(sizeof(int));
        *num = i + 100;
        pool.addTask(Task(taskFunc,num));
    }

    sleep(10);

    return 0;
}
