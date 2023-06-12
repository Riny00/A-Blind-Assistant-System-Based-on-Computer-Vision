#pragma execution_character_set("utf-8")
#include"usermain.h"
#include <QWidget>
#include "ui_usermain.h"


void UserMain::initChart()
{
    //定时器
    m_timer=new QTimer(this);
    m_timer->setSingleShot(false);
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(slotTimeout_Temp()));



    m_axisX = new QValueAxis();
    m_axisY = new QValueAxis();
    m_axisX->setTitleText("X-label");
    m_axisX->setTitleText("Y-label");
    m_axisX->setMin(0);
    m_axisX->setMax(0);
    m_axisX->setMax(AXIS_MAX_X);
    m_axisX->setMax(AXIS_MAX_Y);

    m_lineSeries = new QLineSeries();                             // 创建曲线绘制对象
    m_lineSeries->setPointsVisible(true);                         // 设置数据点可见
    m_lineSeries->setName("路程数曲线");                            // 图例名称

    m_chart = new QChart();                                        // 创建图表对象
    m_chart->addAxis(m_axisX, Qt::AlignLeft);                      // 将X轴添加到图表上
    m_chart->addAxis(m_axisY, Qt::AlignBottom);                    // 将Y轴添加到图表上
    m_chart->addSeries(m_lineSeries);                              // 将曲线对象添加到图表上
    m_chart->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    m_lineSeries->attachAxis(m_axisX);                             // 曲线对象关联上X轴，此步骤必须在m_chart->addSeries之后
    m_lineSeries->attachAxis(m_axisY);                             // 曲线对象关联上Y轴，此步骤必须在m_chart->addSeries之后

    ui->widget_8->setChart(m_chart);                           // 将图表对象设置到graphicsView上进行显示
    ui->widget_8->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑

    pointCount = 0;
    m_timer->start(800);
}

void UserMain::slotTimeout_Temp()
{
    if(pointCount > AXIS_MAX_X)
    {
        //m_lineSeries->remove(0);
        m_chart->axisX()->setMin(pointCount - AXIS_MAX_X);
        m_chart->axisX()->setMax(pointCount);                    // 更新X轴范围
    }
    bool ok = false;
    //int num1 = tmp.toInt(&ok, 10);
    m_lineSeries->append(QPointF(pointCount, rand() % AXIS_MAX_Y));  // 更新显示（随机生成10以内的一个数）
    //m_lineSeries->append(QPointF(pointCount, num1));  // 更新显示（随机生成10以内的一个数）
    pointCount++;
}


