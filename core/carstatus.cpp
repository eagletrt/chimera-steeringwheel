#include "../header/carstatus.h"

CarStatus::CarStatus() {

    //m_speed = 100; moved into race
    
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
    sensors.setBrakeVal((int) val);
}

// Set Throttle value 
void CarStatus::setThrottle(int val){    
    sensors.setThrottleVal((int) val);
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
    lv.setLvVolt(val1);
    lv.setLvTemp(val3);
}

// Set HV temp,volt value
void CarStatus::setHVStatus(uint8_t id, uint8_t val1, uint8_t val2, uint8_t val3, uint8_t val4, uint8_t val5, uint8_t val6, uint8_t val7){
    if(id == 0x01){
        hv.setHvVoltage(val1, val2, val3);
        // i due byte dopo sono max e min
        emit hvVoltChanged();
    }
    if(id == 0x0A){
        hv.setHvTemperature(val1, val2);
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
        manettini.setMap(mapID);
    } else {
        //m_map = m_map > MAP_NUMBER ? m_map % MAP_NUMBER : m_map;
        manettini.incMap(MAP_NUMBER);
    }

    emit mapChanged();
}

// Set the value for the Pump 
void CarStatus::changePump(int pumpID) {

    if (pumpID != LOOP_THROUGH_PUMPS) {
        manettini.setPump(pumpID);
    } else {
        manettini.incPump(PUMP_NUMBER);
    }
    //emit pumpChanged();
}

// Set the value for the Pump 
void CarStatus::changeTc(int tcID) {

    if (tcID != LOOP_THROUGH_TCS) {
        manettini.setTc(tcID);
    } else {
        manettini.incTc(TC_NUMBER);
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
    return QString::number(telemetry.getTelemetry(0))+
           QString::number(telemetry.getTelemetry(1))+
           QString::number(telemetry.getTelemetry(2))+
           QString::number(telemetry.getTelemetry(3))+
           QString::number(telemetry.getTelemetry(4))+
           QString::number(telemetry.getTelemetry(5))+
           QString::number(telemetry.getTelemetry(6))+
           QString::number(telemetry.getTelemetry(7))+
           QString::number(telemetry.getTelemetry(8))+
           QString::number(telemetry.getTelemetry(9))+
           QString::number(telemetry.getTelemetry(10)]);
}

int CarStatus::TelemetryEnabledStatus() const {
    return telemetry.getTelemetryStatus();
}

int CarStatus::SteeringWheelPopup() const {
    return telemetry.getPopupMessage();
}

QByteArray CarStatus::getTelemetryStatus() {
    QByteArray t;
    t.resize(8);
    qDebug() << TelemetryStatus();
    t[0] = 0xF;
    t[1] = (telemetry.getTelemetry(0) << 6) + 
           (telemetry.getTelemetry(1) << 4) +
           (telemetry.getTelemetry(2) << 2) +
           (telemetry.getTelemetry(3));
    t[2] = (telemetry.getTelemetry(4) << 6) + 
           (telemetry.getTelemetry(5) << 4) +
           (telemetry.getTelemetry(6) << 2) +
           (telemetry.getTelemetry(7));
    t[3] = (telemetry.getTelemetry(8) << 6) + 
           (telemetry.getTelemetry(9) << 4) +
           (telemetry.getTelemetry(10) << 2);
    return t;
}

QByteArray CarStatus::getTelemetryEnabledStatus() {
    QByteArray t;
    t.resize(8);
    qDebug() << "Asking telemetry to set up";
    t[0] = 0x1;
    t[1] = telemetry.getTelemetryStatus();
    return t;
}

bool CarStatus::getSender() {
    return telemetry.getSender();
}

void CarStatus::setSender() {
    telemetry.setSender();
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
        .arg(QString::number(errors.getErrApps()),
             QString::number(errors.getErrBse()),
             QString::number(errors.getErrLeftWheel()),
             QString::number(errors.getErrRightWheel()),
             QString::number(errors.getErrSteer()),
             QString::number(errors.getErrFrontIMU()),
             QString::number(errors.getErrGPS()),
             QString::number(errors.getErrCentralIMU()),
             QString::number(errors.getErrRearIMU()));
}

// ???
int CarStatus::getBit(unsigned char seq, int index){
    return (int)(seq >> index) & 1U;
}

QList<int> CarStatus::APPSStatus() const {
    QList<int> appsStatusArr;
    appsStatusArr.append((int) sensors.getApps());
    for (int var = 0; var < 5; ++var) {
       appsStatusArr.append(CarStatus::getBit(sensors.getNumErrApps(), var));
    }
    return appsStatusArr;
}

QList<int> CarStatus::BSEStatus() const {
    QList<int> bseStatusArr;
    bseStatusArr.append((int) sensors.getBse());
    for (int var = 0; var < 4; ++var) {
       bseStatusArr.append(CarStatus::getBit(sensors.getNumErrBse(), var));
    }
    return bseStatusArr;
}

QList<int> CarStatus::STEERStatus() const {
    QList<int> steerStatusArr;
    steerStatusArr.append((int) sensors.getNumErrSteer());
    steerStatusArr.append(CarStatus::getBit(sensors.getNumErrSteer(), 0));
    return steerStatusArr;
}

