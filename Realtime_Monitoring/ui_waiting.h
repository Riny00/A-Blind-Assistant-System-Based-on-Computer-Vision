/********************************************************************************
** Form generated from reading UI file 'waiting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITING_H
#define UI_WAITING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_waiting
{
public:
    QFrame *frame_background;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_17;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame_pic;
    QLabel *wait_pic;
    QLabel *label_word;
    QLabel *label_word_2;
    QProgressBar *progressBar;
    QLabel *label_word_3;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_10;

    void setupUi(QWidget *waiting)
    {
        if (waiting->objectName().isEmpty())
            waiting->setObjectName(QString::fromUtf8("waiting"));
        waiting->resize(1450, 890);
        frame_background = new QFrame(waiting);
        frame_background->setObjectName(QString::fromUtf8("frame_background"));
        frame_background->setGeometry(QRect(0, 0, 1600, 900));
        frame_background->setFrameShape(QFrame::StyledPanel);
        frame_background->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_background);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        label_title = new QLabel(frame_background);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_12->addWidget(label_title);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);

        horizontalLayout_12->setStretch(0, 5);
        horizontalLayout_12->setStretch(1, 5);
        horizontalLayout_12->setStretch(2, 5);

        gridLayout_3->addLayout(horizontalLayout_12, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_9 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_9);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_17);

        frame = new QFrame(frame_background);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        frame_pic = new QFrame(frame);
        frame_pic->setObjectName(QString::fromUtf8("frame_pic"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_pic->sizePolicy().hasHeightForWidth());
        frame_pic->setSizePolicy(sizePolicy);
        frame_pic->setMinimumSize(QSize(500, 600));
        frame_pic->setStyleSheet(QString::fromUtf8(""));
        frame_pic->setFrameShape(QFrame::StyledPanel);
        frame_pic->setFrameShadow(QFrame::Raised);
        wait_pic = new QLabel(frame_pic);
        wait_pic->setObjectName(QString::fromUtf8("wait_pic"));
        wait_pic->setGeometry(QRect(110, 90, 211, 231));
        label_word = new QLabel(frame_pic);
        label_word->setObjectName(QString::fromUtf8("label_word"));
        label_word->setGeometry(QRect(420, 170, 401, 131));
        label_word->setStyleSheet(QString::fromUtf8(""));
        label_word_2 = new QLabel(frame_pic);
        label_word_2->setObjectName(QString::fromUtf8("label_word_2"));
        label_word_2->setGeometry(QRect(390, 410, 311, 41));
        progressBar = new QProgressBar(frame_pic);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(190, 460, 541, 31));
        progressBar->setValue(25);
        progressBar->setTextVisible(false);
        label_word_3 = new QLabel(frame_pic);
        label_word_3->setObjectName(QString::fromUtf8("label_word_3"));
        label_word_3->setGeometry(QRect(430, 510, 111, 31));

        horizontalLayout_8->addWidget(frame_pic);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        horizontalLayout_9->addWidget(frame);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_18);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 4);
        horizontalLayout_9->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout_9);

        verticalSpacer_10 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_10);


        gridLayout_3->addLayout(verticalLayout_2, 1, 0, 1, 1);


        retranslateUi(waiting);

        QMetaObject::connectSlotsByName(waiting);
    } // setupUi

    void retranslateUi(QWidget *waiting)
    {
        waiting->setWindowTitle(QApplication::translate("waiting", "Form", nullptr));
        label_title->setText(QApplication::translate("waiting", "\345\256\236\346\227\266\350\267\257\347\272\277\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        wait_pic->setText(QString());
        label_word->setText(QApplication::translate("waiting", "Real Time Map", nullptr));
        label_word_2->setText(QApplication::translate("waiting", "\345\212\240\350\275\275\345\234\260\345\233\276\344\270\255......", nullptr));
        label_word_3->setText(QApplication::translate("waiting", "46%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class waiting: public Ui_waiting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITING_H
