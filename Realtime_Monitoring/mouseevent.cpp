#pragma execution_character_set("utf-8")
#include"usermain.h"
#include <QWidget>
#include<QList>
#include "ui_usermain.h"
#include <QStandardItemModel>

void UserMain::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void UserMain::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}
