#include "carstatusSim.h"

CarStatusSim::CarStatusSim() {
    qDebug() << "Car Status Init";

    m_invRight = 2;
    m_invLeft = 2;
    m_preCharge = 2;

    m_ctrlIsEnabled = -1;
    // Set control activated by default
    m_ctrlIsOn = 1; 
    // Set car in IDLE at startup
    m_car_status = CAR_STATUS_IDLE;

    m_stateofcharge = -1;
    m_temperature = -1;

    // CAN Statuses
    // 0. ERROR
    // 1. OK
    // 2. NOT RECEIVED

    m_invr = 2;
    m_invl = 2;
    m_front = 2;
    m_rear = 2;
    m_lv = 2;
    m_hv = 2;

    m_velocity = 0;
    m_preset = 1;
}

CarStatusSim::~CarStatusSim() {
    qDebug() << "Car Status Destroy";
}

void CarStatusSim::changePreset(int presetID) {
    /* Step for changing preset:
     * (this needs to be done, now it sends the presetChanged signal directly from hardware)
     * (Handle the case when you are in menu mode and you change preset)
     *
     * 1. Acknowledge change from hardware (the wiper has been moved from one position to another)
     * 2. Send the ECU a request to change the preset (this involves editing some parameters on the software)
     * 3. Wait for the ECU to ack and send back the result
     * 4. Send the signal to the GUI to change the preset
     *
     */

    qDebug() << "New Preset: " << presetID;

    m_preset = presetID;

    emit presetChanged();
}

int CarStatusSim::preset() const {
    return m_preset;
}

int CarStatusSim::velocity() const {
    qDebug() << "Asked velocity";
    return m_velocity;
}

void CarStatusSim::setSTEERStatus(int steer,
                                 int num_err_steer){
    m_steer = steer;
    m_num_err_steer = num_err_steer;
}

void CarStatusSim::setAPPSBSEStatus(int apps,
                                 int num_err_apps,
                                 int bse,
                                 int num_err_bse){
    m_apps = apps;
    m_num_err_apps = num_err_apps;
    m_bse = bse;
    m_num_err_bse = num_err_bse;
}

void CarStatusSim::setERRStatus(int err_apps,
                             int err_bse,
                             int err_steer,
                             int err_wheel_right,
                             int err_wheel_left,
                             int err_imu_front,
                             int err_imu_central,
                             int err_imu_rear) {

    m_err_apps = err_apps;
    m_err_bse = err_bse;
    m_err_steer = err_steer;
    m_err_wheel_right = err_wheel_left;
    m_err_wheel_left = err_wheel_right;
    m_err_imu_front = err_imu_front;
    m_err_imu_central = err_imu_central;
    m_err_imu_rear = err_imu_rear;
}

void CarStatusSim::setCANStatus(int invr,
                             int invl, 
                             int front, 
                             int rear, 
                             int lv, 
                             int hv) {
    m_invr = invr;
    m_invl = invl;
    m_front = front;
    m_rear = rear;
    m_lv = lv;
    m_hv = hv;
}

void CarStatusSim::setHVStatus(int preCharge,
                            int invRight, 
                            int invLeft) {
    m_invRight = invRight;
    m_invLeft = invLeft;
    m_preCharge = preCharge;
}

int CarStatusSim::getCtrlIsEnabled() {
    return m_ctrlIsEnabled;
}

int CarStatusSim::getCtrlIsOn() {
    return m_ctrlIsOn;
}

void CarStatusSim::setCarStatus(int ctrlIsEnabled,
                             int ctrlIsOn,
                             int driveModeEnabled,
                             int velocity,
                             int warning, 
                             int error) {

    m_ctrlIsEnabled = ctrlIsEnabled;
    m_ctrlIsOn = ctrlIsOn;
    m_warning = warning;
    m_error = error;
    m_car_status = driveModeEnabled;
    m_velocity = velocity;

    qDebug() << "CtrlIsEnabled: " << ctrlIsEnabled;
    qDebug() << "CtrlIsOn: " << ctrlIsOn;
    qDebug() << "DriveModeEnabled: " << driveModeEnabled;
    qDebug() << "Velocity: " << velocity;
    qDebug() << "Warning: " << warning;
    qDebug() << "error: " << error;

    emit execModeChanged(ctrlIsEnabled, ctrlIsOn, warning, error);
    emit velocityChanged();
    emit carStatusChanged(m_car_status);
}

int CarStatusSim::getCurrentStatus() {
    return m_car_status;
}

int CarStatusSim::stopCar() {
    qDebug() << "Yuuu! Stoppo la car!";
    m_car_status = CAR_STATUS_STOP;

    emit toggleCar();

    return m_car_status;
}

int CarStatusSim::toggleCarStatus() {
    if (m_car_status == CAR_STATUS_IDLE) {
        qDebug() << "CAR_STATUS_IDLE -> CAR_STATUS_GO";
        // Change the status of the car
        m_car_status = CAR_STATUS_GO;

        // Send CAN request to the CTRL
        emit toggleCar();
    } else {
        if (m_car_status == CAR_STATUS_GO) {
            qDebug() << "CAR_STATUS_GO -> CAR_STATUS_IDLE";
            m_car_status = CAR_STATUS_IDLE;

            emit toggleCar();
        }
    }

    return m_car_status;
}

void CarStatusSim::setStateOfCharge(int stateofcharge) {
    m_stateofcharge = stateofcharge;
    emit socChanged(stateofcharge);
}

void CarStatusSim::setTemperature(int temperature) {
    m_temperature = temperature;
    emit tempChanged(temperature);
}

int CarStatusSim::toggleCtrl() {
    // If the car is in run mode, toggle CTRL
    //if (m_car_status == CAR_STATUS_GO) {
    if (m_car_status == CAR_STATUS_GO) {
        m_ctrlIsOn = m_ctrlIsOn ? 0 : 1;
        emit CTRLEnabledChanged();
        return m_ctrlIsOn;
    }
    return -1;
}
