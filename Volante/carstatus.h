#ifndef CARSTATUS_H
#define CARSTATUS_H

#define CAR_STATUS_IDLE    0
#define CAR_STATUS_SETUP   1
#define CAR_STATUS_RUN     2
#define CAR_STATUS_STOP    3

#define PRESET_NUMBER      6
#define PUMP_NUMBER      6

#include <QDebug>

class CarStatus : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString CANStatus READ CANStatus NOTIFY CANStatusChanged)
    Q_PROPERTY(QString HVStatus READ HVStatus NOTIFY HVStatusChanged)
    Q_PROPERTY(QString ERRStatus READ ERRStatus NOTIFY ERRStatusChanged)
    Q_PROPERTY(QString CTRLEnabled READ CTRLEnabled NOTIFY CTRLEnabledChanged)
    Q_PROPERTY(QList<int> APPSStatus READ APPSStatus NOTIFY APPSStatusChanged)
    Q_PROPERTY(QList<int> BSEStatus READ BSEStatus NOTIFY BSEStatusChanged)
    Q_PROPERTY(QList<int> STEERStatus READ STEERStatus NOTIFY STEERStatusChanged)
    Q_PROPERTY(int velocity READ velocity NOTIFY velocityChanged)
    Q_PROPERTY(int preset READ preset NOTIFY presetChanged)
    Q_PROPERTY(int pump READ pump NOTIFY pumpChanged)

    Q_PROPERTY(int warning READ warning NOTIFY warningChanged)
    Q_PROPERTY(int error READ error NOTIFY errorChanged)

    Q_PROPERTY(int carStatus READ carStatus NOTIFY carStatusChanged)


    public:
        CarStatus();
        ~CarStatus();

        const int LOOP_THROUGH_PRESETS = -1;
        const int LOOP_THROUGH_PUMPS = -1;

        QString CANStatus() const;
        QString HVStatus() const;
        QString ERRStatus() const;
        QList<int> APPSStatus() const;
        QList<int> BSEStatus() const;
        QList<int> STEERStatus() const;
        QString CTRLEnabled() const;

        int velocity() const;
        int preset() const;
        int pump() const;

        void setHVStatus(int invRight, int invLeft, int preCharge);
        void setCarStatus(int, int, int, int, int, int);
        void setCANStatus(int, int, int, int, int, int, int, int);
        void setERRStatus(int, int, int, int, int, int, int, int, int);
        void setAPPSBSEStatus(int, int);
        void setSTEERStatus(int);

        void setCarMode(int mode);

        int getCtrlIsEnabled();
        int getCtrlIsOn();
        int getCurrentStatus();
        int getMap();
        int getPump();

        int carStatus();
        void setWarning(int on);
        void setError(int on);
        void setVelocity(int vel);

        int warning() const;
        int error() const;

        void setTemperature(int temperature);
        void setStateOfCharge(int stateofcharge);

    public slots:
        int toggleCtrl();
        int toggleCarStatus();
        int stopCar();
        void changePreset(int presetID);
        void changePump(int pumpID);

    private:
        static int getBit(unsigned char seq, int index);
        int m_invRight;
        int m_invLeft;
        int m_preCharge;

        int m_ctrlIsEnabled;
        int m_ctrlIsOn;
        int m_car_status;

        int m_warning;
        int m_error;

        int m_stateofcharge;
        int m_temperature;
        int m_velocity;
        int m_preset;
        int m_pump;

        int m_invr;
        int m_invl;
        int m_front;
        int m_rear;
        int m_lv;
        int m_hv;
        int m_central;
        int m_pedals;

        int m_err_apps;
        int m_err_bse;
        int m_err_steer;
        int m_err_wheel_left;
        int m_err_wheel_right;
        int m_err_gps;
        int m_err_imu_front;
        int m_err_imu_central;
        int m_err_imu_rear;

        int m_apps;
        int m_num_err_apps;
        int m_bse;
        int m_num_err_bse;
        int m_steer;
        int m_num_err_steer;

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
        void ERRStatusChanged();
        void APPSStatusChanged();
        void BSEStatusChanged();
        void STEERStatusChanged();
        void CTRLEnabledChanged();
        void velocityChanged();
        void presetChanged();
        void pumpChanged();
};

#endif // CARSTATUS_H
