/****************************************************************************
** Meta object code from reading C++ file 'arduinomgr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../arduinomgr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arduinomgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ArduinoMgr_t {
    QByteArrayData data[12];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArduinoMgr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArduinoMgr_t qt_meta_stringdata_ArduinoMgr = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ArduinoMgr"
QT_MOC_LITERAL(1, 11, 17), // "brightnessChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 13), // "volumeChanged"
QT_MOC_LITERAL(4, 44, 10), // "brightness"
QT_MOC_LITERAL(5, 55, 6), // "volume"
QT_MOC_LITERAL(6, 62, 6), // "turnOn"
QT_MOC_LITERAL(7, 69, 2), // "id"
QT_MOC_LITERAL(8, 72, 7), // "turnOff"
QT_MOC_LITERAL(9, 80, 10), // "writeToTxt"
QT_MOC_LITERAL(10, 91, 4), // "text"
QT_MOC_LITERAL(11, 96, 11) // "readFromTxt"

    },
    "ArduinoMgr\0brightnessChanged\0\0"
    "volumeChanged\0brightness\0volume\0turnOn\0"
    "id\0turnOff\0writeToTxt\0text\0readFromTxt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArduinoMgr[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    1,   58,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      11,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::Int, 0x00495001,
       5, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void ArduinoMgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ArduinoMgr *_t = static_cast<ArduinoMgr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->brightnessChanged(); break;
        case 1: _t->volumeChanged(); break;
        case 2: { qint32 _r = _t->brightness();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 3: { qint32 _r = _t->volume();
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = _r; }  break;
        case 4: _t->turnOn((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 5: _t->turnOff((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 6: _t->writeToTxt((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->readFromTxt(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ArduinoMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ArduinoMgr::brightnessChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ArduinoMgr::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ArduinoMgr::volumeChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ArduinoMgr *_t = static_cast<ArduinoMgr *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qint32*>(_v) = _t->brightness(); break;
        case 1: *reinterpret_cast< qint32*>(_v) = _t->volume(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ArduinoMgr::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ArduinoMgr.data,
      qt_meta_data_ArduinoMgr,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ArduinoMgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArduinoMgr::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ArduinoMgr.stringdata0))
        return static_cast<void*>(const_cast< ArduinoMgr*>(this));
    return QObject::qt_metacast(_clname);
}

int ArduinoMgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ArduinoMgr::brightnessChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ArduinoMgr::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
