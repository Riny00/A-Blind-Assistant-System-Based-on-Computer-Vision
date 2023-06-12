#include "widget.h"
#include "ui_widget.h"
#include<QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();

}

void Widget::init()
{
    //ui->waterProcess2->setUsedColor(QColor(79, 175, 243));
    setWindowFlags(Qt::FramelessWindowHint);


    this->setWindowIcon(QIcon(":/res/pic/map.png"));                //设置窗口图标
    this->setWindowTitle(tr("Realtime_Monitoring"));                //设置窗口名称
    ui->label_user_name->setScaledContents(true);                   //图片自适应label大小
    ui->label_pwd->setScaledContents(true);                         //图片自适应label大小
    ui->lineE_pwd->setEchoMode(QLineEdit::Password);                //设置为小黑点
    setFixedSize(1450, 890);                                        //禁止调节窗口大小
    this->LoadStyleSheet("./res/qss/login_style.qss");              //读取QSS文件



}

bool Widget::LoadStyleSheet(const QString &StyleSheetFile)          //读取QSS文件
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

void Widget::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}



Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_login_clicked()
{
//    WaitingUi=new waiting;                                          //等待界面
//    WaitingUi->show();
    userUI=new UserMain;
    userUI->show();
    this->close();//销毁
}
