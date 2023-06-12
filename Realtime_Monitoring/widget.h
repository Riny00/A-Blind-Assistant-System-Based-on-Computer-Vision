#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include<QPushButton>
#include <QMessageBox>
#include"waiting.h"
#include"usermain.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void init();                                            //登录界面初始化
    bool LoadStyleSheet(const QString &StyleSheetFile);     //读取qss文件

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

    ~Widget();


private slots:
    void on_btn_login_clicked();

private:
    Ui::Widget *ui;

    waiting *WaitingUi;//等待界面
    UserMain *userUI;


};

#endif // WIDGET_H
