/****************************************************************************
** Meta object code from reading C++ file 'canbus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Volante/canbus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canbus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Canbus_t {
    QByteArrayData data[39];
    char stringdata0[494];
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
QT_MOC_LITERAL(8, 70, 11), // "pumpChanged"
QT_MOC_LITERAL(9, 82, 6), // "pumpID"
QT_MOC_LITERAL(10, 89, 31), // "actuatorRangePendingFlagCleared"
QT_MOC_LITERAL(11, 121, 13), // "hvTempChanged"
QT_MOC_LITERAL(12, 135, 13), // "lvTempChanged"
QT_MOC_LITERAL(13, 149, 13), // "hvVoltChanged"
QT_MOC_LITERAL(14, 163, 13), // "lvVoltChanged"
QT_MOC_LITERAL(15, 177, 16), // "invSxTempChanged"
QT_MOC_LITERAL(16, 194, 16), // "invDxTempChanged"
QT_MOC_LITERAL(17, 211, 15), // "brakeValChanged"
QT_MOC_LITERAL(18, 227, 18), // "throttleValChanged"
QT_MOC_LITERAL(19, 246, 11), // "parseSerial"
QT_MOC_LITERAL(20, 258, 9), // "toggleCar"
QT_MOC_LITERAL(21, 268, 11), // "askHVUpdate"
QT_MOC_LITERAL(22, 280, 17), // "setActuatorsRange"
QT_MOC_LITERAL(23, 298, 21), // "checkCANCommunication"
QT_MOC_LITERAL(24, 320, 17), // "checkSensorsError"
QT_MOC_LITERAL(25, 338, 14), // "steerConnected"
QT_MOC_LITERAL(26, 353, 9), // "askStatus"
QT_MOC_LITERAL(27, 363, 12), // "sendEncState"
QT_MOC_LITERAL(28, 376, 14), // "askSetupOrIdle"
QT_MOC_LITERAL(29, 391, 8), // "PWMCheck"
QT_MOC_LITERAL(30, 400, 24), // "actuatorRangePendingFlag"
QT_MOC_LITERAL(31, 425, 6), // "hvTemp"
QT_MOC_LITERAL(32, 432, 6), // "lvTemp"
QT_MOC_LITERAL(33, 439, 6), // "hvVolt"
QT_MOC_LITERAL(34, 446, 6), // "lvVolt"
QT_MOC_LITERAL(35, 453, 9), // "invSxTemp"
QT_MOC_LITERAL(36, 463, 9), // "invDxTemp"
QT_MOC_LITERAL(37, 473, 8), // "brakeVal"
QT_MOC_LITERAL(38, 482, 11) // "throttleVal"

    },
    "Canbus\0controlStateChanged\0\0ctrlState\0"
    "warn\0err\0presetChanged\0presetID\0"
    "pumpChanged\0pumpID\0actuatorRangePendingFlagCleared\0"
    "hvTempChanged\0lvTempChanged\0hvVoltChanged\0"
    "lvVoltChanged\0invSxTempChanged\0"
    "invDxTempChanged\0brakeValChanged\0"
    "throttleValChanged\0parseSerial\0toggleCar\0"
    "askHVUpdate\0setActuatorsRange\0"
    "checkCANCommunication\0checkSensorsError\0"
    "steerConnected\0askStatus\0sendEncState\0"
    "askSetupOrIdle\0PWMCheck\0"
    "actuatorRangePendingFlag\0hvTemp\0lvTemp\0"
    "hvVolt\0lvVolt\0invSxTemp\0invDxTemp\0"
    "brakeVal\0throttleVal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canbus[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       9,  172, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,  129,    2, 0x06 /* Public */,
       6,    1,  136,    2, 0x06 /* Public */,
       8,    1,  139,    2, 0x06 /* Public */,
      10,    0,  142,    2, 0x06 /* Public */,
      11,    0,  143,    2, 0x06 /* Public */,
      12,    0,  144,    2, 0x06 /* Public */,
      13,    0,  145,    2, 0x06 /* Public */,
      14,    0,  146,    2, 0x06 /* Public */,
      15,    0,  147,    2, 0x06 /* Public */,
      16,    0,  148,    2, 0x06 /* Public */,
      17,    0,  149,    2, 0x06 /* Public */,
      18,    0,  150,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,  151,    2, 0x0a /* Public */,
      20,    0,  152,    2, 0x0a /* Public */,
      21,    1,  153,    2, 0x0a /* Public */,
      22,    2,  156,    2, 0x0a /* Public */,
      23,    1,  161,    2, 0x0a /* Public */,
      24,    0,  164,    2, 0x0a /* Public */,
      25,    0,  165,    2, 0x0a /* Public */,
      26,    0,  166,    2, 0x0a /* Public */,
      27,    0,  167,    2, 0x0a /* Public */,
      28,    1,  168,    2, 0x0a /* Public */,
      29,    0,  171,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // properties: name, type, flags
      30, QMetaType::Int, 0x00495001,
      31, QMetaType::Int, 0x00495001,
      32, QMetaType::Int, 0x00495001,
      33, QMetaType::Int, 0x00495001,
      34, QMetaType::Int, 0x00495001,
      35, QMetaType::Int, 0x00495001,
      36, QMetaType::Int, 0x00495001,
      37, QMetaType::Int, 0x00495001,
      38, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       3,
       4,
       5,
       6,
       7,
       8,
       9,
      10,
      11,

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
        case 2: _t->pumpChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->actuatorRangePendingFlagCleared(); break;
        case 4: _t->hvTempChanged(); break;
        case 5: _t->lvTempChanged(); break;
        case 6: _t->hvVoltChanged(); break;
        case 7: _t->lvVoltChanged(); break;
        case 8: _t->invSxTempChanged(); break;
        case 9: _t->invDxTempChanged(); break;
        case 10: _t->brakeValChanged(); break;
        case 11: _t->throttleValChanged(); break;
        case 12: _t->parseSerial(); break;
        case 13: _t->toggleCar(); break;
        case 14: _t->askHVUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setActuatorsRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->checkCANCommunication((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->checkSensorsError(); break;
        case 18: _t->steerConnected(); break;
        case 19: _t->askStatus(); break;
        case 20: _t->sendEncState(); break;
        case 21: _t->askSetupOrIdle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->PWMCheck(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Canbus::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::controlStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::presetChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::pumpChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::actuatorRangePendingFlagCleared)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::hvTempChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::lvTempChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::hvVoltChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::lvVoltChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::invSxTempChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::invDxTempChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::brakeValChanged)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (Canbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::throttleValChanged)) {
                *result = 11;
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
        case 5: *reinterpret_cast< int*>(_v) = _t->invSxTemp(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->invDxTemp(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->brakeVal(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->throttleVal(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Canbus::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Canbus.data,
      qt_meta_data_Canbus,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Canbus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Canbus::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Canbus.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Canbus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Canbus::controlStateChanged(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Canbus::presetChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Canbus::pumpChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Canbus::actuatorRangePendingFlagCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Canbus::hvTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Canbus::lvTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Canbus::hvVoltChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Canbus::lvVoltChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Canbus::invSxTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Canbus::invDxTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void Canbus::brakeValChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Canbus::throttleValChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
