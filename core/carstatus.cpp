#include "../header/carstatus.h"

CarStatus::CarStatus() {

    //m_stateofcharge = -1; not used
    //m_temperature = -1; not used

    m_err_apps = 2;
    m_err_bse = 2;
    m_err_steer = 2;
    m_err_wheel_left = 2;
    m_err_wheel_right = 2;
    m_err_gps = 2;
    m_err_imu_front = 2;
    m_err_imu_central = 2;
    m_err_imu_rear = 2;

    //m_invr = 2; moved into warning
    //m_invl = 2; moved into warning
    //m_front = 2; moved into warning
    //m_central = 2; moved into warning
    //m_pedals = 2; moved into warning
    //m_rear = 2; moved into warning
    //m_lv = 2; moved into warning
    //m_hv = 2; moved into warning

    //m_km = 999; moved into race
    //m_velocity = 0; moved into race
    m_map = 1;
    m_pump = 6;
    m_tc = 1;

    m_apps = 0;
    m_bse = 0;
    m_steer = 50;

    //m_invSxTemp = 0; moved into inverters
    //m_invDxTemp = 0; moved into inverters

    m_hvTemp = 0;
    m_hvVolt = 0;
    m_lvVolt = 0; 
    m_lvTemp = 0; 
    //m_speed = 100; moved into race

    m_brakeVal = 100;
    m_throttleVal = 100;
    
    for(int i = 0 ; i < 11; i++){
        telemetry[i] = 2;
    }
    sender = false;
    telemetryEnStatus = 0; //0 off, 1 is setting up, 2 setted
    popup = 3; //Welcome
    
    QTimer *graphicTimer = new QTimer(this);
    connect(graphicTimer, SIGNAL(timeout()), this, SLOT(processingTimeout()));
    graphicTimer->start(GRAPHICTIMER);
}

void CarStatus::processingTimeout(){
    emit invSxTempChanged();
    emit invDxTempChanged();
    emit speedChanged();
    emit brakeValChanged();
    emit throttleValChanged();
    //emit velocityChanged();
    emit lvTempChanged();
    emit lvVoltChanged();
}

// Set Left Inverter Temperature and emit Property
void CarStatus::setLeftInverterTemperature(int val1, int val2){
    inverters.setLeftInverterTemperature(val1, val2);
}

// Set Right Inverter Temperature and emit Property
void CarStatus::setRightInverterTemperature(int val1, int val2){
    inverters.setRightInverterTemperature(val1, val2);
}

// Set Speed and emit Property
void CarStatus::setSpeed(int val1, int val2){
    //0x07 encoder sinistro in teoria
    race.setSpeed(val1, val2);
}

// Set Km and emit Property
void CarStatus::setKm(int meter1, int meter2){
    race.setKm(meter1, meter2);
    emit kmChanged();    
}

// Set Brake value 
void CarStatus::setBrake(int val){
    m_brakeVal = ( (int) val );
}

// Set Throttle value 
void CarStatus::setThrottle(int val){    
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
    //race.setVelocity(((80.0 * currPercMap * m_throttleVal) / 10000.0)); //remember to uncomment the velocityChanged emit on processingTimeout in order to emit the velocity
}

// Set LV temp,volt value
void CarStatus::setLVStatus(uint8_t val1, uint8_t val3){
    //before uint8_t val2 as a m_lvVal
    m_lvVolt = val1;
    m_lvTemp = val3;
}

// Set HV temp,volt value
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
        race.setVelocity(((val4 << 8) + val5) / 1000); 
        emit velocityChanged();        
    }
}

// Set the value for the Map 
void CarStatus::changeMap(int mapID) {

    if (mapID != LOOP_THROUGH_MAPS) {
        m_map = mapID;
    } else {
         m_map += 1;
        m_map = m_map > MAP_NUMBER ? m_map % MAP_NUMBER : m_map;
    }

    emit mapChanged();
}

// Set the value for the Pump 
void CarStatus::changePump(int pumpID) {

    if (pumpID != LOOP_THROUGH_PUMPS) {
        m_pump = pumpID;
    } else {
        m_pump += 1;
        m_pump = m_pump > PUMP_NUMBER ? m_pump % PUMP_NUMBER : m_pump;
    }
    //emit pumpChanged();
}

// Set the value for the Pump 
void CarStatus::changeTc(int tcID) {

    if (tcID != LOOP_THROUGH_TCS) {
        m_tc = tcID;
    } else {
        m_tc += 1;
        m_tc = m_tc > TC_NUMBER ? m_tc % TC_NUMBER : m_tc;
    }

    emit tcChanged();
}

// Return Can-bus Status value
QString CarStatus::CANStatus() const {
    // qDebug() << "Asked CanStatus";
    return QString("%1%2%3%4%5%6%7%8").arg(QString::number(warning.getInvRight()),
                                       QString::number(warning.getInvLeft()),
                                       QString::number(warning.getFront()),
                                       QString::number(warning.getCentral()),
                                       QString::number(warning.getPedals()),
                                       QString::number(warning.getRear()),
                                       QString::number(warning.getLv()),
                                       QString::number(warning.getHv()));
}
// Return Telemetry Status value

QString CarStatus::TelemetryStatus() const {
    qDebug() << "Asked Telemetry Status";
    return QString::number(telemetry[0])+
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
}

int CarStatus::TelemetryEnabledStatus() const {
    return telemetryEnStatus;
}

