#-------------------------------------------------
#
# Project created by QtCreator 2023-03-02T09:44:39
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Realtime_Monitoring
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
QT += charts

SOURCES += \
        main.cpp \
        widget.cpp \
    waiting.cpp \
    usermain.cpp \
    jump_page.cpp \
    history_data.cpp \
    bridge.cpp \
    mouseevent.cpp \
    waterprocess.cpp \
    wave.cpp \
    chart.cpp \
    realpoint.cpp \
    recvinfo.cpp \
    heartbeat.cpp

HEADERS += \
        widget.h \
    waiting.h \
    usermain.h \
    bridge.h \
    waterprocess.h

FORMS += \
        widget.ui \
    waiting.ui \
    usermain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qss.qrc \
    pic.qrc \
    map.qrc

DISTFILES += \
    res/Map/DrawPath.html \
    res/Map/Location.html \
    res/Map/Location.html
