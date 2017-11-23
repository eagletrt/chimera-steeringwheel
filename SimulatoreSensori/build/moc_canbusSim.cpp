/****************************************************************************
** Meta object code from reading C++ file 'canbusSim.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../canbusSim.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'canbusSim.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CanbusSim_t {
    QByteArrayData data[12];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CanbusSim_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CanbusSim_t qt_meta_stringdata_CanbusSim = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CanbusSim"
QT_MOC_LITERAL(1, 10, 19), // "controlStateChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "ctrlState"
QT_MOC_LITERAL(4, 41, 4), // "warn"
QT_MOC_LITERAL(5, 46, 3), // "err"
QT_MOC_LITERAL(6, 50, 13), // "presetChanged"
QT_MOC_LITERAL(7, 64, 8), // "presetID"
QT_MOC_LITERAL(8, 73, 9), // "toggleCar"
QT_MOC_LITERAL(9, 83, 11), // "askHVUpdate"
QT_MOC_LITERAL(10, 95, 21), // "checkCANCommunication"
QT_MOC_LITERAL(11, 117, 17) // "checkSensorsError"

    },
    "CanbusSim\0controlStateChanged\0\0ctrlState\0"
    "warn\0err\0presetChanged\0presetID\0"
    "toggleCar\0askHVUpdate\0checkCANCommunication\0"
    "checkSensorsError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CanbusSim[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       6,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   54,    2, 0x0a /* Public */,
       9,    1,   55,    2, 0x0a /* Public */,
      10,    1,   58,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void CanbusSim::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CanbusSim *_t = static_cast<CanbusSim *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->controlStateChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->presetChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->toggleCar(); break;
        case 3: _t->askHVUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->checkCANCommunication((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->checkSensorsError(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CanbusSim::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanbusSim::controlStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CanbusSim::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CanbusSim::presetChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CanbusSim::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CanbusSim.data,
      qt_meta_data_CanbusSim,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CanbusSim::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CanbusSim::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CanbusSim.stringdata0))
        return static_cast<void*>(const_cast< CanbusSim*>(this));
    return QObject::qt_metacast(_clname);
}

int CanbusSim::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CanbusSim::controlStateChanged(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CanbusSim::presetChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