int CarStatus::SteeringWheelPopup() const {
    return this->popup;
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
    return QString("%1%2%3").arg(QString::number(inverters.getPreCharge()),
                                 QString::number(inverters.getLeftInverter()),
                                 QString::number(inverters.getRightInverter()));
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
    return QString::number(control.getCtrlIsEnabled());
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
    warning.setInvRight(invr);    
    warning.setInvLeft(invl);     
    warning.setFront(front);  
    warning.setRear(rear);
    warning.setLv(lv);
    warning.setHv(hv);
    warning.setCentral(central);
    warning.setPedals(pedals);

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
    emit TelemetryEnabledStatusChanged();
}

void CarStatus::setSteeringWheelPopup(int msg) { //Value to be showned

    this->popup = msg;

    emit SteeringWheelPopupChanged();
}

void CarStatus::stopMessage(int inverter){

    if (inverter == 0){
        inverters.setLeftInverter(0); 
    } 
    if (inverter == 1) {
        inverters.setRightInverter(0);
    }
    // Quando ricevo che sono in idle 
    if (inverter == 2) {
        inverters.setLeftInverter(0); 
        inverters.setRightInverter(0);
        inverters.setPreCharge(0);
    }

    emit HVStatusChanged();
}

void CarStatus::setHVStatus(int preCharge,
                            int invLeft,
                            int invRight) {

    inverters.setLeftInverter(invLeft); 
    inverters.setRightInverter(invRight);
    inverters.setPreCharge(preCharge);

    emit HVStatusChanged();
}

int CarStatus::getCtrlIsEnabled() {
    return this->control.getCtrlIsEnabled();
}

void CarStatus::setCarStatus(int ctrlIsEnabled,
                             int ctrlIsOn,
                             int driveModeEnabled,
                             int warning,
                             int error) {

    this->control.setCtrlIsEnabled(ctrlIsEnabled);
    this->control.setCtrlIsOn(ctrlIsOn);
    //this->warning.setWarning(warning);
    //m_error = error;
    this->control.setCarStatus(driveModeEnabled);
    
    emit execModeChanged(ctrlIsEnabled, ctrlIsOn, warning, error);
    emit carStatusChanged();
}

void CarStatus::setCarMode(int mode){
   this->control.setCarStatus(mode);
   emit carStatusChanged();
}

void CarStatus::setWarning(int on) {
    warning.setWarning(on);
    emit warningChanged();
}

void CarStatus::setError(int on) {
    m_error = on;
    emit errorChanged();
}

int CarStatus::carStatus() {
    return this->control.getCarStatus();
}

int CarStatus::getPump() {
    return m_pump - 1;
}

int CarStatus::getMap() {
    return m_map - 1;
}

int CarStatus::stopCar() {
    qDebug() << "Stoppo la car!";
    this->control.setCarStatus(CAR_STATUS_STOP);

    emit toggleCar();

    return this->control.getCarStatus();;
}

int CarStatus::toggleCarStatus() {
   switch(this->control.getCarStatus()){
      case CAR_STATUS_IDLE:
         qDebug() << "CAR_STATUS_IDLE -> CAR_STATUS_SETUP";
         // Change the status of the car
         this->control.setCarStatus(CAR_STATUS_IDLE);
         // Send CAN request to the CTRL
         emit toggleCar();
         break;
      case CAR_STATUS_SETUP:
        qDebug() << "CAR_STATUS_SETUP -> CAR_STATUS_RUN";
        // Change the status of the car
        this->control.setCarStatus(CAR_STATUS_SETUP);
        // Send CAN request to the CTRL
        emit toggleCar();
        break;
      case CAR_STATUS_RUN:
        qDebug() << "CAR_STATUS_RUN -> CAR_STATUS_SETUP";
        // Change the status of the car
        this->control.setCarStatus(CAR_STATUS_RUN);
        // Send CAN request to the CTRL
        emit toggleCar();
        break;
    }

    return control.getCarStatus();
}
// Is not used
//void CarStatus::setStateOfCharge(int stateofcharge) {
//    m_stateofcharge = stateofcharge;
//    emit socChanged(stateofcharge);
//}

//Is not used
//void CarStatus::setTemperature(int temperature) {
//    m_temperature = temperature;
//    emit tempChanged(temperature);
//}

//This is not used
int CarStatus::toggleCtrl() {
    if (this->control.setCarStatus(CAR_STATUS_RUN)) {
        this->control.setCtrlIsOn(!this->control.getCtrlIsOn());
        
        emit CTRLEnabledChanged();
        return this->control.getCtrlIsOn();
    }
    return -1;
}

bool CarStatus::setTelemetry(int index) {
    bool ret = false;
    if(index >= 0 && index < 11){
        telemetry[index] = (telemetry[index] + 1) % 2;
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
int CarStatus::map() const {
    return m_map;
}
int CarStatus::tc() const {
    return m_tc;
}
int CarStatus::velocity() const {
    return race.getVelocity();
}
int CarStatus::brakeVal() const {
    return m_brakeVal;
}
int CarStatus::throttleVal() const {
    return m_throttleVal;
}
int CarStatus::speed() const {
    return race.getSpeed();
}
int CarStatus::km() const {
    return race.getKm();
}
int CarStatus::invSxTemp() const {
    return inverters.getLeftInverterTemperature();
}
int CarStatus::invDxTemp() const {
    return inverters.getRightInverterTemperature();
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
    return this->control.getCtrlIsOn();
}
int CarStatus::getWarning() const {
    return warning.getWarning();
}
int CarStatus::error() const {
    return m_error;
}

// Destroy, BOOM!
CarStatus::~CarStatus() {
    qDebug() << "Closing CarStatus...";
}
