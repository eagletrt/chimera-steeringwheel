#include "../header/carstatus.h"

CarStatus::CarStatus() {
    
    m_invRight = 2;
    m_invLeft = 2;
    m_preCharge = 2;

    m_ctrlIsEnabled = -1;
    
    m_ctrlIsOn = 0;
    
    m_car_status = CAR_STATUS_IDLE;

    m_stateofcharge = -1;
    m_temperature = -1;

    m_err_apps = 2;
    m_err_bse = 2;
    m_err_steer = 2;
    m_err_wheel_left = 2;
    m_err_wheel_right = 2;
    m_err_gps = 2;
    m_err_imu_front = 2;
    m_err_imu_central = 2;
    m_err_imu_rear = 2;

    m_invr = 2;
    m_invl = 2;
    m_front = 2;
    m_central = 2;
    m_pedals = 2;
    m_rear = 2;
    m_lv = 2;
    m_hv = 2;

    m_km = 999;
    m_velocity = 0;
    m_preset = 1;
    m_pump = 6;

    m_apps = 0;
    m_bse = 0;
    m_steer = 50;

    m_invSxTemp = 0;
    m_invDxTemp = 0;

    m_hvTemp = 0;
    m_hvVolt = 0;
    // m_lvVoltVal = 120;
    m_lvVolt = 0; 
    m_lvTemp = 0; 
    m_speed = 100;

    m_brakeVal = 100;
    m_throttleVal = 100;

    speedPrescaler = 8;
    pedalsPrescaler = 6;
    counterSpeed = 0;
    counterThrottle = 0;
    counterBrake = 0;   

    LVPrescaler = 10;
    counterLV = 0;
    invRightPrescaler = 10;
    counterInvRight = 0;
    invLeftPrescaler = 10;
    counterInvLeft = 0;
    
    for(int i = 0 ; i < 12; i++){
        telemetry[i] = 2;
    }
    sender = false;
    telemetryEnStatus = 0; //0 off, 1 is setting up, 2 setted

}

// Set Left Inverter Temperature and emit Property
void CarStatus::setLeftInverterTemperature(int val1, int val2){
    counterInvLeft++;
    if(counterInvLeft >= invLeftPrescaler){
        m_invSxTemp = (((val1 + (val2 * 256.0f) ) - 15797.0f ) / 112.1182f) * 10.0f;
        counterInvLeft = 0;

        emit invSxTempChanged();     
    }
}

// Set Right Inverter Temperature and emit Property
void CarStatus::setRightInverterTemperature(int val1, int val2){
    counterInvRight++;
    if(counterInvRight >= invRightPrescaler){
        m_invDxTemp = (((val1 + (val2 * 256.0f) ) - 15797.0f ) / 112.1182f) * 10.0f;
        counterInvRight = 0;

        emit invDxTempChanged();     
    }
}

// Set Speed and emit Property
void CarStatus::setSpeed(int id, int val1, int val2, int prescaler){
    counterSpeed++;
    speedPrescaler = prescaler;
    //0x07 encoder sinistro in teoria
    if(id == 0x06){
        if(counterSpeed >= pedalsPrescaler){
            counterSpeed = 0;
            m_speed = ((uint8_t)val1 * 256 + (uint8_t)val2);
            
            emit speedChanged();
        }
    }    

}

// Set Km and emit Property
void CarStatus::setKm(int meter1, int meter2){
    m_km = (((uint8_t)meter1 << 8 ) + (uint8_t)meter2);

    emit kmChanged();
    
}

// Set Pedals Prescaler to Slow Down 
void CarStatus::setPedalsPrescaler(int prescaler){
    pedalsPrescaler = prescaler;
}

// Set Brake value and emit Property, it use prescaler
void CarStatus::setBrake(int val){
    counterBrake++;
    if(counterBrake >= pedalsPrescaler){
        counterBrake = 0;
        m_brakeVal = ( (int) val );
        
        emit brakeValChanged();
    }    
}

