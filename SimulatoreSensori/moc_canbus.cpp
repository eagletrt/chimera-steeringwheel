/****************************************************************************
** Meta object code from reading C++ file 'canbus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Volante/canbus.h"
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
    QByteArrayData data[24];
    char stringdata0[303];
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
QT_MOC_LITERAL(9, 102, 13), // "hvTempChanged"
QT_MOC_LITERAL(10, 116, 13), // "lvTempChanged"
QT_MOC_LITERAL(11, 130, 13), // "hvVoltChanged"
QT_MOC_LITERAL(12, 144, 13), // "lvVoltChanged"
QT_MOC_LITERAL(13, 158, 11), // "parseSerial"
QT_MOC_LITERAL(14, 170, 9), // "toggleCar"
QT_MOC_LITERAL(15, 180, 11), // "askHVUpdate"
QT_MOC_LITERAL(16, 192, 17), // "setActuatorsRange"
QT_MOC_LITERAL(17, 210, 21), // "checkCANCommunication"
QT_MOC_LITERAL(18, 232, 17), // "checkSensorsError"
QT_MOC_LITERAL(19, 250, 24), // "actuatorRangePendingFlag"
QT_MOC_LITERAL(20, 275, 6), // "hvTemp"
QT_MOC_LITERAL(21, 282, 6), // "lvTemp"
QT_MOC_LITERAL(22, 289, 6), // "hvVolt"
QT_MOC_LITERAL(23, 296, 6) // "lvVolt"

    },
    "Canbus\0controlStateChanged\0\0ctrlState\0"
    "warn\0err\0presetChanged\0presetID\0"
    "actuatorRangePendingFlagCleared\0"
    "hvTempChanged\0lvTempChanged\0hvVoltChanged\0"
    "lvVoltChanged\0parseSerial\0toggleCar\0"
    "askHVUpdate\0setActuatorsRange\0"
    "checkCANCommunication\0checkSensorsError\0"
    "actuatorRangePendingFlag\0hvTemp\0lvTemp\0"
    "hvVolt\0lvVolt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canbus[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       5,  108, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,
       6,    1,   86,    2, 0x06 /* Public */,
       8,    0,   89,    2, 0x06 /* Public */,
       9,    0,   90,    2, 0x06 /* Public */,
      10,    0,   91,    2, 0x06 /* Public */,
      11,    0,   92,    2, 0x06 /* Public */,
      12,    0,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   94,    2, 0x0a /* Public */,
      14,    0,   95,    2, 0x0a /* Public */,
      15,    1,   96,    2, 0x0a /* Public */,
      16,    2,   99,    2, 0x0a /* Public */,
      17,    1,  104,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // properties: name, type, flags
      19, QMetaType::Int, 0x00495001,
      20, QMetaType::Int, 0x00495001,
      21, QMetaType::Int, 0x00495001,
      22, QMetaType::Int, 0x00495001,
      23, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       2,
       3,
       4,
       5,
       6,

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
        case 3: _t->hvTempChanged(); break;
        case 4: _t->lvTempChanged(); break;
        case 5: _t->hvVoltChanged(); break;
        case 6: _t->lvVoltChanged(); break;
        case 7: _t->parseSerial(); break;
        case 8: _t->toggleCar(); break;
        case 9: _t->askHVUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setActuatorsRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->checkCANCommunication((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->checkSensorsError(); break;
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
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Canbus::hvTempChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Canbus::lvTempChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Canbus::hvVoltChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Canbus::lvVoltChanged)) {
                *result = 6;
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
        case 1: *reinterpret_cast< int*>(_v) = _t->hvTemp(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->lvTemp(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->hvVolt(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->lvVolt(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
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

// SIGNAL 3
void Canbus::hvTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Canbus::lvTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Canbus::hvVoltChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Canbus::lvVoltChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
