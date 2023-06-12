
#pragma execution_character_set("utf-8")
#include"usermain.h"
#include <QWidget>
#include "ui_usermain.h"

void UserMain::on_btn_mangren_clicked()//盲人实时位置
{
    updatePoint();

    ui->stackedWidget->setCurrentWidget(ui->page);


}

void UserMain::updatePoint()
{
    RealPoint_timer=new QTimer();
    connect(RealPoint_timer,SIGNAL(timeout()),this,SLOT(RecvPoint()));
    RealPoint_timer->start(2000);
}

void UserMain::RecvPoint()
{
    QString Use=QString("TotalTask()");
    QJsonObject json;
    json["x"]="["+longitude+","+latitude+"]";
    myBridge->setProperty("jsonData", json);
    ui->widget_4->page()->runJavaScript(Use);




}


