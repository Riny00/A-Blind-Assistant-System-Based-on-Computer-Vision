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
struct PACKET_HEAD//���ݰ�ͷ��
{
	Type type;
	int lenght;
};


void* heart_handler(void* arg);

class TCP_Server
{
public:
	TCP_Server(int port, char*IP);//��ʼ��
	~TCP_Server();//����
	void Bind();//��
	void Listen();//����

	void EPOLL();//epoll��·����

	void Recv_Package(int fd, PACKET_HEAD head);//���ܺ�����������or���ݣ�
	friend void* heart_handler(void* arg);//���������(�жϿͻ����Ƿ�����)

	void task();//��������

private:
	int port;//�˿�
	char* IP;//IP��ַ
	int lfd;//���ڼ������ļ�������
	struct sockaddr_in serv_addr;
	int epfd;//epollʵ��
	map<int, pair<string, int> >mmap;//map<fd, pair<ip, count>>

};

