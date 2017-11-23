/****************************************************************************
** Meta object code from reading C++ file 'carstatusSim.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../carstatusSim.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'carstatusSim.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CarStatusSim_t {
    QByteArrayData data[31];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarStatusSim_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarStatusSim_t qt_meta_stringdata_CarStatusSim = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CarStatusSim"
QT_MOC_LITERAL(1, 13, 11), // "tempChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "temperature"
QT_MOC_LITERAL(4, 38, 10), // "socChanged"
QT_MOC_LITERAL(5, 49, 3), // "soc"
QT_MOC_LITERAL(6, 53, 15), // "execModeChanged"
QT_MOC_LITERAL(7, 69, 13), // "ctrlIsEnabled"
QT_MOC_LITERAL(8, 83, 8), // "ctrlIsOn"
QT_MOC_LITERAL(9, 92, 7), // "warning"
QT_MOC_LITERAL(10, 100, 5), // "error"
QT_MOC_LITERAL(11, 106, 16), // "carStatusChanged"
QT_MOC_LITERAL(12, 123, 8), // "statusID"
QT_MOC_LITERAL(13, 132, 9), // "toggleCar"
QT_MOC_LITERAL(14, 142, 15), // "HVStatusChanged"
QT_MOC_LITERAL(15, 158, 16), // "CANStatusChanged"
QT_MOC_LITERAL(16, 175, 16), // "ERRStatusChanged"
QT_MOC_LITERAL(17, 192, 18), // "CTRLEnabledChanged"
QT_MOC_LITERAL(18, 211, 15), // "velocityChanged"
QT_MOC_LITERAL(19, 227, 13), // "presetChanged"
QT_MOC_LITERAL(20, 241, 10), // "toggleCtrl"
QT_MOC_LITERAL(21, 252, 15), // "toggleCarStatus"
QT_MOC_LITERAL(22, 268, 7), // "stopCar"
QT_MOC_LITERAL(23, 276, 12), // "changePreset"
QT_MOC_LITERAL(24, 289, 8), // "presetID"
QT_MOC_LITERAL(25, 298, 9), // "CANStatus"
QT_MOC_LITERAL(26, 308, 8), // "HVStatus"
QT_MOC_LITERAL(27, 317, 9), // "ERRStatus"
QT_MOC_LITERAL(28, 327, 11), // "CTRLEnabled"
QT_MOC_LITERAL(29, 339, 8), // "velocity"
QT_MOC_LITERAL(30, 348, 6) // "preset"

    },
    "CarStatusSim\0tempChanged\0\0temperature\0"
    "socChanged\0soc\0execModeChanged\0"
    "ctrlIsEnabled\0ctrlIsOn\0warning\0error\0"
    "carStatusChanged\0statusID\0toggleCar\0"
    "HVStatusChanged\0CANStatusChanged\0"
    "ERRStatusChanged\0CTRLEnabledChanged\0"
    "velocityChanged\0presetChanged\0toggleCtrl\0"
    "toggleCarStatus\0stopCar\0changePreset\0"
    "presetID\0CANStatus\0HVStatus\0ERRStatus\0"
    "CTRLEnabled\0velocity\0preset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarStatusSim[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       6,  120, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       6,    4,   95,    2, 0x06 /* Public */,
      11,    1,  104,    2, 0x06 /* Public */,
      13,    0,  107,    2, 0x06 /* Public */,
      14,    0,  108,    2, 0x06 /* Public */,
      15,    0,  109,    2, 0x06 /* Public */,
      16,    0,  110,    2, 0x06 /* Public */,
      17,    0,  111,    2, 0x06 /* Public */,
      18,    0,  112,    2, 0x06 /* Public */,
      19,    0,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,  114,    2, 0x0a /* Public */,
      21,    0,  115,    2, 0x0a /* Public */,
      22,    0,  116,    2, 0x0a /* Public */,
      23,    1,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   24,

 // properties: name, type, flags
      25, QMetaType::QString, 0x00495001,
      26, QMetaType::QString, 0x00495001,
      27, QMetaType::QString, 0x00495001,
      28, QMetaType::QString, 0x00495001,
      29, QMetaType::Int, 0x00495001,
      30, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       6,
       5,
       7,
       8,
       9,
      10,

       0        // eod
};

void CarStatusSim::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CarStatusSim *_t = static_cast<CarStatusSim *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tempChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->socChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->execModeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->carStatusChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->toggleCar(); break;
        case 5: _t->HVStatusChanged(); break;
        case 6: _t->CANStatusChanged(); break;
        case 7: _t->ERRStatusChanged(); break;
        case 8: _t->CTRLEnabledChanged(); break;
        case 9: _t->velocityChanged(); break;
        case 10: _t->presetChanged(); break;
        case 11: { int _r = _t->toggleCtrl();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { int _r = _t->toggleCarStatus();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 13: { int _r = _t->stopCar();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: _t->changePreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CarStatusSim::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::tempChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::socChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::execModeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::carStatusChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::toggleCar)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::HVStatusChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::CANStatusChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::ERRStatusChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::CTRLEnabledChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::velocityChanged)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::presetChanged)) {
                *result = 10;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        CarStatusSim *_t = static_cast<CarStatusSim *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->CANStatus(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->HVStatus(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->ERRStatus(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->CTRLEnabled(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->velocity(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->preset(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject CarStatusSim::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CarStatusSim.data,
      qt_meta_data_CarStatusSim,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CarStatusSim::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarStatusSim::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CarStatusSim.stringdata0))
        return static_cast<void*>(const_cast< CarStatusSim*>(this));
    return QObject::qt_metacast(_clname);
}

int CarStatusSim::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CarStatusSim::tempChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CarStatusSim::socChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CarStatusSim::execModeChanged(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CarStatusSim::carStatusChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CarStatusSim::toggleCar()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CarStatusSim::HVStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void CarStatusSim::CANStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void CarStatusSim::ERRStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void CarStatusSim::CTRLEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void CarStatusSim::velocityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void CarStatusSim::presetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
