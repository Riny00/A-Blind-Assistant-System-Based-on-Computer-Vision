#include "waiting.h"
#include "ui_waiting.h"

#include <QFile>

waiting::waiting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::waiting)
{
    ui->setupUi(this);
    init();

}


void waiting::init()
{
    setWindowFlags(Qt::FramelessWindowHint);
    userUI=new UserMain;
    userUI->show();
    timer = new QTimer(this);                                         //进度条定时器
    this->LoadStyleSheet("./res/qss/waiting_style.qss");              //读取QSS文件
    setFixedSize(1450, 890);                                          //禁止调节窗口大小
    ui->wait_pic->setScaledContents(true);                            //图片自适应label大小
    ui->progressBar->setValue(0);                                     //初始化进度条
    ui->label_word_3->setText("0%");                                  //初始化数字
    timer->start(80);                                                //进度条定时器启动，每45毫秒发一次信号

    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutslots()));      //进度条定时器

}

bool waiting::LoadStyleSheet(const QString &StyleSheetFile)          //读取QSS文件
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

    return true;
}
void waiting::timeoutslots()
{
    QString res="";
    QString str ="";
    QString tmp="";
    int index = ui->progressBar->value();
    index+=1;
    str = QString::number(index, 10);

    if (index > 100)
    {
        timer->stop();
        //userUI->show();
        this->close();//销毁
    }
    if (index == 20)
    {
        tmp = QStringLiteral("初始化地图...");//没有乱码
        ui->label_word_2->setText(tmp);
    }
    if (index == 40)
    {
        tmp = QStringLiteral("与服务器建立连接...");
        ui->label_word_2->setText(tmp);
    }
    if (index== 60)
    {
        tmp = QStringLiteral("获取用户信息...");
        ui->label_word_2->setText(tmp);
    }
    if (index== 80)
    {
        tmp = QStringLiteral("界面初始化...");
        ui->label_word_2->setText(tmp);
    }
    res=str+"%";
    ui->progressBar->setValue(index);
    ui->label_word_3->setText(res);
    //先获取进度条的值，并增加
    //如果大于100，不用执行
    //未大于100，将增加后的值重新赋值。
}


waiting::~waiting()
{
    delete ui;
}
