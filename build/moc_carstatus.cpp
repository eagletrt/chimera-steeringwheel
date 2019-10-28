/****************************************************************************
** Meta object code from reading C++ file 'carstatus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../header/carstatus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'carstatus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CarStatus_t {
    QByteArrayData data[91];
    char stringdata0[994];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarStatus_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarStatus_t qt_meta_stringdata_CarStatus = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CarStatus"
QT_MOC_LITERAL(1, 10, 11), // "tempChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "temperature"
QT_MOC_LITERAL(4, 35, 10), // "socChanged"
QT_MOC_LITERAL(5, 46, 3), // "soc"
QT_MOC_LITERAL(6, 50, 15), // "execModeChanged"
QT_MOC_LITERAL(7, 66, 13), // "ctrlIsEnabled"
QT_MOC_LITERAL(8, 80, 8), // "ctrlIsOn"
QT_MOC_LITERAL(9, 89, 7), // "warning"
QT_MOC_LITERAL(10, 97, 5), // "error"
QT_MOC_LITERAL(11, 103, 16), // "carStatusChanged"
QT_MOC_LITERAL(12, 120, 14), // "warningChanged"
QT_MOC_LITERAL(13, 135, 12), // "errorChanged"
QT_MOC_LITERAL(14, 148, 9), // "toggleCar"
QT_MOC_LITERAL(15, 158, 15), // "HVStatusChanged"
QT_MOC_LITERAL(16, 174, 16), // "CANStatusChanged"
QT_MOC_LITERAL(17, 191, 16), // "ERRStatusChanged"
QT_MOC_LITERAL(18, 208, 17), // "APPSStatusChanged"
QT_MOC_LITERAL(19, 226, 16), // "BSEStatusChanged"
QT_MOC_LITERAL(20, 243, 18), // "STEERStatusChanged"
QT_MOC_LITERAL(21, 262, 18), // "CTRLEnabledChanged"
QT_MOC_LITERAL(22, 281, 15), // "velocityChanged"
QT_MOC_LITERAL(23, 297, 13), // "presetChanged"
QT_MOC_LITERAL(24, 311, 11), // "pumpChanged"
QT_MOC_LITERAL(25, 323, 12), // "speedChanged"
QT_MOC_LITERAL(26, 336, 9), // "kmChanged"
QT_MOC_LITERAL(27, 346, 13), // "hvTempChanged"
QT_MOC_LITERAL(28, 360, 13), // "lvTempChanged"
QT_MOC_LITERAL(29, 374, 13), // "hvVoltChanged"
QT_MOC_LITERAL(30, 388, 13), // "lvVoltChanged"
QT_MOC_LITERAL(31, 402, 16), // "invSxTempChanged"
QT_MOC_LITERAL(32, 419, 16), // "invDxTempChanged"
QT_MOC_LITERAL(33, 436, 15), // "brakeValChanged"
QT_MOC_LITERAL(34, 452, 18), // "throttleValChanged"
QT_MOC_LITERAL(35, 471, 10), // "toggleCtrl"
QT_MOC_LITERAL(36, 482, 15), // "toggleCarStatus"
QT_MOC_LITERAL(37, 498, 7), // "stopCar"
QT_MOC_LITERAL(38, 506, 12), // "changePreset"
QT_MOC_LITERAL(39, 519, 8), // "presetID"
QT_MOC_LITERAL(40, 528, 10), // "changePump"
QT_MOC_LITERAL(41, 539, 6), // "pumpID"
QT_MOC_LITERAL(42, 546, 26), // "setLeftInverterTemperature"
QT_MOC_LITERAL(43, 573, 4), // "val1"
QT_MOC_LITERAL(44, 578, 4), // "val2"
QT_MOC_LITERAL(45, 583, 27), // "setRightInverterTemperature"
QT_MOC_LITERAL(46, 611, 8), // "setSpeed"
QT_MOC_LITERAL(47, 620, 2), // "id"
QT_MOC_LITERAL(48, 623, 9), // "prescaler"
QT_MOC_LITERAL(49, 633, 5), // "setKm"
QT_MOC_LITERAL(50, 639, 6), // "meter1"
QT_MOC_LITERAL(51, 646, 6), // "meter2"
QT_MOC_LITERAL(52, 653, 18), // "setPedalsPrescaler"
QT_MOC_LITERAL(53, 672, 11), // "setThrottle"
QT_MOC_LITERAL(54, 684, 3), // "val"
QT_MOC_LITERAL(55, 688, 8), // "setBrake"
QT_MOC_LITERAL(56, 697, 11), // "stopMessage"
QT_MOC_LITERAL(57, 709, 8), // "inverter"
QT_MOC_LITERAL(58, 718, 11), // "setHVStatus"
QT_MOC_LITERAL(59, 730, 7), // "uint8_t"
QT_MOC_LITERAL(60, 738, 4), // "val3"
QT_MOC_LITERAL(61, 743, 4), // "val4"
QT_MOC_LITERAL(62, 748, 4), // "val5"
QT_MOC_LITERAL(63, 753, 4), // "val6"
QT_MOC_LITERAL(64, 758, 4), // "val7"
QT_MOC_LITERAL(65, 763, 11), // "setLVStatus"
QT_MOC_LITERAL(66, 775, 12), // "setTelemetry"
QT_MOC_LITERAL(67, 788, 5), // "index"
QT_MOC_LITERAL(68, 794, 5), // "value"
QT_MOC_LITERAL(69, 800, 9), // "CANStatus"
QT_MOC_LITERAL(70, 810, 8), // "HVStatus"
QT_MOC_LITERAL(71, 819, 9), // "ERRStatus"
QT_MOC_LITERAL(72, 829, 11), // "CTRLEnabled"
QT_MOC_LITERAL(73, 841, 10), // "APPSStatus"
QT_MOC_LITERAL(74, 852, 10), // "QList<int>"
QT_MOC_LITERAL(75, 863, 9), // "BSEStatus"
QT_MOC_LITERAL(76, 873, 11), // "STEERStatus"
QT_MOC_LITERAL(77, 885, 8), // "velocity"
QT_MOC_LITERAL(78, 894, 6), // "preset"
QT_MOC_LITERAL(79, 901, 4), // "pump"
QT_MOC_LITERAL(80, 906, 9), // "carStatus"
QT_MOC_LITERAL(81, 916, 9), // "invSxTemp"
QT_MOC_LITERAL(82, 926, 9), // "invDxTemp"
QT_MOC_LITERAL(83, 936, 6), // "hvTemp"
QT_MOC_LITERAL(84, 943, 6), // "lvTemp"
QT_MOC_LITERAL(85, 950, 6), // "hvVolt"
QT_MOC_LITERAL(86, 957, 6), // "lvVolt"
QT_MOC_LITERAL(87, 964, 5), // "speed"
QT_MOC_LITERAL(88, 970, 2), // "km"
QT_MOC_LITERAL(89, 973, 8), // "brakeVal"
QT_MOC_LITERAL(90, 982, 11) // "throttleVal"

    },
    "CarStatus\0tempChanged\0\0temperature\0"
    "socChanged\0soc\0execModeChanged\0"
    "ctrlIsEnabled\0ctrlIsOn\0warning\0error\0"
    "carStatusChanged\0warningChanged\0"
    "errorChanged\0toggleCar\0HVStatusChanged\0"
    "CANStatusChanged\0ERRStatusChanged\0"
    "APPSStatusChanged\0BSEStatusChanged\0"
    "STEERStatusChanged\0CTRLEnabledChanged\0"
    "velocityChanged\0presetChanged\0pumpChanged\0"
    "speedChanged\0kmChanged\0hvTempChanged\0"
    "lvTempChanged\0hvVoltChanged\0lvVoltChanged\0"
    "invSxTempChanged\0invDxTempChanged\0"
    "brakeValChanged\0throttleValChanged\0"
    "toggleCtrl\0toggleCarStatus\0stopCar\0"
    "changePreset\0presetID\0changePump\0"
    "pumpID\0setLeftInverterTemperature\0"
    "val1\0val2\0setRightInverterTemperature\0"
    "setSpeed\0id\0prescaler\0setKm\0meter1\0"
    "meter2\0setPedalsPrescaler\0setThrottle\0"
    "val\0setBrake\0stopMessage\0inverter\0"
    "setHVStatus\0uint8_t\0val3\0val4\0val5\0"
    "val6\0val7\0setLVStatus\0setTelemetry\0"
    "index\0value\0CANStatus\0HVStatus\0ERRStatus\0"
    "CTRLEnabled\0APPSStatus\0QList<int>\0"
    "BSEStatus\0STEERStatus\0velocity\0preset\0"
    "pump\0carStatus\0invSxTemp\0invDxTemp\0"
    "hvTemp\0lvTemp\0hvVolt\0lvVolt\0speed\0km\0"
    "brakeVal\0throttleVal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarStatus[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
      23,  340, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      27,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  229,    2, 0x06 /* Public */,
       4,    1,  232,    2, 0x06 /* Public */,
       6,    4,  235,    2, 0x06 /* Public */,
      11,    0,  244,    2, 0x06 /* Public */,
      12,    0,  245,    2, 0x06 /* Public */,
      13,    0,  246,    2, 0x06 /* Public */,
      14,    0,  247,    2, 0x06 /* Public */,
      15,    0,  248,    2, 0x06 /* Public */,
      16,    0,  249,    2, 0x06 /* Public */,
      17,    0,  250,    2, 0x06 /* Public */,
      18,    0,  251,    2, 0x06 /* Public */,
      19,    0,  252,    2, 0x06 /* Public */,
      20,    0,  253,    2, 0x06 /* Public */,
      21,    0,  254,    2, 0x06 /* Public */,
      22,    0,  255,    2, 0x06 /* Public */,
      23,    0,  256,    2, 0x06 /* Public */,
      24,    0,  257,    2, 0x06 /* Public */,
      25,    0,  258,    2, 0x06 /* Public */,
      26,    0,  259,    2, 0x06 /* Public */,
      27,    0,  260,    2, 0x06 /* Public */,
      28,    0,  261,    2, 0x06 /* Public */,
      29,    0,  262,    2, 0x06 /* Public */,
      30,    0,  263,    2, 0x06 /* Public */,
      31,    0,  264,    2, 0x06 /* Public */,
      32,    0,  265,    2, 0x06 /* Public */,
      33,    0,  266,    2, 0x06 /* Public */,
      34,    0,  267,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      35,    0,  268,    2, 0x0a /* Public */,
      36,    0,  269,    2, 0x0a /* Public */,
      37,    0,  270,    2, 0x0a /* Public */,
      38,    1,  271,    2, 0x0a /* Public */,
      40,    1,  274,    2, 0x0a /* Public */,
      42,    2,  277,    2, 0x0a /* Public */,
      45,    2,  282,    2, 0x0a /* Public */,
      46,    4,  287,    2, 0x0a /* Public */,
      49,    2,  296,    2, 0x0a /* Public */,
      52,    1,  301,    2, 0x0a /* Public */,
      53,    1,  304,    2, 0x0a /* Public */,
      55,    1,  307,    2, 0x0a /* Public */,
      56,    1,  310,    2, 0x0a /* Public */,
      58,    8,  313,    2, 0x0a /* Public */,
      65,    2,  330,    2, 0x0a /* Public */,
      66,    2,  335,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   43,   44,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   43,   44,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   47,   43,   44,   48,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   50,   51,
    QMetaType::Void, QMetaType::Int,   48,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void, QMetaType::Int,   54,
    QMetaType::Void, QMetaType::Int,   57,
    QMetaType::Void, 0x80000000 | 59, 0x80000000 | 59, 0x80000000 | 59, 0x80000000 | 59, 0x80000000 | 59, 0x80000000 | 59, 0x80000000 | 59, 0x80000000 | 59,   47,   43,   44,   60,   61,   62,   63,   64,
    QMetaType::Void, 0x80000000 | 59, 0x80000000 | 59,   43,   60,
    QMetaType::Bool, QMetaType::Int, QMetaType::Bool,   67,   68,

 // properties: name, type, flags
      69, QMetaType::QString, 0x00495001,
      70, QMetaType::QString, 0x00495001,
      71, QMetaType::QString, 0x00495001,
      72, QMetaType::QString, 0x00495001,
      73, 0x80000000 | 74, 0x00495009,
      75, 0x80000000 | 74, 0x00495009,
      76, 0x80000000 | 74, 0x00495009,
      77, QMetaType::Int, 0x00495001,
      78, QMetaType::Int, 0x00495001,
      79, QMetaType::Int, 0x00495001,
       9, QMetaType::Int, 0x00495001,
      10, QMetaType::Int, 0x00495001,
      80, QMetaType::Int, 0x00495001,
      81, QMetaType::Int, 0x00495001,
      82, QMetaType::Int, 0x00495001,
      83, QMetaType::Int, 0x00495001,
      84, QMetaType::Int, 0x00495001,
      85, QMetaType::Int, 0x00495001,
      86, QMetaType::Int, 0x00495001,
      87, QMetaType::Int, 0x00495001,
      88, QMetaType::Int, 0x00495001,
      89, QMetaType::Int, 0x00495001,
      90, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       8,
       7,
       9,
      13,
      10,
      11,
      12,
      14,
      15,
      16,
       4,
       5,
       3,
      23,
      24,
      19,
      20,
      21,
      22,
      17,
      18,
      25,
      26,

       0        // eod
};

