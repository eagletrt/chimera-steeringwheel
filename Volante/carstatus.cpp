#include "carstatus.h"

CarStatus::CarStatus() {
    qDebug() << "Car Status Init";

    m_invRight = 2;
    m_invLeft = 2;
    m_preCharge = 2;

    m_ctrlIsEnabled = -1;
    // Set control activated by default
    m_ctrlIsOn = 0;
    // Set car in IDLE at startup
    m_car_status = CAR_STATUS_IDLE;

    m_stateofcharge = -1;
    m_temperature = -1;

    // CAN Statuses
    // 0. ERROR
    // 1. OK
    // 2. NOT RECEIVED

    m_err_apps = 2;
    m_err_bse = 2;
    m_err_steer = 2;
    m_err_wheel_right = 2;
    m_err_wheel_left = 2;
    m_err_imu_front = 2;
    m_err_imu_central = 2;
    m_err_imu_rear = 2;

    m_invr = 2;
    m_invl = 2;
    m_front = 2;
    m_rear = 2;
    m_lv = 2;
    m_hv = 2;

    m_velocity = 75;
    m_preset = 1;

    m_apps = 0;
    m_num_err_apps = 0;
    m_bse = 0;
    m_num_err_bse = 0;
    m_steer = 50;
    m_num_err_steer = 0;
}

CarStatus::~CarStatus() {
    qDebug() << "Car Status Destroy";
}

void CarStatus::changePreset(int presetID) {
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

    qDebug() << "Preset to change: " << presetID;

    if (presetID != LOOP_THROUGH_PRESETS) {
        // Change preset to presetID --> Case Hardware Wiper
        m_preset = presetID;
    } else {
        // Loop through presents from 1 to 8 --> Case Single Button for Preset change
        m_preset += 1;
        qDebug() << m_preset;
        m_preset = m_preset > PRESET_NUMBER ? m_preset % PRESET_NUMBER : m_preset;
        qDebug() << m_preset;
    }

    qDebug() << "New Preset: " << m_preset;

    emit presetChanged();
}

int CarStatus::preset() const {
    return m_preset;
}

int CarStatus::velocity() const {
    qDebug() << "Asked velocity";
    return m_velocity;
}

QString CarStatus::CANStatus() const {
    qDebug() << "Asked CanStatus";
    return QString("%1%2%3%4%5%6").arg(QString::number(m_invr),
                                       QString::number(m_invl),
                                       QString::number(m_front),
                                       QString::number(m_rear),
                                       QString::number(m_lv),
                                       QString::number(m_hv));
}

QString CarStatus::HVStatus() const {
    qDebug() << "Asked HVStatus";
    return QString("%1%2%3").arg(QString::number(m_preCharge),
                                 QString::number(m_invRight),
                                 QString::number(m_invLeft));
}

QString CarStatus::ERRStatus() const {
    qDebug() << "Asked ERRStatus";
    return QString("%1%2%3%4%5%6%7%8")
        .arg(QString::number(m_err_apps),
             QString::number(m_err_bse),
             QString::number(m_err_steer),
             QString::number(m_err_wheel_left),
             QString::number(m_err_wheel_right),
             QString::number(m_err_imu_front),
             QString::number(m_err_imu_central),
             QString::number(m_err_imu_rear));
}

QList<int> CarStatus::APPSStatus() const {
    QList<int> appsStatusArr;
    appsStatusArr.append((int) m_apps);
    for (int var = 0; var < 5; ++var) {
       appsStatusArr.append(CarStatus::getBit(m_num_err_apps,var));
    }
    return appsStatusArr;
}

int CarStatus::getBit(unsigned char seq, int index){
    return (int)(seq >> index) & 1U;
}

QList<int> CarStatus::BSEStatus() const {
    QList<int> bseStatusArr;
    bseStatusArr.append((int) m_bse);
    for (int var = 0; var < 4; ++var) {
       bseStatusArr.append(CarStatus::getBit(m_num_err_bse,var));
    }
    return bseStatusArr;
}

QList<int> CarStatus::STEERStatus() const {
    QList<int> steerStatusArr;
    steerStatusArr.append((int) m_steer);
    steerStatusArr.append(CarStatus::getBit(m_num_err_steer,0));
    return steerStatusArr;
}

QString CarStatus::CTRLEnabled() const {
    qDebug() << "Asked CTRLEnabled";
    return QString::number(m_ctrlIsOn);
}

void CarStatus::setSTEERStatus(int steer,
                                 int num_err_steer){
    m_steer = steer;
    m_num_err_steer = num_err_steer;

    emit STEERStatusChanged();
}

void CarStatus::setAPPSBSEStatus(int apps,
                                 int num_err_apps,
                                 int bse,
                                 int num_err_bse){
    m_apps = apps;
    m_num_err_apps = num_err_apps;
    m_bse = bse;
    m_num_err_bse = num_err_bse;

    emit APPSStatusChanged();
    emit BSEStatusChanged();
}

void CarStatus::setERRStatus(int err_apps,
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

    emit ERRStatusChanged();
}

void CarStatus::setCANStatus(int invr,
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

    emit CANStatusChanged();
}

void CarStatus::setHVStatus(int preCharge,
                            int invRight,
                            int invLeft) {
    m_invRight = invRight;
    m_invLeft = invLeft;
    m_preCharge = preCharge;

    emit HVStatusChanged();
}

int CarStatus::getCtrlIsEnabled() {
    return m_ctrlIsEnabled;
}

int CarStatus::getCtrlIsOn() {
    return m_ctrlIsOn;
}

void CarStatus::setCarStatus(int ctrlIsEnabled,
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

int CarStatus::getCurrentStatus() {
    return m_car_status;
}

int CarStatus::getMap() {
    // TODO: Uniform RIO map numbering with UI map numbering
    // RIO 0..7 UI 1..8
    return m_preset - 1;
}

int CarStatus::stopCar() {
    qDebug() << "Yuuu! Stoppo la car!";
    m_car_status = CAR_STATUS_STOP;

    emit toggleCar();

    return m_car_status;
}

int CarStatus::toggleCarStatus() {
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

    // *************
    // *************
    // DEBUG ONLY!!!
    // *************
    // *************
    //emit carStatusChanged(m_car_status);

    return m_car_status;
}

void CarStatus::setStateOfCharge(int stateofcharge) {
    m_stateofcharge = stateofcharge;
    emit socChanged(stateofcharge);
}

void CarStatus::setTemperature(int temperature) {
    m_temperature = temperature;
    emit tempChanged(temperature);
}

int CarStatus::toggleCtrl() {
    // If the car is in run mode, toggle CTRL
    //if (m_car_status == CAR_STATUS_GO) {
    if (m_car_status == CAR_STATUS_GO) {
        m_ctrlIsOn = m_ctrlIsOn ? 0 : 1;
        emit CTRLEnabledChanged();
        return m_ctrlIsOn;
    }
    return -1;
}
