/****************************************************************************
** Meta object code from reading C++ file 'usermain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../usermain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usermain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserMain_t {
    QByteArrayData data[21];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserMain_t qt_meta_stringdata_UserMain = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UserMain"
QT_MOC_LITERAL(1, 9, 10), // "UpdataInfo"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "doHeart"
QT_MOC_LITERAL(4, 29, 15), // "isDisConnection"
QT_MOC_LITERAL(5, 45, 12), // "reConnection"
QT_MOC_LITERAL(6, 58, 12), // "initDataTime"
QT_MOC_LITERAL(7, 71, 11), // "time_update"
QT_MOC_LITERAL(8, 83, 19), // "on_btn_data_clicked"
QT_MOC_LITERAL(9, 103, 18), // "on_btn_map_clicked"
QT_MOC_LITERAL(10, 122, 22), // "on_btn_history_clicked"
QT_MOC_LITERAL(11, 145, 22), // "on_btn_setting_clicked"
QT_MOC_LITERAL(12, 168, 19), // "on_btn_exit_clicked"
QT_MOC_LITERAL(13, 188, 22), // "on_btn_mangren_clicked"
QT_MOC_LITERAL(14, 211, 21), // "on_btn_weizhi_clicked"
QT_MOC_LITERAL(15, 233, 33), // "on_borderWidthSlider_valueCha..."
QT_MOC_LITERAL(16, 267, 5), // "value"
QT_MOC_LITERAL(17, 273, 29), // "on_processSlider_valueChanged"
QT_MOC_LITERAL(18, 303, 16), // "slotTimeout_Temp"
QT_MOC_LITERAL(19, 320, 9), // "RecvPoint"
QT_MOC_LITERAL(20, 330, 8) // "RecvData"

    },
    "UserMain\0UpdataInfo\0\0doHeart\0"
    "isDisConnection\0reConnection\0initDataTime\0"
    "time_update\0on_btn_data_clicked\0"
    "on_btn_map_clicked\0on_btn_history_clicked\0"
    "on_btn_setting_clicked\0on_btn_exit_clicked\0"
    "on_btn_mangren_clicked\0on_btn_weizhi_clicked\0"
    "on_borderWidthSlider_valueChanged\0"
    "value\0on_processSlider_valueChanged\0"
    "slotTimeout_Temp\0RecvPoint\0RecvData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserMain[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    1,  117,    2, 0x08 /* Private */,
      17,    1,  120,    2, 0x08 /* Private */,
      18,    0,  123,    2, 0x08 /* Private */,
      19,    0,  124,    2, 0x08 /* Private */,
      20,    0,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdataInfo(); break;
        case 1: _t->doHeart(); break;
        case 2: _t->isDisConnection(); break;
        case 3: _t->reConnection(); break;
        case 4: _t->initDataTime(); break;
        case 5: _t->time_update(); break;
        case 6: _t->on_btn_data_clicked(); break;
        case 7: _t->on_btn_map_clicked(); break;
        case 8: _t->on_btn_history_clicked(); break;
        case 9: _t->on_btn_setting_clicked(); break;
        case 10: _t->on_btn_exit_clicked(); break;
        case 11: _t->on_btn_mangren_clicked(); break;
        case 12: _t->on_btn_weizhi_clicked(); break;
        case 13: _t->on_borderWidthSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_processSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->slotTimeout_Temp(); break;
        case 16: _t->RecvPoint(); break;
        case 17: _t->RecvData(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserMain::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_UserMain.data,
    qt_meta_data_UserMain,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserMain.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
