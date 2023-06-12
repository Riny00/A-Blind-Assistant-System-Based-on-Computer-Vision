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
    QByteArrayData data[10];
    char stringdata0[122];
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
QT_MOC_LITERAL(9, 103, 18) // "on_btn_map_clicked"

    },
    "UserMain\0UpdataInfo\0\0doHeart\0"
    "isDisConnection\0reConnection\0initDataTime\0"
    "time_update\0on_btn_data_clicked\0"
    "on_btn_map_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserMain[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        default: ;
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
