/****************************************************************************
** Meta object code from reading C++ file 'canbus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/canbus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canbus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Canbus_t {
    QByteArrayData data[24];
    char stringdata0[311];
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
QT_MOC_LITERAL(11, 121, 11), // "parseSerial"
QT_MOC_LITERAL(12, 133, 10), // "sendMarker"
QT_MOC_LITERAL(13, 144, 9), // "toggleCar"
QT_MOC_LITERAL(14, 154, 11), // "askHVUpdate"
QT_MOC_LITERAL(15, 166, 17), // "setActuatorsRange"
QT_MOC_LITERAL(16, 184, 21), // "checkCANCommunication"
QT_MOC_LITERAL(17, 206, 17), // "checkSensorsError"
QT_MOC_LITERAL(18, 224, 14), // "steerConnected"
QT_MOC_LITERAL(19, 239, 9), // "askStatus"
QT_MOC_LITERAL(20, 249, 12), // "sendEncState"
QT_MOC_LITERAL(21, 262, 14), // "askSetupOrIdle"
QT_MOC_LITERAL(22, 277, 8), // "PWMCheck"
QT_MOC_LITERAL(23, 286, 24) // "actuatorRangePendingFlag"

    },
    "Canbus\0controlStateChanged\0\0ctrlState\0"
    "warn\0err\0presetChanged\0presetID\0"
    "pumpChanged\0pumpID\0actuatorRangePendingFlagCleared\0"
    "parseSerial\0sendMarker\0toggleCar\0"
    "askHVUpdate\0setActuatorsRange\0"
    "checkCANCommunication\0checkSensorsError\0"
    "steerConnected\0askStatus\0sendEncState\0"
    "askSetupOrIdle\0PWMCheck\0"
    "actuatorRangePendingFlag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Canbus[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       1,  130, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   94,    2, 0x06 /* Public */,
       6,    1,  101,    2, 0x06 /* Public */,
       8,    1,  104,    2, 0x06 /* Public */,
      10,    0,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  108,    2, 0x0a /* Public */,
      12,    0,  109,    2, 0x0a /* Public */,
      13,    0,  110,    2, 0x0a /* Public */,
      14,    1,  111,    2, 0x0a /* Public */,
      15,    2,  114,    2, 0x0a /* Public */,
      16,    1,  119,    2, 0x0a /* Public */,
      17,    0,  122,    2, 0x0a /* Public */,
      18,    0,  123,    2, 0x0a /* Public */,
      19,    0,  124,    2, 0x0a /* Public */,
      20,    0,  125,    2, 0x0a /* Public */,
      21,    1,  126,    2, 0x0a /* Public */,
      22,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
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
      23, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       3,

       0        // eod
};

void Canbus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Canbus *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->controlStateChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->presetChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->pumpChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->actuatorRangePendingFlagCleared(); break;
        case 4: _t->parseSerial(); break;
        case 5: _t->sendMarker(); break;
        case 6: _t->toggleCar(); break;
        case 7: _t->askHVUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setActuatorsRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->checkCANCommunication((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->checkSensorsError(); break;
        case 11: _t->steerConnected(); break;
        case 12: _t->askStatus(); break;
        case 13: _t->sendEncState(); break;
        case 14: _t->askSetupOrIdle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->PWMCheck(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Canbus::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::controlStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Canbus::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::presetChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Canbus::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::pumpChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Canbus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Canbus::actuatorRangePendingFlagCleared)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Canbus *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject Canbus::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Canbus.data,
    qt_meta_data_Canbus,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
