#include "TCP_Server.h"



TCP_Server::TCP_Server(int port, char*IP)
{
    //创建监听的套接字
    this->IP = IP;
    this->port = port;
    this->lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        perror("socket error");
        exit(1);
    }
    cout << "IP:" << this->IP << endl;
    cout << "port:" << this->port << endl;
}

TCP_Server::~TCP_Server()
{
    close(lfd);
}

void TCP_Server::Bind()
{
    memset(&serv_addr, 0, sizeof(serv_addr)); //将某一块内存中的内容全部设置为指定的值
    this->serv_addr.sin_family = AF_INET;
    this->serv_addr.sin_port = htons(port);
    this->serv_addr.sin_addr.s_addr = inet_addr(IP);

    //绑定端口
    int ret = bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret == -1)
    {
        perror("bind error");
        exit(1);//要求终止程序，非正常退出
    }
}

void TCP_Server::Listen()
{
    int ret = listen(lfd, 64);
    if (ret == -1)
    {
        perror("listen error");
        exit(1);
    }
}

void TCP_Server::Recv_Package(int fd, PACKET_HEAD head)
{
    //创建子线程判断客户端是否离线
    pthread_t HEART_TEST;
    int ret = pthread_create(&HEART_TEST, NULL, heart_handler, (void*)this);

    PACKET_HEAD HEAD=head;

    if (HEAD.type == HEART)//如果收到心跳数据包
    {
        mmap[fd].second = 0;
        cout << "Received heart-beat" << endl;
    }
    else //普通数据
    {
        cout << "putongshuj" << endl;
    }

}

void* heart_handler(void* arg)
{
    cout << "The heartbeat checking thread started"<<endl;
    TCP_Server* s = (TCP_Server*)arg;

    //迭代器指向首位
    map<int, pair<string, int> >::iterator it = s->mmap.begin();
    while (1)
    {
        for (; it != s->mmap.end();)//map<fd, pair<ip, count>>
        {
            if (it->second.second == 5)//服务端3s*5 未收到心跳包则客户端掉线
            {
                cout << "The client " << it->second.first << " has be offline.\n";
                int fd = it->first;
                epoll_ctl(s->epfd, EPOLL_CTL_DEL, fd, NULL);
                close(fd);

                s->mmap.erase(it++);  // 从map中移除该记录
            }
            else if (it->second.second < 5 && it->second.second >= 0)
            {
                it->second.second += 1;
                ++it;
            }
            else
            {
                ++it;
            }
            sleep(3);   // 定时三秒
        }
    }

    return nullptr;
}

void TCP_Server::EPOLL()
{
    
    //创建epoll实例
    epfd = epoll_create(1);
    if (epfd == -1)
    {
        perror("epoll_create");
        exit(0);//正常退出
    }

    //添加事件到epoll实例上
    struct epoll_event ev;
    ev.events = EPOLLIN;//监听读事件
    ev.data.fd = lfd;//监听的文件描述符
    int epc = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);//ev被拷贝
    if (epc == -1)
    {
        perror("epoll_ctl");
        exit(1);
    }
    //循环监测创建的epoll实例中有没有就绪的文件描述符
    struct epoll_event evs[1024];
    int size = sizeof(evs) / sizeof(evs[0]);
    while (1)
    {
        int num = epoll_wait(epfd, evs, size, -1);
        cout << "num:" << num << endl;

        //读出文件描述符
        for (int i = 0; i < num; ++i)
        {
            int fd = evs[i].data.fd;
            if (fd == lfd)//用于监听的文件描述符
            {
                int cfd = accept(fd, NULL, NULL);//第二个参数为客户端的信息
                ev.events = EPOLLIN;
                ev.data.fd = cfd;
                int epc = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
            }
            else //用于通信的文件描述符
            {
                //char buf[1024];
                PACKET_HEAD head;
                int len = recv(fd, &head, sizeof(head), 0);

                if (len == -1)
                {
                    perror("recv error");
                    exit(1);
                }
                else if (len == 0)
                {
                    cout << "客户端断开连接" << endl;
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                    break;
                }
                //服务端打印客户端信息
                //cout << "recv buf:" << buf << endl;
                Recv_Package(fd,head);//判断心跳or数据

                //回发给客户端
                int ret = send(fd, "helloworld", 11, 0);
                if (ret == -1)
                {
                    perror("send error");
                    exit(1);
                }
            }
        }
    }
}

void TCP_Server::task()
{
    this->Bind();
    this->Listen();
    this->EPOLL();
}


