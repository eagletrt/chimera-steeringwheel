/****************************************************************************
** Meta object code from reading C++ file 'canbus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../canbus.h"
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
    QByteArrayData data[16];
    char stringdata0[219];
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
QT_MOC_LITERAL(8, 70, 31), // "actuatorRangePendingFlagCleared"
QT_MOC_LITERAL(9, 102, 11), // "parseSerial"
QT_MOC_LITERAL(10, 114, 9), // "toggleCar"
QT_MOC_LITERAL(11, 124, 11), // "askHVUpdate"
QT_MOC_LITERAL(12, 136, 17), // "setActuatorsRange"
QT_MOC_LITERAL(13, 154, 21), // "checkCANCommunication"
QT_MOC_LITERAL(14, 176, 17), // "checkSensorsError"
QT_MOC_LITERAL(15, 194, 24) // "actuatorRangePendingFlag"

    },
    "Canbus\0controlStateChanged\0\0ctrlState\0"
    "warn\0err\0presetChanged\0presetID\0"
    "actuatorRangePendingFlagCleared\0"
    "parseSerial\0toggleCar\0askHVUpdate\0"
    "setActuatorsRange\0checkCANCommunication\0"
    "checkSensorsError\0actuatorRangePendingFlag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canbus[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       6,    1,   66,    2, 0x06 /* Public */,
       8,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   70,    2, 0x0a /* Public */,
      10,    0,   71,    2, 0x0a /* Public */,
      11,    1,   72,    2, 0x0a /* Public */,
      12,    2,   75,    2, 0x0a /* Public */,
      13,    1,   80,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       2,

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
        case 2: _t->actuatorRangePendingFlagCleared(); break;
        case 3: _t->parseSerial(); break;
        case 4: _t->toggleCar(); break;
        case 5: _t->askHVUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setActuatorsRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->checkCANCommunication((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->checkSensorsError(); break;
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
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Canbus::actuatorRangePendingFlagCleared)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Canbus *_t = static_cast<Canbus *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->actuatorRangePendingFlag(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
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

// SIGNAL 2
void Canbus::actuatorRangePendingFlagCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
