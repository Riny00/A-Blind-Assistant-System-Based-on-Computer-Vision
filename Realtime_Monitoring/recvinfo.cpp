#pragma execution_character_set("utf-8")
#include"usermain.h"
#include <QWidget>
#include<QList>
#include "ui_usermain.h"

void UserMain::NetInit()
{
    timer_heart=new QTimer(this);
    timer_reConn=new QTimer(this);
    timer_heart->setInterval(15000);                                //设置定时器间隔15秒

    m_tcp = new QTcpSocket(this);
    m_tcp->connectToHost(QHostAddress(ip),port);

    connect(timer_heart,SIGNAL(timeout()),this,SLOT(doHeart()));        //定时器超时发送心跳
    connect(m_tcp,SIGNAL(disconnected()),this,SLOT(isDisConnection())); //断线处理
//    // 检测是否和服务器是否连接成功了
//    connect(m_tcp, &QTcpSocket::connected, this, [=]()
//    {
//        timer_reConn->stop();
//        timer_heart->start();//开始心跳
//    });

     timer_heart->start();//开始心跳

    QString str="\" \"";

    connect(m_tcp, &QTcpSocket::readyRead, this, [=]()
    {
        QFile file("./release/Map/test.json");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            return;
        }
        // 接收服务器发送的数据
        QByteArray jsonData=m_tcp->readAll();
        QJsonDocument jsonDoc=QJsonDocument::fromJson(jsonData);
        QJsonObject jsonObj=jsonDoc.object();
        longitude=jsonObj["longitude"].toString();
        latitude=jsonObj["latitude"].toString();
        Help=jsonObj["Help"].toString();

        if(Help!="")
        {
           QString inf="************收到盲人求助信息************\n\n盲人当前位置:"+Help;
           const char* res=inf.toStdString().c_str();
           QMessageBox::warning(this,tr("警告信息"),tr(res));
        }

        //************去重部分*************
        QString point='['+longitude+','+latitude+']'+',';
        set<QString>::iterator iter;                // 迭代器
        iter = lgt_lat.find(point);               // 查找元素 point
        if(iter != lgt_lat.end()) {

        }
        else{
            if(point_cnt==0)
            {
                QString str="getData({\"car1\"["+point;

                // 文件流
                QTextStream stream(&file);
                // 输入内容
                stream << str;
                point_cnt=point_cnt+1;
            }
            else if(point_cnt==2&&finish==0)
            {
                QString str="]})";
                QTextStream stream(&file);
                // 输入内容
                stream << str;
                file.close();
                qDebug()<<"执行到这"<<endl;
                finish=1;
            }
            else if(point_cnt!=2&&finish!=1)
            {
                lgt_lat.insert(point);

                // 文件流
                QTextStream stream(&file);
                // 输入内容
                stream << point;
                point_cnt=point_cnt+1;
            }
        }
        //************去重部分*************

        qDebug()<<"longitude:"<<longitude<<endl;
        qDebug()<<"latitude:"<<latitude<<endl;
    });

        //发送 Json data
        QJsonObject jsonObject;
        jsonObject.insert("Data", "Position");
        jsonObject.insert("type", "Desktop");

        QJsonDocument jsonDocument;
        jsonDocument.setObject(jsonObject);
        QByteArray dataArray = jsonDocument.toJson();

        qDebug()<<"data:"<<dataArray<<endl;

        m_tcp->write(dataArray);

}


void UserMain::RecvData()
{
//    // 接收服务器发送的数据
//    QByteArray jsonData=m_tcp->readAll();
//    QJsonDocument jsonDoc=QJsonDocument::fromJson(jsonData);
//    QJsonObject jsonObj=jsonDoc.object();
//    longitude=jsonObj["longitude"].toString();
//    latitude=jsonObj["latitude"].toString();
//    qDebug()<<"longitude:"<<longitude<<endl;
//    qDebug()<<"latitude:"<<latitude<<endl;
}
