#ifndef USERMAIN_H
#define USERMAIN_H

#include <QWidget>
#include<QTimer>
#include <QFile>
#include <QTextStream>
#include<QPushButton>
#include <QMessageBox>
#include <QWebChannel>
#include <QLineEdit>
#include<QScrollArea>
#include<QScrollBar>
#include<QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>
#include<QTableView>
#include <QTableWidgetItem>
#include <QVariant>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <iostream>
#include <set>
#include "bridge.h"
using namespace std;
namespace Ui {
class UserMain;
}

class UserMain : public QWidget
{
    Q_OBJECT

public:
    explicit UserMain(QWidget *parent = nullptr);    
    ~UserMain();

public:
    void init();                                        //界面初始化
    void NetInit();                                     //网络初始化
    void InfoGet();                                     //经纬度获取
    bool LoadStyleSheet(const QString &StyleSheetFile); //读取qss
    void initTableWidget();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void initChart();                                     //初始化图表

private slots:
    void UpdataInfo();
    void doHeart();             //发送心跳包槽函数
    void isDisConnection();     //断线处理
    void reConnection();        //断线重连

    void initDataTime();        //时间设置
    void time_update(void);     //时间更新

    void on_btn_data_clicked();

    void on_btn_map_clicked();

    void on_btn_history_clicked();

    void on_btn_setting_clicked();

    void on_btn_exit_clicked();

    void on_btn_mangren_clicked();

    void on_btn_weizhi_clicked();

    void on_borderWidthSlider_valueChanged(int value);

    void on_processSlider_valueChanged(int value);

    void slotTimeout_Temp();        //动态图表定时器槽函数

    void RecvPoint();
    void RecvData();//接收服务端发来的的数据

private:
    Ui::UserMain *ui;
    QString ip="47.115.230.59";//服务端ip
    unsigned short port=9999;//端口
    int count=0;        //心跳次数
    QTimer *timer_heart;//心跳定时器
    QTimer *timer_reConn;//重连定时器


    QTcpSocket*m_tcp;//与服务端通信信道
    QWebChannel *m_channel;
    Bridge *myBridge;


    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;


    /*动态折线图*/
    QTimer *m_timer;
    QChart* m_chart;/* 图表对象 */
    QValueAxis *m_axisX, *m_axisY;/* 横纵坐标轴对象 */
    QLineSeries* m_lineSeries;/* 曲线图对象 */
    const int AXIS_MAX_X = 70, AXIS_MAX_Y = 30;/* 横纵坐标最大显示范围 */
    int pointCount = 0;/* 用来记录数据点数 */


    QString longitude="";//获取经度

    QString latitude="";//获取纬度
    QString Help="";//获取求助

    set<QString>lgt_lat;

private:
    QTimer *RealPoint_timer;
    int cnt=1;
    int count1=1;
    int point_cnt=0;
    int finish=0;
public:
    void updatePoint();


};

#endif // USERMAIN_H
