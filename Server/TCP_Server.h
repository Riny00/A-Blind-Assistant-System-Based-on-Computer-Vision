#pragma once
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <string>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include<iostream>
#include<map>
#include"ThreadPool.h"

using namespace std;

enum Type{HEART,OTHER};
struct PACKET_HEAD//数据包头部
{
	Type type;
	int lenght;
};


void* heart_handler(void* arg);

class TCP_Server
{
public:
	TCP_Server(int port, char*IP);//初始化
	~TCP_Server();//析构
	void Bind();//绑定
	void Listen();//监听

	void EPOLL();//epoll多路复用

	void Recv_Package(int fd, PACKET_HEAD head);//接受函数（心跳包or数据）
	friend void* heart_handler(void* arg);//心跳包检测(判断客户端是否离线)

	void task();//总任务函数

private:
	int port;//端口
	char* IP;//IP地址
	int lfd;//用于监听的文件描述符
	struct sockaddr_in serv_addr;
	int epfd;//epoll实例
	map<int, pair<string, int> >mmap;//map<fd, pair<ip, count>>

};

