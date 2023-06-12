#pragma execution_character_set("utf-8")
#include "usermain.h"
#include "ui_usermain.h"

UserMain::UserMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserMain)
{
    ui->setupUi(this);
    init();                 //界面设置
    initDataTime();         //动态时间
    InfoGet();              //经纬度定时获取
    NetInit();              //网络设置
    initChart();            //图表初始化
    initTableWidget();      //历史路线tableWidget初始化
}

void UserMain::init()
{
    ui->waterProcess2->setUsedColor(QColor(79, 175, 243));  //设置水波背景颜色

    this->setWindowIcon(QIcon(":/res/pic/map.png"));                //设置窗口图标
    this->setWindowTitle(tr("Realtime_Monitoring"));                //设置窗口名称
    setWindowFlags(Qt::FramelessWindowHint);

    myBridge = new Bridge;                          //创建通道对象用于和JS交互

    m_channel= new QWebChannel(this);               //创建通道对象用于和JS交互


    ui->widget_4->page()->setWebChannel(m_channel);
    ui->widget_3->page()->setWebChannel(m_channel);
    ui->widget_2->page()->setWebChannel(m_channel);

    // 这里注册对象名"mybridge"需要与JS函数用到的名称一致
    m_channel->registerObject("mybridge", (QObject*)myBridge);

    QString htmlPath =      QApplication::applicationDirPath() + "/Map/DrawPath.html";      //路线绘制
    QString locationPath=   QApplication::applicationDirPath() + "/Map/Location.html";      //当前位置
    QString realPoint=      QApplication::applicationDirPath() + "/Map/realpoint.html";     //盲人位置
    QString test=      QApplication::applicationDirPath() + "/Map/index2.html";             //测试位置


    ui->widget_2->page()->load("file:///" + htmlPath);      //绘制路线界面
    ui->widget_3->page()->load("file:///" + locationPath);  //当前位置界面
    ui->widget_4->page()->load("file:///" + realPoint);     //盲人位置界面
    //ui->widget_4->page()->load("file:///" + test);          //测试界面

    //ui->widget_3->page()->load(QUrl("qrc:/res/Map/DrawPath.html"));
    //ui->widget_2->page()->load(QUrl("qrc:/res/Map/DrawPath.html"));

    setFixedSize(1450, 890);                                           //禁止调节窗口大小
    ui->label->setScaledContents(true);                                //图片自适应label大小
    this->LoadStyleSheet("./res/qss/user_style.qss");                   //读取QSS文件

    ui->stackedWidget->setCurrentWidget(ui->page_3);


}



void UserMain::InfoGet()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(UpdataInfo()));
    timer->start(3000); //3s执行一次,定时器
}




bool UserMain::LoadStyleSheet(const QString &StyleSheetFile)          //读取QSS文件
{
    QFile ofile(StyleSheetFile);
    bool Ret = ofile.open(QFile::ReadOnly);

    if (!Ret)
    {
         QMessageBox::information(this,"Tip",ofile.errorString());
         return false;
    }

    this->setStyleSheet(ofile.readAll());
    ofile.close();

    //滚动条样式
    ui->scrollArea->verticalScrollBar()->setStyleSheet(
                "QScrollBar{background-color:rgb(218,222,223); width:10px;}"
                "QScrollBar::handle{background-color:#b1bffc; border:2px solid transparent; border-radius:5px;}"
                "QScrollBar::handle:hover{background-color:#b1bffc;}"
                "QScrollBar::sub-line{background:transparent;}"
                "QScrollBar::add-line{background:transparent;}");

    return true;
}


UserMain::~UserMain()
{
    m_tcp->close();
    delete ui;
}



void UserMain::UpdataInfo()
{

    //获取当前时间
    QDateTime time = QDateTime::currentDateTime();
    QString hh=time.toString("hh");
    QString mm=time.toString("mm");
    QString ss=time.toString("ss");



    QLineEdit *lineEdit = new QLineEdit();
    lineEdit->setReadOnly(true);           //  不可编辑
    int i=ui->scrollArea->verticalScrollBar()->maximum();
    ui->scrollArea->verticalScrollBar()->setValue(i);

    //拼接字符串
    QString txt=hh+':'+mm+':'+ss+"     "+longitude+"    "+latitude;
    lineEdit->setText(txt);
    ui->scrollAreaWidgetContents->layout()->addWidget(lineEdit);


}


void UserMain::reConnection()
{
    count++;
    if(count<=10)
    {

        qDebug()<<"Disconnect and prepare for reconnection...(第"<<count<<"次)";
        m_tcp->connectToHost(ip,port);
    }
    else {
        timer_reConn->stop();//超过10次停止重连
    }
}

void UserMain::initDataTime()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(time_update()));
    timer->start(1000); //1s执行一次,定时器
}

void UserMain::time_update()
{
    QDateTime time = QDateTime::currentDateTime();
    //QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_5->setText(time.toString("hh"));
    ui->label_8->setText(time.toString("mm"));
    ui->label_11->setText(time.toString("ss"));
}



void UserMain::on_btn_exit_clicked()//退出程序
{
    if (!(QMessageBox::information(this,tr("系统警告"),tr("您确定要退出本系统吗 ?\n"),tr("确定"),tr("取消"))))
         {
               QApplication* app;
               app->exit(0);
         }

}