// Set Throttle value and emit Property, it use prescaler
void CarStatus::setThrottle(int val){
    counterThrottle++;

    if(counterThrottle >= pedalsPrescaler){

        counterThrottle = 0;
        m_throttleVal = ( (int) val);
        int currPercMap = 0;
        
        switch(getMap() + 1){
            
            case 1: currPercMap = -20; break;
            case 2: currPercMap = 20; break;
            case 3: currPercMap = 40; break;
            case 4: currPercMap = 60; break;
            case 5: currPercMap = 80; break;
            case 6: currPercMap = 100; break;
            default: currPercMap = -100; break;
        }
        // m_velocity = (80.0 * currPercMap * m_throttleVal) / 10000.0;
        
        // emit velocityChanged();
        emit throttleValChanged();
    }    
}

// Set LV temp,volt value and emit Property, without prescaler
void CarStatus::setLVStatus(uint8_t val1, uint8_t val3){
    
    counterLV++;
    //before uint8_t val2 as a m_lvVal
    m_lvVolt = val1;
    m_lvTemp = val3;
    
    if(counterLV >= LVPrescaler){
        counterLV = 0;
        emit lvTempChanged();
        emit lvVoltChanged();
    }
}

// Set HV temp,volt value and emit Property, without prescaler
void CarStatus::setHVStatus(uint8_t id, uint8_t val1, uint8_t val2, uint8_t val3, uint8_t val4, uint8_t val5, uint8_t val6, uint8_t val7){
    if(id == 0x01){
        m_hvVolt = ((val1 << 16) + (val2 << 8) + val3 ) / 1000;
        // i due byte dopo sono max e min
        emit hvVoltChanged();
    }
    if(id == 0x0A){
        m_hvTemp = ((val1 << 8) + val2 ) / 10;
        // i due byte dopo sono max e min
        emit hvTempChanged();
    }
    if(id == 0x05){
        m_velocity = ((val4 << 8) + val5) / 1000;        
        emit velocityChanged();        
    }
}
// Set the value for the Pump 
void CarStatus::changePump(int pumpID) {

    if (pumpID != LOOP_THROUGH_PUMPS) {
        m_pump = pumpID;
    } else {
        // Loop through presents from 1 to 8 --> Case Single Button for Preset change
        m_pump += 1;
        m_pump = m_pump > PUMP_NUMBER ? m_pump % PUMP_NUMBER : m_pump;
    }
    //emit pumpChanged();
}

// Set the value for the Map 
void CarStatus::changePreset(int presetID) {

    if (presetID != LOOP_THROUGH_PRESETS) {
        // Change preset to presetID --> Case Hardware Wiper
        m_preset = presetID;
    } else {
        // Loop through presents from 1 to 8 --> Case Single Button for Preset change
        m_preset += 1;
        m_preset = m_preset > PRESET_NUMBER ? m_preset % PRESET_NUMBER : m_preset;
    }

    //qDebug() << "New Preset: " << m_preset;

    emit presetChanged();
}

// Return Can-bus Status value
QString CarStatus::CANStatus() const {
    // qDebug() << "Asked CanStatus";
    return QString("%1%2%3%4%5%6%7%8").arg(QString::number(m_invr),
                                       QString::number(m_invl),
                                       QString::number(m_front),
                                       QString::number(m_central),
                                       QString::number(m_pedals),
                                       QString::number(m_rear),
                                       QString::number(m_lv),
                                       QString::number(m_hv));
}
// Return Telemetry Status value

QString CarStatus::TelemetryStatus() const {
    qDebug() << "Asked Telemetry Status";
    QString telemetryText =  QString::number(telemetry[0])+
                    QString::number(telemetry[1])+
                    QString::number(telemetry[2])+
                    QString::number(telemetry[3])+
                    QString::number(telemetry[4])+
                    QString::number(telemetry[5])+
                    QString::number(telemetry[6])+
                    QString::number(telemetry[7])+
                    QString::number(telemetry[8])+
                    QString::number(telemetry[9])+
                    QString::number(telemetry[10]);
    return telemetryText;
}

int CarStatus::TelemetryEnabledStatus() const {
    return telemetryEnStatus;
}

QByteArray CarStatus::getTelemetryStatus() {
    QByteArray t;
    t.resize(8);
    qDebug() << TelemetryStatus();
    t[0] = 0xF;
    t[1] = (telemetry[0] << 6) + 
           (telemetry[1] << 4) +
           (telemetry[2] << 2) +
           (telemetry[3]);
    t[2] = (telemetry[4] << 6) + 
           (telemetry[5] << 4) +
           (telemetry[6] << 2) +
           (telemetry[7]);
    t[3] = (telemetry[8] << 6) + 
           (telemetry[9] << 4) +
           (telemetry[10] << 2);
    return t;
}

