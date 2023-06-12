/********************************************************************************
** Form generated from reading UI file 'usermain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMAIN_H
#define UI_USERMAIN_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"
#include "waterprocess.h"

QT_BEGIN_NAMESPACE

class Ui_UserMain
{
public:
    QWidget *menu_top;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_map;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_data;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_setting;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_12;
    QWidget *menu_bottom;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_15;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QWebEngineView *widget_3;
    QWidget *page;
    QWebEngineView *widget_4;
    QWidget *page_3_1;
    QWebEngineView *widget_2;
    QWidget *page_4;
    QTableWidget *tableWidget;
    QWidget *page_set;
    QWidget *widget_5;
    QLabel *label_23;
    WaterProcess *waterProcess2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_27;
    QLabel *label_21;
    QWidget *widget_7;
    QLabel *label_26;
    QChartView *widget_8;
    QWidget *widget_6;
    QLabel *label_24;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *label_19;
    QLineEdit *lineEdit;
    QLabel *label_22;
    QLineEdit *lineEdit_2;
    QLabel *label_17;
    QLineEdit *lineEdit_3;
    QLabel *label_25;
    QLineEdit *lineEdit_4;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_19;
    QWidget *widget_9;
    QPushButton *btn_history;
    QPushButton *btn_exit;
    QPushButton *btn_mangren;
    QPushButton *btn_weizhi;

    void setupUi(QWidget *UserMain)
    {
        if (UserMain->objectName().isEmpty())
            UserMain->setObjectName(QString::fromUtf8("UserMain"));
        UserMain->resize(1454, 897);
        menu_top = new QWidget(UserMain);
        menu_top->setObjectName(QString::fromUtf8("menu_top"));
        menu_top->setGeometry(QRect(-11, -10, 1471, 111));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menu_top->sizePolicy().hasHeightForWidth());
        menu_top->setSizePolicy(sizePolicy);
        menu_top->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(menu_top);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label = new QLabel(menu_top);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(90, 90));
        label->setMargin(5);

        horizontalLayout->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(25, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 10, -1, -1);
        label_2 = new QLabel(menu_top);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(menu_top);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        horizontalLayout_5->addLayout(horizontalLayout);

        horizontalSpacer_9 = new QSpacerItem(238, 48, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_map = new QPushButton(menu_top);
        btn_map->setObjectName(QString::fromUtf8("btn_map"));
        btn_map->setMinimumSize(QSize(90, 85));

        horizontalLayout_2->addWidget(btn_map);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_data = new QPushButton(menu_top);
        btn_data->setObjectName(QString::fromUtf8("btn_data"));
        btn_data->setMinimumSize(QSize(100, 85));

        horizontalLayout_2->addWidget(btn_data);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_setting = new QPushButton(menu_top);
        btn_setting->setObjectName(QString::fromUtf8("btn_setting"));
        btn_setting->setMinimumSize(QSize(100, 85));

        horizontalLayout_2->addWidget(btn_setting);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_13);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 15, -1, -1);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        label_5 = new QLabel(menu_top);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        label_6 = new QLabel(menu_top);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        label_8 = new QLabel(menu_top);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        label_9 = new QLabel(menu_top);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        label_11 = new QLabel(menu_top);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_4->addWidget(label_11);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 3);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 3);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 3);
        horizontalLayout_4->setStretch(6, 1);

        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        label_12 = new QLabel(menu_top);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);

        label_13 = new QLabel(menu_top);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13);

        label_14 = new QLabel(menu_top);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_3->addWidget(label_14);

        label_15 = new QLabel(menu_top);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_3->addWidget(label_15);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        menu_bottom = new QWidget(UserMain);
        menu_bottom->setObjectName(QString::fromUtf8("menu_bottom"));
        menu_bottom->setGeometry(QRect(0, 849, 1450, 41));
        horizontalLayout_6 = new QHBoxLayout(menu_bottom);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_14 = new QSpacerItem(614, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_14);

        label_16 = new QLabel(menu_bottom);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_6->addWidget(label_16);

        horizontalSpacer_15 = new QSpacerItem(614, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_15);

        layoutWidget = new QWidget(UserMain);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 80, 1451, 771));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(layoutWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        widget_3 = new QWebEngineView(page_3);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 30, 1111, 731));
        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widget_4 = new QWebEngineView(page);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(10, 30, 1111, 731));
        stackedWidget->addWidget(page);
        page_3_1 = new QWidget();
        page_3_1->setObjectName(QString::fromUtf8("page_3_1"));
        widget_2 = new QWebEngineView(page_3_1);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 30, 1121, 731));
        stackedWidget->addWidget(page_3_1);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        tableWidget = new QTableWidget(page_4);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 1101, 741));
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(4);
        stackedWidget->addWidget(page_4);
        page_set = new QWidget();
        page_set->setObjectName(QString::fromUtf8("page_set"));
        widget_5 = new QWidget(page_set);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(20, 40, 531, 391));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:20px;\n"
""));
        label_23 = new QLabel(widget_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(180, 10, 161, 31));
        label_23->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));
        waterProcess2 = new WaterProcess(widget_5);
        waterProcess2->setObjectName(QString::fromUtf8("waterProcess2"));
        waterProcess2->setGeometry(QRect(80, 60, 371, 231));
        layoutWidget1 = new QWidget(widget_5);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 321, 351, 41));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        horizontalLayout_12->addWidget(label_18);

        horizontalSpacer_27 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_27);

        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        horizontalLayout_12->addWidget(label_21);

        horizontalLayout_12->setStretch(0, 20);
        horizontalLayout_12->setStretch(1, 10);
        horizontalLayout_12->setStretch(2, 20);
        widget_7 = new QWidget(page_set);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(20, 440, 1081, 311));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:20px;"));
        label_26 = new QLabel(widget_7);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(480, 10, 161, 31));
        label_26->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));
        widget_8 = new QChartView(widget_7);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(20, 40, 1041, 261));
        widget_6 = new QWidget(page_set);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(570, 40, 531, 391));
        widget_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:20px;"));
        label_24 = new QLabel(widget_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(180, 10, 161, 31));
        label_24->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));
        pushButton = new QPushButton(widget_6);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 340, 93, 28));
        pushButton->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";\n"
"border-radius:35px;\n"
""));
        pushButton_2 = new QPushButton(widget_6);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 340, 93, 28));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";\n"
"border-radius:35px;\n"
"background-color: rgb(255, 0, 0);"));
        layoutWidget2 = new QWidget(widget_6);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 60, 451, 261));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_19, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_22 = new QLabel(layoutWidget2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_22, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_17, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_25 = new QLabel(layoutWidget2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(label_25, 3, 0, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setStyleSheet(QString::fromUtf8("font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

        stackedWidget->addWidget(page_set);

        horizontalLayout_7->addWidget(stackedWidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget = new QWidget(layoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 80, 331, 461));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 329, 459));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget3 = new QWidget(widget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 20, 331, 61));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_16 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_16);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_8->addWidget(label_4);

        horizontalSpacer_17 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_17);

        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        horizontalSpacer_18 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_8->addWidget(label_10);

        horizontalSpacer_19 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_19);

        horizontalLayout_8->setStretch(0, 5);
        horizontalLayout_8->setStretch(1, 20);
        horizontalLayout_8->setStretch(2, 3);
        horizontalLayout_8->setStretch(3, 20);
        horizontalLayout_8->setStretch(4, 3);
        horizontalLayout_8->setStretch(5, 20);
        horizontalLayout_8->setStretch(6, 1);
        widget_9 = new QWidget(widget);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setGeometry(QRect(10, 490, 311, 261));
        widget_9->setStyleSheet(QString::fromUtf8("\n"
"border-radius:20px;"));
        btn_history = new QPushButton(widget_9);
        btn_history->setObjectName(QString::fromUtf8("btn_history"));
        btn_history->setGeometry(QRect(20, 190, 121, 41));
        btn_history->setStyleSheet(QString::fromUtf8("border-radius:20px;"));
        btn_exit = new QPushButton(widget_9);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(170, 190, 121, 41));
        btn_exit->setStyleSheet(QString::fromUtf8("border-radius:20px;"));
        btn_mangren = new QPushButton(widget_9);
        btn_mangren->setObjectName(QString::fromUtf8("btn_mangren"));
        btn_mangren->setGeometry(QRect(170, 100, 121, 41));
        btn_mangren->setStyleSheet(QString::fromUtf8("border-radius:20px;"));
        btn_weizhi = new QPushButton(widget_9);
        btn_weizhi->setObjectName(QString::fromUtf8("btn_weizhi"));
        btn_weizhi->setGeometry(QRect(20, 100, 121, 41));
        btn_weizhi->setStyleSheet(QString::fromUtf8("border-radius:20px;"));
        widget_9->raise();
        scrollArea->raise();
        layoutWidget->raise();

        verticalLayout_4->addWidget(widget);


        horizontalLayout_7->addLayout(verticalLayout_4);

        horizontalLayout_7->setStretch(0, 10);
        horizontalLayout_7->setStretch(1, 3);

        retranslateUi(UserMain);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(UserMain);
    } // setupUi

    void retranslateUi(QWidget *UserMain)
    {
        UserMain->setWindowTitle(QApplication::translate("UserMain", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("UserMain", "\345\256\236\346\227\266\350\267\257\347\272\277\347\233\221\346\265\213\345\271\263\345\217\260", nullptr));
        label_3->setText(QApplication::translate("UserMain", "Real-time route monitoring platform", nullptr));
        btn_map->setText(QApplication::translate("UserMain", "\347\224\265\345\255\220\345\234\260\345\233\276", nullptr));
        btn_data->setText(QApplication::translate("UserMain", "\346\225\260\346\215\256\346\237\245\350\257\242", nullptr));
        btn_setting->setText(QApplication::translate("UserMain", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        label_5->setText(QApplication::translate("UserMain", "15", nullptr));
        label_6->setText(QApplication::translate("UserMain", ":", nullptr));
        label_8->setText(QApplication::translate("UserMain", "32", nullptr));
        label_9->setText(QApplication::translate("UserMain", ":", nullptr));
        label_11->setText(QApplication::translate("UserMain", "25", nullptr));
        label_12->setText(QApplication::translate("UserMain", "Cpu", nullptr));
        label_13->setText(QApplication::translate("UserMain", "1%", nullptr));
        label_14->setText(QApplication::translate("UserMain", "Mem", nullptr));
        label_15->setText(QApplication::translate("UserMain", "29%", nullptr));
        label_16->setText(QApplication::translate("UserMain", "\346\254\242\350\277\216\344\275\277\347\224\250\345\256\236\346\227\266\350\267\257\347\272\277\347\233\221\346\265\213\345\271\263\345\217\260", nullptr));
        label_23->setText(QApplication::translate("UserMain", "\350\256\276\345\244\207\347\224\265\351\207\217\346\230\276\347\244\272", nullptr));
        label_18->setText(QApplication::translate("UserMain", "\350\256\276\345\244\207\345\220\215\347\247\260\357\274\232", nullptr));
        label_21->setText(QApplication::translate("UserMain", "Jetson nano", nullptr));
        label_26->setText(QApplication::translate("UserMain", "\345\207\272\350\241\214\351\207\214\347\250\213\350\256\260\345\275\225", nullptr));
        label_24->setText(QApplication::translate("UserMain", "\347\275\221\347\273\234\350\277\236\346\216\245\350\256\276\347\275\256", nullptr));
        pushButton->setText(QApplication::translate("UserMain", "\346\217\220\344\272\244", nullptr));
        pushButton_2->setText(QApplication::translate("UserMain", "\346\226\255\345\274\200", nullptr));
        label_19->setText(QApplication::translate("UserMain", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        lineEdit->setText(QApplication::translate("UserMain", "192.168.13.156", nullptr));
        label_22->setText(QApplication::translate("UserMain", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        lineEdit_2->setText(QApplication::translate("UserMain", "1000", nullptr));
        label_17->setText(QApplication::translate("UserMain", "\345\207\272\350\241\214\346\226\271\345\274\217\357\274\232", nullptr));
        lineEdit_3->setText(QApplication::translate("UserMain", "\346\255\245\350\241\214", nullptr));
        label_25->setText(QApplication::translate("UserMain", "\351\207\207\351\233\206\351\227\264\351\232\224\357\274\232", nullptr));
        lineEdit_4->setText(QApplication::translate("UserMain", "2S", nullptr));
        label_4->setText(QApplication::translate("UserMain", "\346\227\266\351\227\264", nullptr));
        label_7->setText(QApplication::translate("UserMain", "\347\273\217\345\272\246", nullptr));
        label_10->setText(QApplication::translate("UserMain", "\347\272\254\345\272\246", nullptr));
        btn_history->setText(QApplication::translate("UserMain", "\345\274\200\345\247\213\347\273\230\345\210\266", nullptr));
        btn_exit->setText(QApplication::translate("UserMain", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        btn_mangren->setText(QApplication::translate("UserMain", "\347\233\262\344\272\272\344\275\215\347\275\256", nullptr));
        btn_weizhi->setText(QApplication::translate("UserMain", "\345\275\223\345\211\215\344\275\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserMain: public Ui_UserMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMAIN_H
