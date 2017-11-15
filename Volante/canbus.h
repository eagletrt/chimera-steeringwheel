#ifndef CANBUS_H 
#define CANBUS_H

#include <QSerialPort>
#include <QTimer>
#include <QByteArray>
#include <QHash>
#include "carstatus.h"

// CarStatus Constants
#define CAR_STATUS_IDLE 0
#define CAR_STATUS_GO   1
#define CAR_STATUS_STOP 2

// ID in lettura
#define GET_CAN_STATUS      0xDA
#define HV_STATE_ID         0xDB
#define GET_ERRORS_STATUS   0xDD
#define EXEC_MODE_ID        0xDF
#define BMS_STATUS_ID       0x7EB

// ID in Scrittura 
// Ask again to check the CAN communication of peripherals
#define CHECK_CAN_COM           0xEA
#define ASK_HV_STATE_ID         0xEB
#define CHECK_SENSOR_ERROR_ID   0xEC
#define ASK_SENSORS_VALUE_ID    0xED
#define ASK_BATTERY_STATUS      0xEE
#define CHANGE_EXEC_MODE_ID     0xEF

class Canbus : public QObject
{
    Q_OBJECT

    public:
        Canbus(CarStatus* carStatus, const QString serial_port);
        ~Canbus();

        QSerialPort serial;

        int invLeftState;
        int invRightState;
        int preChargeState;

        int warning;
        int error;
        int velocity;
        int ctrlIsEnabled;
        int ctrlIsOn;
        int goStatus;
        int driveModeEnabled;

        CarStatus* carStatus;

    private:
        QTimer timer;
        qint64 canID;
        QByteArray canMSG;
        QString canMessage;

        void parseCANMessage(int mid, QByteArray msg);
        void sendCanMessage(int, QString);

        int idIsArrived;

    signals:
        void controlStateChanged(int ctrlState, int warn, int err); 
        void presetChanged(int presetID); 

    public slots:
        void parseSerial();
        void toggleCar();
        void askHVUpdate(int);
        void checkCANCommunication(bool);
        void checkSensorsError();
};

#endif // CANBUS_H

