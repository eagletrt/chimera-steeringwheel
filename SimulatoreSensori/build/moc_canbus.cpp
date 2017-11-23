/****************************************************************************
** Meta object code from reading C++ file 'canbus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Volante/canbus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canbus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Canbus_t {
    QByteArrayData data[13];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Canbus_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Canbus_t qt_meta_stringdata_Canbus = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Canbus"
QT_MOC_LITERAL(1, 7, 19), // "controlStateChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "ctrlState"
QT_MOC_LITERAL(4, 38, 4), // "warn"
QT_MOC_LITERAL(5, 43, 3), // "err"
QT_MOC_LITERAL(6, 47, 13), // "presetChanged"
QT_MOC_LITERAL(7, 61, 8), // "presetID"
QT_MOC_LITERAL(8, 70, 11), // "parseSerial"
QT_MOC_LITERAL(9, 82, 9), // "toggleCar"
QT_MOC_LITERAL(10, 92, 11), // "askHVUpdate"
QT_MOC_LITERAL(11, 104, 21), // "checkCANCommunication"
QT_MOC_LITERAL(12, 126, 17) // "checkSensorsError"

    },
    "Canbus\0controlStateChanged\0\0ctrlState\0"
    "warn\0err\0presetChanged\0presetID\0"
    "parseSerial\0toggleCar\0askHVUpdate\0"
    "checkCANCommunication\0checkSensorsError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canbus[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   49,    2, 0x06 /* Public */,
       6,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   59,    2, 0x0a /* Public */,
       9,    0,   60,    2, 0x0a /* Public */,
      10,    1,   61,    2, 0x0a /* Public */,
      11,    1,   64,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void Canbus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Canbus *_t = static_cast<Canbus *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->controlStateChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->presetChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->parseSerial(); break;
        case 3: _t->toggleCar(); break;
        case 4: _t->askHVUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->checkCANCommunication((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->checkSensorsError(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Canbus::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Canbus::controlStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Canbus::presetChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Canbus::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Canbus.data,
      qt_meta_data_Canbus,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Canbus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canbus::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Canbus.stringdata0))
        return static_cast<void*>(const_cast< Canbus*>(this));
    return QObject::qt_metacast(_clname);
}

int Canbus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Canbus::controlStateChanged(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Canbus::presetChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
