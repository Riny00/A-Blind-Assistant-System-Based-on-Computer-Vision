#ifndef WAITING_H
#define WAITING_H

#include <QWidget>
#include<QPushButton>
#include <QMessageBox>
#include <QTimer>
#include"usermain.h"

namespace Ui {
class waiting;
}

class waiting : public QWidget
{
    Q_OBJECT

public:
    explicit waiting(QWidget *parent = nullptr);
    bool LoadStyleSheet(const QString &StyleSheetFile);//读取qss
    void init();
    ~waiting();



private:
    Ui::waiting *ui;
    QTimer *timer;//进度条定时器
    UserMain *userUI;

Q_SIGNALS:
    void timeout(QPrivateSignal);//计时信号
private slots:
    void timeoutslots();//进度条槽函数

};

#endif // WAITING_H