QString CarStatus::CTRLEnabled() const {
    //qDebug() << "Asked CTRLEnabled";
    return QString::number(control.getCtrlIsEnabled());
}

void CarStatus::setSTEERStatus(int steer){
    sensors.setSteer(steer);

    emit STEERStatusChanged();
}

void CarStatus::setAPPSBSEStatus(int apps,
                                 int bse){
    sensors.setApps(apps);
    sensors.setBse(bse);

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

    errors.setAll(err_apps, err_bse, err_steer, err_wheel_left,
                  err_wheel_right, err_gps, err_imu_front,
                  err_imu_central, err_imu_rear);

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
    telemetry.setTelemetry(
        bms_hv,
        bms_lv,
        gps,
        imu_gyro,
        imu_axel,
        front_wheel_encoder,
        steering,
        throttle,
        brake,
        db,
        mqtt
    );

    emit TelemetryStatusChanged();
}

void CarStatus::setTelemetryEnabledStatus(int status){
    telemetry.setTelemetryStatus(status);
    emit TelemetryEnabledStatusChanged();
}

void CarStatus::setSteeringWheelPopup(int msg) { //Value to be showned
    telemetry.setPopupMessage(msg);
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
    return control.getCtrlIsEnabled();
}

void CarStatus::setCarStatus(int ctrlIsEnabled,
                             int ctrlIsOn,
                             int driveModeEnabled,
                             int warning,
                             int error) {

    control.setCtrlIsEnabled(ctrlIsEnabled);
    control.setCtrlIsOn(ctrlIsOn);
    //this->warning.setWarning(warning);
    //m_error = error;
    control.setCarStatus(driveModeEnabled);
    
    emit execModeChanged(ctrlIsEnabled, ctrlIsOn, warning, error);
    emit carStatusChanged();
}

void CarStatus::setCarMode(int mode){
   control.setCarStatus(mode);
   emit carStatusChanged();
}

void CarStatus::setWarning(int on) {
    warning.setWarning(on);
    emit warningChanged();
}

void CarStatus::setError(int on) {
    errors.setError(on);
    emit errorChanged();
}

int CarStatus::carStatus() {
    return control.getCarStatus();
}

int CarStatus::getPump() {
    manettini.setPump(manettini.getPump() - 1);    
    return manettini.getPump();
}

int CarStatus::getMap() {
    manettini.setMap(manettini.getMap() - 1);
    return manettini.getMap();
}

int CarStatus::stopCar() {
    qDebug() << "Stoppo la car!";
    control.setCarStatus(CAR_STATUS_STOP);

    emit toggleCar();

    return control.getCarStatus();;
}

int CarStatus::toggleCarStatus() {
   switch(control.getCarStatus()){
      case CAR_STATUS_IDLE:
         qDebug() << "CAR_STATUS_IDLE -> CAR_STATUS_SETUP";
         // Change the status of the car
         control.setCarStatus(CAR_STATUS_IDLE);
         // Send CAN request to the CTRL
         emit toggleCar();
         break;
      case CAR_STATUS_SETUP:
        qDebug() << "CAR_STATUS_SETUP -> CAR_STATUS_RUN";
        // Change the status of the car
        control.setCarStatus(CAR_STATUS_SETUP);
        // Send CAN request to the CTRL
        emit toggleCar();
        break;
      case CAR_STATUS_RUN:
        qDebug() << "CAR_STATUS_RUN -> CAR_STATUS_SETUP";
        // Change the status of the car
        control.setCarStatus(CAR_STATUS_RUN);
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
    if (control.setCarStatus(CAR_STATUS_RUN)) {
        control.setCtrlIsOn(!control.getCtrlIsOn());
        
        emit CTRLEnabledChanged();
        return control.getCtrlIsOn();
    }
    return -1;
}

bool CarStatus::setTelemetry(int index) {
    bool ret = false;
    if(index >= 0 && index < 11){

        telemetry.setTelemetryIndex(index);
        ret = true;
    }
    return ret;
}

/*
    Functions to return all the m_values
*/

int CarStatus::pump() const {
    return manettini.getPump();
}
int CarStatus::map() const {
    return manettini.getMap();
}
int CarStatus::tc() const {
    return manettini.getTc();
}
int CarStatus::velocity() const {
    return race.getVelocity();
}
int CarStatus::brakeVal() const {
    return sensors.getBrakeVal();
}
int CarStatus::throttleVal() const {
    return sensors.getThrottleVal();
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
    return hv.getHvTemperature();
}
int CarStatus::lvTemp() const {
    return lv.getLvTemp();
}
int CarStatus::hvVolt() const {
    return hv.getHvVoltage();
}
int CarStatus::lvVolt() const {
    return lv.getLvVolt();
}
int CarStatus::getCtrlIsOn() {
    return this->control.getCtrlIsOn();
}
int CarStatus::getWarning() const {
    return warning.getWarning();
}
int CarStatus::error() const {
    return errors.getError();
}

// Destroy, BOOM!
CarStatus::~CarStatus() {
    qDebug() << "Closing CarStatus...";
}
