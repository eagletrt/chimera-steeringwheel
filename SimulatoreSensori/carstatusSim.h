#ifndef CARSTATUSSIM_H
#define CARSTATUSSIM_H

#define CAR_STATUS_IDLE 0
#define CAR_STATUS_GO   1
#define CAR_STATUS_STOP 2

#include <QDebug>

class CarStatusSim : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int velocity READ velocity NOTIFY velocityChanged)
    Q_PROPERTY(int preset READ preset NOTIFY presetChanged)

    public:
        CarStatusSim();
        ~CarStatusSim();

        int velocity() const;
        int preset() const;

        void setHVStatus(int invRight, int invLeft, int preCharge);
        void setCarStatus(int, int, int, int, int, int);
        void setCANStatus(int, int, int, int, int, int);
        void setERRStatus(int, int, int, int, int, int, int, int);
        void setAPPSBSEStatus(int, int, int, int);
        void setSTEERStatus(int, int);

        int getCtrlIsEnabled();
        int getCtrlIsOn();
        int getCurrentStatus();

        void setTemperature(int temperature);
        void setStateOfCharge(int stateofcharge);

    public slots:
        int toggleCtrl();
        int toggleCarStatus();
        int stopCar();
        void changePreset(int presetID);

    private:
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

        int m_invr = -1;
        int m_invl = -1;
        int m_front = -1;
        int m_rear = -1;
        int m_lv = -1;
        int m_hv = -1;

        int m_err_apps = 2;
        int m_err_bse = 2;
        int m_err_steer = 2;
        int m_err_wheel_right = 2;
        int m_err_wheel_left = 2;
        int m_err_imu_front = 2;
        int m_err_imu_central = 2;
        int m_err_imu_rear = 2;

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
        void carStatusChanged(int statusID); 

        void toggleCar();

        void CTRLEnabledChanged();
        void velocityChanged();
        void presetChanged();
};

#endif // CARSTATUSSIM_H


