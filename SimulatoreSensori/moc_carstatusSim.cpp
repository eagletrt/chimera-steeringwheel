/****************************************************************************
** Meta object code from reading C++ file 'carstatusSim.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "carstatusSim.h"
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
    QByteArrayData data[24];
    char stringdata0[264];
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
QT_MOC_LITERAL(14, 142, 18), // "CTRLEnabledChanged"
QT_MOC_LITERAL(15, 161, 15), // "velocityChanged"
QT_MOC_LITERAL(16, 177, 13), // "presetChanged"
QT_MOC_LITERAL(17, 191, 10), // "toggleCtrl"
QT_MOC_LITERAL(18, 202, 15), // "toggleCarStatus"
QT_MOC_LITERAL(19, 218, 7), // "stopCar"
QT_MOC_LITERAL(20, 226, 12), // "changePreset"
QT_MOC_LITERAL(21, 239, 8), // "presetID"
QT_MOC_LITERAL(22, 248, 8), // "velocity"
QT_MOC_LITERAL(23, 257, 6) // "preset"

    },
    "CarStatusSim\0tempChanged\0\0temperature\0"
    "socChanged\0soc\0execModeChanged\0"
    "ctrlIsEnabled\0ctrlIsOn\0warning\0error\0"
    "carStatusChanged\0statusID\0toggleCar\0"
    "CTRLEnabledChanged\0velocityChanged\0"
    "presetChanged\0toggleCtrl\0toggleCarStatus\0"
    "stopCar\0changePreset\0presetID\0velocity\0"
    "preset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarStatusSim[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       2,  102, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    4,   80,    2, 0x06 /* Public */,
      11,    1,   89,    2, 0x06 /* Public */,
      13,    0,   92,    2, 0x06 /* Public */,
      14,    0,   93,    2, 0x06 /* Public */,
      15,    0,   94,    2, 0x06 /* Public */,
      16,    0,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,   96,    2, 0x0a /* Public */,
      18,    0,   97,    2, 0x0a /* Public */,
      19,    0,   98,    2, 0x0a /* Public */,
      20,    1,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   21,

 // properties: name, type, flags
      22, QMetaType::Int, 0x00495001,
      23, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       6,
       7,

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
        case 5: _t->CTRLEnabledChanged(); break;
        case 6: _t->velocityChanged(); break;
        case 7: _t->presetChanged(); break;
        case 8: { int _r = _t->toggleCtrl();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { int _r = _t->toggleCarStatus();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->stopCar();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->changePreset((*reinterpret_cast< int(*)>(_a[1]))); break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::CTRLEnabledChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::velocityChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CarStatusSim::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CarStatusSim::presetChanged)) {
                *result = 7;
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
        case 0: *reinterpret_cast< int*>(_v) = _t->velocity(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->preset(); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
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
void CarStatusSim::CTRLEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void CarStatusSim::velocityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void CarStatusSim::presetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
