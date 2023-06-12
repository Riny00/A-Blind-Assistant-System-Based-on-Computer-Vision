#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>
#include<QJsonObject>

class Bridge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QJsonObject jsonData MEMBER m_jsonData NOTIFY dataChanged)
public:
    explicit Bridge(QObject *parent = nullptr);

public slots:
    void btn_draw();//申明槽函数，供js调用

signals:
    void dataChanged(const QJsonObject &jsonData);// 必须加const

private:
    QJsonObject m_jsonData;
};

#endif // BRIDGE_H
