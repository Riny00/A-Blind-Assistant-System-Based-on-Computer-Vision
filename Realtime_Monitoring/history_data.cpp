#pragma execution_character_set("utf-8")
#include"usermain.h"
#include <QWidget>
#include<QList>
#include "ui_usermain.h"
#include <QStandardItemModel>

void UserMain::initTableWidget()
{
    //ui->tableWidget->verticalHeader()->setHidden(true);       //隐藏行号列

    QStringList header;
    header<<"时间"<<"起点"<<"用户"<<"设备IP";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应表头宽度
    ui->tableWidget->setRowCount(30);
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    for(int i=0;i<4;i++)
    {
        if(i==0)
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem("                2023-03-21 15:04"));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem("                           育才路"));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem("                           李华"));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("                           47.115.230.59"));
        }
        if(i==1)
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem("                2023-04-5 13:04"));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem("                           开发大道"));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem("                           李华"));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("                           47.115.230.59"));
        }
        if(i==2)
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem("                2023-04-7 12:04"));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem("                           万达时代城"));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem("                           李华"));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("                           47.115.230.59"));
        }
        if(i==3)
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem("                2023-03-21 8:04"));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem("                           育才路"));
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem("                           李华"));
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("                           47.115.230.59"));
        }

    }

    //滚动条样式
    ui->tableWidget->verticalScrollBar()->setStyleSheet(
                "QScrollBar{background-color:rgb(218,222,223); width:10px;}"
                "QScrollBar::handle{background-color:#b1bffc; border:2px solid transparent; border-radius:5px;}"
                "QScrollBar::handle:hover{background-color:rgb(139, 139, 139);}"
                "QScrollBar::sub-line{background:transparent;}"
                "QScrollBar::add-line{background:transparent;}");

    //被选中
    connect(ui->tableWidget,&QTableWidget::itemClicked,this,[=](){
    int row=ui->tableWidget->currentRow();

    if(row==3)
    {
        qDebug()<<"row:"<<row<<endl;
    }



    });



}