QByteArray CarStatus::getTelemetryEnabledStatus() {
    QByteArray t;
    t.resize(8);
    qDebug() << "Asking telemetry to set up";
    t[0] = 0x1;
    t[1] = telemetryEnStatus;
    return t;
}

bool CarStatus::getSender() {
    return sender;
}

void CarStatus::setSender() {
    sender == false ? sender = true : sender = false;
    qDebug() << "Invio:" << sender;
}

// Return HV Status value
QString CarStatus::HVStatus() const {
    // qDebug() << "Asked HVStatus";
    return QString("%1%2%3").arg(QString::number(m_preCharge),
                                 QString::number(m_invLeft),
                                 QString::number(m_invRight));
}

// Return Error Status value
QString CarStatus::ERRStatus() const {
    // qDebug() << "Asked ERRStatus";
    return QString("%1%2%3%4%5%6%7%8%9")
        .arg(QString::number(m_err_apps),
             QString::number(m_err_bse),
             QString::number(m_err_wheel_left),
             QString::number(m_err_wheel_right),
             QString::number(m_err_steer),
             QString::number(m_err_imu_front),
             QString::number(m_err_gps),
             QString::number(m_err_imu_central),
             QString::number(m_err_imu_rear));
}

// ???
int CarStatus::getBit(unsigned char seq, int index){
    return (int)(seq >> index) & 1U;
}

QList<int> CarStatus::APPSStatus() const {
    QList<int> appsStatusArr;
    appsStatusArr.append((int) m_apps);
    for (int var = 0; var < 5; ++var) {
       appsStatusArr.append(CarStatus::getBit(m_num_err_apps,var));
    }
    return appsStatusArr;
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
    //qDebug() << "Asked CTRLEnabled";
    return QString::number(m_ctrlIsOn);
}

void CarStatus::setSTEERStatus(int steer){
    m_steer = steer;

    emit STEERStatusChanged();
}

void CarStatus::setAPPSBSEStatus(int apps,
                                 int bse){
    m_apps = apps;
    m_bse = bse;

    emit APPSStatusChanged();
    emit BSEStatusChanged();
}

void CarStatus::setERRStatus(int err_apps,
                             int err_bse,
                             int err_wheel_left,
                             int err_wheel_right,
                             int err_steer,
                             int err_imu_front,
                             int err_gps,
                             int err_imu_central,
                             int err_imu_rear) {

    m_err_apps = err_apps;
    m_err_bse = err_bse;
    m_err_steer = err_steer;
    m_err_gps = err_gps;
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
                             int central,
                             int pedals,
                             int rear,
                             int hv,
                             int lv) {
    m_invr = invr;
    m_invl = invl;
    m_front = front;
    m_rear = rear;
    m_lv = lv;
    m_hv = hv;
    m_central = central;
    m_pedals = pedals;

    emit CANStatusChanged();
}
void CarStatus::setTelemetryStatus(int bms_hv,
                                    int bms_lv,
                                    int gps,
                                    int imu_gyro,
                                    int imu_axel,
                                    int front_wheel_encoder,
                                    int steering,
                                    int throttle,
                                    int brake,
                                    int db,
                                    int mqtt) {
    telemetry[0] = bms_hv;
    telemetry[1] = bms_lv;
    telemetry[2] = gps;
    telemetry[3] = imu_gyro;
    telemetry[4] = imu_axel;
    telemetry[5] = front_wheel_encoder;
    telemetry[6] = steering;
    telemetry[7] = throttle;
    telemetry[8] = brake;
    telemetry[9] = db;
    telemetry[10]= mqtt;

    emit TelemetryStatusChanged();
}

void CarStatus::setTelemetryEnabledStatus(int status){
    telemetryEnStatus = status;
    emit TelemetryEnabledStatusChanged(status);
}

void CarStatus::stopMessage(int inverter){

    if (inverter == 0){
        m_invLeft = 0; 
    } 
    if (inverter == 1) {
        m_invRight = 0;
    }
    // Quando ricevo che sono in idle 
    if (inverter == 2) {
        m_invLeft = 0;
        m_invRight = 0;
        m_preCharge = 0;
    }

    emit HVStatusChanged();
}

