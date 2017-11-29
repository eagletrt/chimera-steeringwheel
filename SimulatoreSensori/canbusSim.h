#ifndef CANBUSSIM_H
#define CANBUSSIM_H

#include <QSerialPort>
#include <QTimer>
#include <QByteArray>
#include <QHash>
#include "carstatusSim.h"
#include <vector>

// CarStatus Constants
#define CAR_STATUS_IDLE 0
#define CAR_STATUS_GO   1
#define CAR_STATUS_STOP 2

// ID requests to control boxes
#define GET_CAN_STATUS      0xDA
#define GET_HV_STATE_ID     0xDB
#define GET_ERRORS_STATUS   0xDD
#define EXEC_MODE_ID        0xDF
#define GET_APPS_BSE_STATUS 0xDE
#define GET_STEER_STATUS    0xE1
#define BMS_STATUS_ID       0x7EB

// ID requests from volante
// Ask again to check the CAN communication of peripherals
#define CHECK_CAN_COM           0xEA
#define ASK_HV_STATE_ID         0xEB
#define CHECK_SENSOR_ERROR_ID   0xEC
#define ASK_SENSORS_VALUE_ID    0xED
#define ASK_BATTERY_STATUS      0xEE
#define CHANGE_EXEC_MODE_ID     0xEF

class CanbusSim : public QObject
{
    Q_OBJECT

    public:
        CanbusSim(CarStatusSim* carStatus, const QString serial_port);
        ~CanbusSim();

        QSerialPort serial;

        void sendCanMessage(int, QString);
        void MySendSerialMessage(int, std::vector<int>);

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

        CarStatusSim* carStatus;

    private:
        QTimer *timer;
        qint64 canID;
        QByteArray canMSG;
        QString canMessage;

        int idIsArrived;

    signals:
        void controlStateChanged(int ctrlState, int warn, int err);
        void presetChanged(int presetID);

    public slots:
        void toggleCar();
        void checkCANCommunication(bool);
};

#endif // CANBUSSIM_H

