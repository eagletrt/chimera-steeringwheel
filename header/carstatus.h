#ifndef CARSTATUS_H
#define CARSTATUS_H

#define CAR_STATUS_IDLE    0
#define CAR_STATUS_SETUP   1
#define CAR_STATUS_RUN     2
#define CAR_STATUS_STOP    3

#define MAP_NUMBER         6
#define PUMP_NUMBER        6
#define TC_NUMBER          6

#define GRAPHICTIMER       100

#include <QDebug>
#include <QTimer>
#include "inverters.h"
#include "control.h"
#include "race.h"
#include "warning.h"
#include "manettini.h"
#include "errors.h"
#include "hv.h"
#include "sensors.h"
#include "telemetry.h"

class CarStatus : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString CANStatus READ CANStatus NOTIFY CANStatusChanged)
    Q_PROPERTY(QString TelemetryStatus READ TelemetryStatus NOTIFY TelemetryStatusChanged)
    Q_PROPERTY(int TelemetryEnabledStatus READ TelemetryEnabledStatus NOTIFY TelemetryEnabledStatusChanged)
    Q_PROPERTY(int SteeringWheelPopup READ SteeringWheelPopup NOTIFY SteeringWheelPopupChanged)
    Q_PROPERTY(QString HVStatus READ HVStatus NOTIFY HVStatusChanged)
    Q_PROPERTY(QString ERRStatus READ ERRStatus NOTIFY ERRStatusChanged)
    Q_PROPERTY(QString CTRLEnabled READ CTRLEnabled NOTIFY CTRLEnabledChanged)
    Q_PROPERTY(QList<int> APPSStatus READ APPSStatus NOTIFY APPSStatusChanged)
    Q_PROPERTY(QList<int> BSEStatus READ BSEStatus NOTIFY BSEStatusChanged)
    Q_PROPERTY(QList<int> STEERStatus READ STEERStatus NOTIFY STEERStatusChanged)
    Q_PROPERTY(int velocity READ velocity NOTIFY velocityChanged)
    Q_PROPERTY(int map READ map NOTIFY mapChanged)
    Q_PROPERTY(int tc READ tc NOTIFY tcChanged)
    Q_PROPERTY(int pump READ pump NOTIFY pumpChanged)

    Q_PROPERTY(int varWarning READ getWarning NOTIFY warningChanged)
    Q_PROPERTY(int error READ error NOTIFY errorChanged)

    Q_PROPERTY(int carStatus READ carStatus NOTIFY carStatusChanged)

    Q_PROPERTY(int invSxTemp READ invSxTemp NOTIFY invSxTempChanged)
    Q_PROPERTY(int invDxTemp READ invDxTemp NOTIFY invDxTempChanged)

    Q_PROPERTY(int hvTemp READ hvTemp NOTIFY hvTempChanged)
    Q_PROPERTY(int lvTemp READ lvTemp NOTIFY lvTempChanged)
    Q_PROPERTY(int hvVolt READ hvVolt NOTIFY hvVoltChanged)
    Q_PROPERTY(int lvVolt READ lvVolt NOTIFY lvVoltChanged)
    Q_PROPERTY(int speed READ speed NOTIFY speedChanged)
    Q_PROPERTY(int km READ km NOTIFY kmChanged)
    Q_PROPERTY(int brakeVal READ brakeVal NOTIFY brakeValChanged)
    Q_PROPERTY(int throttleVal READ throttleVal NOTIFY throttleValChanged)
   

    public:
        CarStatus();
        ~CarStatus();

        const int LOOP_THROUGH_MAPS = -1;
        const int LOOP_THROUGH_PUMPS = -1;
        const int LOOP_THROUGH_TCS = -1;

        QString CANStatus() const;
        QString TelemetryStatus() const;
        int TelemetryEnabledStatus() const;
        int SteeringWheelPopup() const;
        QString HVStatus() const;
        QString ERRStatus() const;
        QList<int> APPSStatus() const;
        QList<int> BSEStatus() const;
        QList<int> STEERStatus() const;
        QString CTRLEnabled() const;

        int map() const;
        int pump() const;
        int tc() const;
        int velocity() const;
        
        void setHVStatus(int invRight, int invLeft, int preCharge);
        void setCarStatus(int, int, int, int, int);
        void setCANStatus(int, int, int, int, int, int, int, int);
        void setTelemetryStatus(int, int, int, int, int, int, int, int, int, int, int);
        void setTelemetryEnabledStatus(int);
        void setSteeringWheelPopup(int);
        void setERRStatus(int, int, int, int, int, int, int, int, int);
        void setAPPSBSEStatus(int, int);
        void setSTEERStatus(int);

        void setCarMode(int mode);

        int getCtrlIsEnabled();
        int getCtrlIsOn();
        int getMap();
        int getPump();

        int carStatus();
        void setWarning(int on);
        void setError(int on);

        int getWarning() const;
        int error() const;

        //void setTemperature(int temperature);
        //void setStateOfCharge(int stateofcharge);

        int speed() const;
        int km() const;
        int invSxTemp() const;
        int invDxTemp() const;
        int hvTemp() const;
        int lvTemp() const;
        int hvVolt() const;
        int lvVolt() const;

        int brakeVal() const;
        int throttleVal() const;

        bool getSender();

    public slots:
        int toggleCtrl();
        int toggleCarStatus();
        int stopCar();
        void changeMap(int mapID);
        void changePump(int pumpID);
        void changeTc(int tcID);

        void setLeftInverterTemperature(int val1, int val2);
        void setRightInverterTemperature(int val1, int val2);        
        void setSpeed(int val1, int val2);
        void setKm(int meter1, int meter2);
        void setThrottle(int val);
        void setBrake(int val);
        void stopMessage(int inverter);
        void setHVStatus(uint8_t id,uint8_t val1,uint8_t val2,uint8_t val3,uint8_t val4,uint8_t val5,uint8_t val6,uint8_t val7);
        void setLVStatus(uint8_t val1, uint8_t val3);
        
        QByteArray getTelemetryStatus();
        bool setTelemetry(int index);
        void setSender();
        QByteArray getTelemetryEnabledStatus();

        void processingTimeout();

    private:
        static int getBit(unsigned char seq, int index);
        //int m_invRight; moved into inverters
        //int m_invLeft; moved into inverters
        //int m_preCharge; moved into inverters
        //int m_invSxTemp; moved into inverters
        //int m_invDxTemp; moved into inverters
        Inverters inverters;

        Control control;

        // not used
        //int m_stateofcharge;
        //int m_temperature;

        // Racing Page
        //int m_speed; moved into race
        //int m_velocity; moved into race
        //int m_km; moved into race

        Race race;

        // manettini
        //int m_map;
        //int m_tc;
        //int m_pump;
        Manettini manettini;

        // warnings
        //int m_invr;  moved into warning
        //int m_invl;  moved into warning
        //int m_front; moved into warning
        //int m_rear; moved into warning
        //int m_lv; moved into warning
        //int m_hv; moved into warning
        //int m_central; moved into warning
        //int m_pedals; moved into warning
        //int m_warning; moved into warning

        Warning warning;

        // errors
        //int m_err_apps;
        //int m_err_bse;
        //int m_err_steer;
        //int m_err_wheel_left;
        //int m_err_wheel_right;
        //int m_err_gps;
        //int m_err_imu_front;
        //int m_err_imu_central;
        //int m_err_imu_rear;
        //int m_error;

        Errors errors;
        
        // tab sensors
        //int m_brakeVal;
        //int m_throttleVal;
        //int m_apps;
        //int m_bse;
        //int m_steer;
        //int m_num_err_apps;
        //int m_num_err_bse;
        //int m_num_err_steer;
        Sensors sensors;
        
        // hv
        //int m_hvTemp; moved into Hv
        //int m_hvVolt; moved into Hv

        Hv hv;

        // lv
        int m_lvTemp;
        int m_lvVolt;

        //QString firstTelemetry; Useless, who put these please delete them
        //QString secondTelemetry; Useless, who put these please delete them

        Telemetry telemetry;
        
        //int telemetry[12]; moved into telemetry
        //bool sender; moved into telemetry
        //int telemetryEnStatus; moved into telemetry
        //int popup; moved into telemetry

    signals:
        void tempChanged(int temperature);
        void socChanged(int soc);
        void execModeChanged(int ctrlIsEnabled, int ctrlIsOn, int warning, int error);
        void carStatusChanged();
        void warningChanged();
        void errorChanged();

        void toggleCar();

        void HVStatusChanged();
        void CANStatusChanged();
        void TelemetryStatusChanged();
        void TelemetryEnabledStatusChanged();
        void SteeringWheelPopupChanged();
        void ERRStatusChanged();
        void APPSStatusChanged();
        void BSEStatusChanged();
        void STEERStatusChanged();
        void CTRLEnabledChanged();
        void velocityChanged();
        void mapChanged();
        void tcChanged();
        void pumpChanged();

        //signal per qml hv e lv temp volt
        void speedChanged();
        void kmChanged();
        void hvTempChanged();
        void lvTempChanged();
        void hvVoltChanged();
        void lvVoltChanged();
        void invSxTempChanged();
        void invDxTempChanged();

        void brakeValChanged();
        void throttleValChanged();

};

#endif // CARSTATUS_H
