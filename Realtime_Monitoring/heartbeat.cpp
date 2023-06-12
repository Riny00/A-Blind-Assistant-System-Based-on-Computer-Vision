#pragma execution_character_set("utf-8")
#include"usermain.h"
#include <QWidget>
#include<QList>
#include "ui_usermain.h"

void UserMain::doHeart()
{
    //创建心跳包json
    QJsonObject jsonObject;
    jsonObject.insert("Data", "Heartbeat");
    jsonObject.insert("type", "Desktop");


    QJsonDocument jsonDocument;
    jsonDocument.setObject(jsonObject);
    QByteArray dataArray = jsonDocument.toJson();

    qDebug()<<"data:"<<dataArray<<endl;
    m_tcp->write(dataArray);                        //发送
}

void UserMain::isDisConnection()
{
    count=0;
    //m_tcp->abort();
    qDebug()<<"*******Disconnect*******";
    timer_heart->stop();                //断开连接后心跳停止
    timer_reConn->setInterval(5000);    //每5秒钟自动重连 10次后停止
    connect(timer_reConn,SIGNAL(timeout()),this,SLOT(reConnection()));
    timer_reConn->start();
}
