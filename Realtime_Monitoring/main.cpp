#include "widget.h"
#include <QApplication>
#include"usermain.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Widget w;
    w.show();
//    UserMain u;
//    u.show();

    QString str="getData({\"car1\"[";


//    QFile file("./release/Map/test.json");
//    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
//    {

//    }
//    // 文件流
//    QTextStream stream(&file);
//    // 输入内容
//    stream << str;

//    file.close();

    return app.exec();
}
