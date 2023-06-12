#include "TCP_Server.h"



TCP_Server::TCP_Server(int port, char*IP)
{
    //�����������׽���
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
    memset(&serv_addr, 0, sizeof(serv_addr)); //��ĳһ���ڴ��е�����ȫ������Ϊָ����ֵ
    this->serv_addr.sin_family = AF_INET;
    this->serv_addr.sin_port = htons(port);
    this->serv_addr.sin_addr.s_addr = inet_addr(IP);

    //�󶨶˿�
    int ret = bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret == -1)
    {
        perror("bind error");
        exit(1);//Ҫ����ֹ���򣬷������˳�
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
    //�������߳��жϿͻ����Ƿ�����
    pthread_t HEART_TEST;
    int ret = pthread_create(&HEART_TEST, NULL, heart_handler, (void*)this);

    PACKET_HEAD HEAD=head;

    if (HEAD.type == HEART)//����յ��������ݰ�
    {
        mmap[fd].second = 0;
        cout << "Received heart-beat" << endl;
    }
    else //��ͨ����
    {
        cout << "putongshuj" << endl;
    }

}

void* heart_handler(void* arg)
{
    cout << "The heartbeat checking thread started"<<endl;
    TCP_Server* s = (TCP_Server*)arg;

    //������ָ����λ
    map<int, pair<string, int> >::iterator it = s->mmap.begin();
    while (1)
    {
        for (; it != s->mmap.end();)//map<fd, pair<ip, count>>
        {
            if (it->second.second == 5)//�����3s*5 δ�յ���������ͻ��˵���
            {
                cout << "The client " << it->second.first << " has be offline.\n";
                int fd = it->first;
                epoll_ctl(s->epfd, EPOLL_CTL_DEL, fd, NULL);
                close(fd);

                s->mmap.erase(it++);  // ��map���Ƴ��ü�¼
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
            sleep(3);   // ��ʱ����
        }
    }

    return nullptr;
}

void TCP_Server::EPOLL()
{
    
    //����epollʵ��
    epfd = epoll_create(1);
    if (epfd == -1)
    {
        perror("epoll_create");
        exit(0);//�����˳�
    }

    //����¼���epollʵ����
    struct epoll_event ev;
    ev.events = EPOLLIN;//�������¼�
    ev.data.fd = lfd;//�������ļ�������
    int epc = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);//ev������
    if (epc == -1)
    {
        perror("epoll_ctl");
        exit(1);
    }
    //ѭ����ⴴ����epollʵ������û�о������ļ�������
    struct epoll_event evs[1024];
    int size = sizeof(evs) / sizeof(evs[0]);
    while (1)
    {
        int num = epoll_wait(epfd, evs, size, -1);
        cout << "num:" << num << endl;

        //�����ļ�������
        for (int i = 0; i < num; ++i)
        {
            int fd = evs[i].data.fd;
            if (fd == lfd)//���ڼ������ļ�������
            {
                int cfd = accept(fd, NULL, NULL);//�ڶ�������Ϊ�ͻ��˵���Ϣ
                ev.events = EPOLLIN;
                ev.data.fd = cfd;
                int epc = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
            }
            else //����ͨ�ŵ��ļ�������
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
                    cout << "�ͻ��˶Ͽ�����" << endl;
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                    break;
                }
                //����˴�ӡ�ͻ�����Ϣ
                //cout << "recv buf:" << buf << endl;
                Recv_Package(fd,head);//�ж�����or����

                //�ط����ͻ���
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