void CarStatus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarStatus *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tempChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->socChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->execModeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->carStatusChanged(); break;
        case 4: _t->warningChanged(); break;
        case 5: _t->errorChanged(); break;
        case 6: _t->toggleCar(); break;
        case 7: _t->HVStatusChanged(); break;
        case 8: _t->CANStatusChanged(); break;
        case 9: _t->ERRStatusChanged(); break;
        case 10: _t->APPSStatusChanged(); break;
        case 11: _t->BSEStatusChanged(); break;
        case 12: _t->STEERStatusChanged(); break;
        case 13: _t->CTRLEnabledChanged(); break;
        case 14: _t->velocityChanged(); break;
        case 15: _t->presetChanged(); break;
        case 16: _t->pumpChanged(); break;
        case 17: _t->speedChanged(); break;
        case 18: _t->kmChanged(); break;
        case 19: _t->hvTempChanged(); break;
        case 20: _t->lvTempChanged(); break;
        case 21: _t->hvVoltChanged(); break;
        case 22: _t->lvVoltChanged(); break;
        case 23: _t->invSxTempChanged(); break;
        case 24: _t->invDxTempChanged(); break;
        case 25: _t->brakeValChanged(); break;
        case 26: _t->throttleValChanged(); break;
        case 27: { int _r = _t->toggleCtrl();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 28: { int _r = _t->toggleCarStatus();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 29: { int _r = _t->stopCar();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 30: _t->changePreset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->changePump((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->setLeftInverterTemperature((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: _t->setRightInverterTemperature((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->setSpeed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 35: _t->setKm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: _t->setPedalsPrescaler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->setThrottle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->setBrake((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->stopMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->setHVStatus((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2])),(*reinterpret_cast< uint8_t(*)>(_a[3])),(*reinterpret_cast< uint8_t(*)>(_a[4])),(*reinterpret_cast< uint8_t(*)>(_a[5])),(*reinterpret_cast< uint8_t(*)>(_a[6])),(*reinterpret_cast< uint8_t(*)>(_a[7])),(*reinterpret_cast< uint8_t(*)>(_a[8]))); break;
        case 41: _t->setLVStatus((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 42: { bool _r = _t->setTelemetry((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CarStatus::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::tempChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::socChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::execModeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::carStatusChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::warningChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::errorChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::toggleCar)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::HVStatusChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::CANStatusChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::ERRStatusChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::APPSStatusChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::BSEStatusChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::STEERStatusChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::CTRLEnabledChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::velocityChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::presetChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::pumpChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::speedChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::kmChanged)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::hvTempChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::lvTempChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::hvVoltChanged)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::lvVoltChanged)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::invSxTempChanged)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::invDxTempChanged)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::brakeValChanged)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (CarStatus::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CarStatus::throttleValChanged)) {
                *result = 26;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
        case 5:
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CarStatus *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->CANStatus(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->HVStatus(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->ERRStatus(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->CTRLEnabled(); break;
        case 4: *reinterpret_cast< QList<int>*>(_v) = _t->APPSStatus(); break;
        case 5: *reinterpret_cast< QList<int>*>(_v) = _t->BSEStatus(); break;
        case 6: *reinterpret_cast< QList<int>*>(_v) = _t->STEERStatus(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->velocity(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->preset(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->pump(); break;
        case 10: *reinterpret_cast< int*>(_v) = _t->warning(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->error(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->carStatus(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->invSxTemp(); break;
        case 14: *reinterpret_cast< int*>(_v) = _t->invDxTemp(); break;
        case 15: *reinterpret_cast< int*>(_v) = _t->hvTemp(); break;
        case 16: *reinterpret_cast< int*>(_v) = _t->lvTemp(); break;
        case 17: *reinterpret_cast< int*>(_v) = _t->hvVolt(); break;
        case 18: *reinterpret_cast< int*>(_v) = _t->lvVolt(); break;
        case 19: *reinterpret_cast< int*>(_v) = _t->speed(); break;
        case 20: *reinterpret_cast< int*>(_v) = _t->km(); break;
        case 21: *reinterpret_cast< int*>(_v) = _t->brakeVal(); break;
        case 22: *reinterpret_cast< int*>(_v) = _t->throttleVal(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CarStatus::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CarStatus.data,
    qt_meta_data_CarStatus,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CarStatus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarStatus::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CarStatus.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CarStatus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 43;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 23;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 23;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CarStatus::tempChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CarStatus::socChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CarStatus::execModeChanged(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CarStatus::carStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void CarStatus::warningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CarStatus::errorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void CarStatus::toggleCar()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void CarStatus::HVStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void CarStatus::CANStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void CarStatus::ERRStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void CarStatus::APPSStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void CarStatus::BSEStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void CarStatus::STEERStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void CarStatus::CTRLEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void CarStatus::velocityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void CarStatus::presetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void CarStatus::pumpChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void CarStatus::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void CarStatus::kmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void CarStatus::hvTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void CarStatus::lvTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void CarStatus::hvVoltChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void CarStatus::lvVoltChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void CarStatus::invSxTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void CarStatus::invDxTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void CarStatus::brakeValChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void CarStatus::throttleValChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
