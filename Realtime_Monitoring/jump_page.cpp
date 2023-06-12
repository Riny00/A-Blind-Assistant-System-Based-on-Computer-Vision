#pragma execution_character_set("utf-8")
#include"usermain.h"
#include <QWidget>
#include "ui_usermain.h"


void UserMain::on_btn_data_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);

}

void UserMain::on_btn_map_clicked()//回主页
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
}

void UserMain::on_btn_history_clicked()//路线绘制
{
    QJsonObject json;
    json["x"] = "./data1.json";


    myBridge->setProperty("jsonData", json);


    QString Use=QString("main()");
    ui->widget_2->page()->runJavaScript(Use);
    qDebug()<<"调用"<<endl;
    ui->stackedWidget->setCurrentWidget(ui->page_3_1);

}
void UserMain::on_btn_setting_clicked()//系统设置界面
{
    ui->stackedWidget->setCurrentWidget(ui->page_set);
}

void UserMain::on_btn_weizhi_clicked()//当前位置
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);

}

