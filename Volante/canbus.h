#ifndef CANBUS_H
#define CANBUS_H

#include <QTimer>
#include <QByteArray>
#include <QHash>
#include "carstatus.h"

#include <QCanBus>

// CarStatus Constants
#define CAR_STATUS_IDLE 0
#define CAR_STATUS_GO   1
#define CAR_STATUS_STOP 2

// ID in lettura
#define GET_CAN_STATUS          0xDA
#define GET_HV_STATE_ID         0xDB
#define GET_ERRORS_STATUS       0xDD
#define EXEC_MODE_ID            0xDF
#define GET_APPS_BSE_STATUS     0xDE
#define GET_STEER_STATUS        0xE1
#define BMS_STATUS_ID           0x7EB
#define GET_ACTUATORS_RANGE_ACK 0xBC

// ID in Scrittura
// Ask again to check the CAN communication of peripherals
#define CHECK_CAN_COM           0xEA
#define ASK_HV_STATE_ID         0xEB
#define CHECK_SENSOR_ERROR_ID   0xEC
#define ASK_SENSORS_VALUE_ID    0xED
#define ASK_BATTERY_STATUS      0xEE
#define CHANGE_EXEC_MODE_ID     0xEF

//NEW DEFINE FOR VARANO 2018
#define ECU_INV_LEFT            0x08
#define ECU_INV_RIGHT           0x09
#define STEERING_WHEEL_ID       0xA0
#define ECU_ERRORS              0x01
#define ECU_WARNINGS            0x02
#define ECU_MSG                 0x55
#define GET_ACTUATORS_RANGE_ACK 0xBC
#define SET_ACTUATORS_RANGES    0xBB
#define STM_PEDALS              0xB0

class Canbus : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int actuatorRangePendingFlag READ actuatorRangePendingFlag NOTIFY actuatorRangePendingFlagCleared)
    //property volt e temperature
    Q_PROPERTY(int hvTemp READ hvTemp NOTIFY hvTempChanged)
    Q_PROPERTY(int lvTemp READ lvTemp NOTIFY lvTempChanged)
    Q_PROPERTY(int hvVolt READ hvVolt NOTIFY hvVoltChanged)
    Q_PROPERTY(int lvVolt READ lvVolt NOTIFY lvVoltChanged)

    Q_PROPERTY(int brakeVal READ brakeVal NOTIFY brakeValChanged)
    Q_PROPERTY(int throttleVal READ throttleVal NOTIFY throttleValChanged)

    public:
        Canbus(CarStatus* carStatus, const QString can_interface);
        ~Canbus();

        int invLeftState;
        int invRightState;
        int preChargeState;

        int warning;
        int error;
        int velocity;
        int ctrlIsEnabled;

        int m_hvTemp;
        int m_hvVolt;
        int m_lvTemp;
        int m_lvVolt;

        int m_brakeVal;
        int m_throttleVal;

        int hvTemp() const;
        int lvTemp() const;
        int hvVolt() const;
        int lvVolt() const;

        int brakeVal() const;
        int throttleVal() const;


        int ctrlIsOn;
        int goStatus;
        int map;
        int driveModeEnabled;

        int actuatorRangePendingFlag() const;

        CarStatus* carStatus;

    private:
        QTimer *timer;

        qint64 canID;
        QByteArray canMSG;
        QString canMessage;

        void parseCANMessage(int mid, QByteArray msg);
        void sendCanMessage(int, QByteArray);

        int idIsArrived;

        int m_actuatorRangePendingFlag;

    signals:
        void controlStateChanged(int ctrlState, int warn, int err);
        void presetChanged(int presetID);
        void actuatorRangePendingFlagCleared();

        //signal per qml hv e lv temp volt
        void hvTempChanged();
        void lvTempChanged();
        void hvVoltChanged();
        void lvVoltChanged();

        void brakeValChanged();
        void throttleValChanged();

    public slots:
        void parseSerial();
        void toggleCar();
        void askHVUpdate(int);
        void setActuatorsRange(int, int);
        void checkCANCommunication(bool);
        void checkSensorsError();
        void steerConnected();
};

#endif // CANBUS_H