void CarStatus::setHVStatus(int preCharge,
                            int invLeft,
                            int invRight) {
    m_invRight = invRight;
    m_invLeft = invLeft;
    m_preCharge = preCharge;

    emit HVStatusChanged();
}

int CarStatus::getCtrlIsEnabled() {
    return m_ctrlIsEnabled;
}

void CarStatus::setCarStatus(int ctrlIsEnabled,
                             int ctrlIsOn,
                             int driveModeEnabled,
                             int warning,
                             int error) {

    m_ctrlIsEnabled = ctrlIsEnabled;
    m_ctrlIsOn = ctrlIsOn;
    //m_warning = warning;
    //m_error = error;
    m_car_status = driveModeEnabled;
    
    emit execModeChanged(ctrlIsEnabled, ctrlIsOn, warning, error);
    emit carStatusChanged();
}

void CarStatus::setCarMode(int mode){
   m_car_status = mode;
   emit carStatusChanged();
}

void CarStatus::setWarning(int on) {
    m_warning = on;
    emit warningChanged();
}

void CarStatus::setError(int on) {
    m_error = on;
    emit errorChanged();
}

int CarStatus::carStatus() {
    return m_car_status;
}

int CarStatus::getCurrentStatus() {
    return m_car_status;
}

int CarStatus::getPump() {
    return m_pump - 1;
}

int CarStatus::getMap() {
    return m_preset - 1;
}

int CarStatus::stopCar() {
    qDebug() << "Stoppo la car!";
    m_car_status = CAR_STATUS_STOP;

    emit toggleCar();

    return m_car_status;
}

int CarStatus::toggleCarStatus() {
   switch(m_car_status){
      case CAR_STATUS_IDLE:
         qDebug() << "CAR_STATUS_IDLE -> CAR_STATUS_SETUP";
         // Change the status of the car
         m_car_status = CAR_STATUS_IDLE;
         // Send CAN request to the CTRL
         emit toggleCar();
         break;
      case CAR_STATUS_SETUP:
        qDebug() << "CAR_STATUS_SETUP -> CAR_STATUS_RUN";
        // Change the status of the car
        m_car_status = CAR_STATUS_SETUP;
        // Send CAN request to the CTRL
        emit toggleCar();
        break;
      case CAR_STATUS_RUN:
        qDebug() << "CAR_STATUS_RUN -> CAR_STATUS_SETUP";
        // Change the status of the car
        m_car_status = CAR_STATUS_RUN;
        // Send CAN request to the CTRL
        emit toggleCar();
        break;
    }

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
    if (m_car_status == CAR_STATUS_RUN) {
        m_ctrlIsOn = m_ctrlIsOn ? 0 : 1;
        emit CTRLEnabledChanged();
        return m_ctrlIsOn;
    }
    return -1;
}

bool CarStatus::setTelemetry(int index) {
    bool ret = false;
    if(index >= 0 && index < 11){
        telemetry[index] = (telemetry[index] + 1) % 3;
        ret = true;
    }
    return ret;
}


/*
    Functions to return all the m_values
*/

int CarStatus::pump() const {
    return m_pump;
}
int CarStatus::preset() const {
    return m_preset;
}
int CarStatus::velocity() const {
    return m_velocity;
}
int CarStatus::brakeVal() const {
    return m_brakeVal;
}
int CarStatus::throttleVal() const {
    return m_throttleVal;
}
int CarStatus::speed() const {
    return m_speed;
}
int CarStatus::km() const {
    return m_km;
}
int CarStatus::invSxTemp() const {
    return m_invSxTemp;
}
int CarStatus::invDxTemp() const {
    return m_invDxTemp;
}
int CarStatus::hvTemp() const {
    return m_hvTemp;
}
int CarStatus::lvTemp() const {
    return m_lvTemp;
}
int CarStatus::hvVolt() const {
    return m_hvVolt;
}
int CarStatus::lvVolt() const {
    return m_lvVolt;
}
int CarStatus::getCtrlIsOn() {
    return m_ctrlIsOn;
}
int CarStatus::warning() const {
    return m_warning;
}
int CarStatus::error() const {
    return m_error;
}

// Destroy, BOOM!
CarStatus::~CarStatus() {
    qDebug() << "Closing CarStatus...";
}


