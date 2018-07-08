#include "canbus.h"
#include <QDebug>
#include <QFileInfo>

QCanBusDevice *device;

Canbus::Canbus(CarStatus* m_carStatus, const QString can_interface) {


   //Right Can for 5.10.1 RPI

   QString errorString;
   device = QCanBus::instance()->createDevice(
       QStringLiteral("socketcan"), QStringLiteral("vcan0"), &errorString);
   if (!device)
       qDebug() << "NO CAN!";
   else
       device->connectDevice();

/*
    foreach (const QByteArray &backend, QCanBus::instance()->plugins()) {
      if (backend == can_interface) {
        qDebug() << "Socketcan Found";
        break;
      }
    }

    device = QCanBus::instance()->createDevice("socketcan", QStringLiteral("vcan0"));
    device->connectDevice();
*/
    carStatus = m_carStatus;

    qDebug() << "CAN Interface Init";

    timerSteeringWheel = new QTimer(this);
    timerStatus = new QTimer(this);

    // Setup signal/slot mechanism
    connect(timerSteeringWheel, SIGNAL(timeout()),
            this, SLOT(steerConnected()));

    connect(timerStatus, SIGNAL(timeout()),
            this, SLOT(askStatus()));

    connect(device, SIGNAL(framesReceived()),
            this, SLOT(parseSerial()));

    connect(carStatus, SIGNAL(toggleCar()),
            this, SLOT(toggleCar()));

    connect(carStatus, SIGNAL(CTRLEnabledChanged()),
            this, SLOT(toggleCar()));

    timerSteeringWheel->start(10);
    timerStatus->start(1000);


    invLeftState = -1;
    invRightState = -1;
    preChargeState = -1;

    error = -1;
    warning = -1;
    velocity = -1;

    idIsArrived = 0;

    m_hvTemp = 70;
    m_hvVolt = 120;
    m_lvVolt = 120;
    m_lvTemp = 30;

    m_brakeVal = 10;
    m_throttleVal = 10;

    m_actuatorRangePendingFlag = 0;
}

void Canbus::steerConnected() {
   QByteArray connected;
   connected.resize(8);
   connected[0] = 1;
   sendCanMessage(STEERING_WHEEL_ID,connected);
}

void Canbus::askStatus() {
   QByteArray askErrors;
   QByteArray askWarnings;
   askErrors.resize(8);
   askWarnings.resize(8);
   askErrors[0] = ECU_ERRORS;
   askWarnings[0] = ECU_WARNINGS;
   sendCanMessage(ECU_MSG,askErrors);
   sendCanMessage(ECU_MSG,askWarnings);
}

int Canbus::actuatorRangePendingFlag() const {
  qDebug() << m_actuatorRangePendingFlag << "Asked m_actuatorRangePendingFlag";
  return m_actuatorRangePendingFlag;
}

void Canbus::checkSensorsError() {
    QByteArray vuoto;
    qDebug() << "CheckSensorsError";
    sendCanMessage(CHECK_SENSOR_ERROR_ID, vuoto);
}

void Canbus::checkCANCommunication(bool isOk = false) {
  QByteArray check;
  check.resize(8);
    if (isOk) {
      check[0] = 1;
      sendCanMessage(CHECK_CAN_COM, check);
    } else {
      check[0] = 0;
      sendCanMessage(CHECK_CAN_COM, check);
    }
}

void Canbus::parseCANMessage(int mid, QByteArray msg) {
    // State machine for parsing the CAN Msg and giving
    // back the correct signal
    switch (mid) {





        case GET_APPS_BSE_STATUS:
            qDebug() << "APPS State: ";
            qDebug() << "APPS: " << QString::number(msg.at(0));
            qDebug() << "err APPS: " << QString::number(msg.at(1));
            qDebug() << "BSE State: ";
            qDebug() << "BSE: " << QString::number(msg.at(2));
            qDebug() << "err BSE: " << QString::number(msg.at(3));

            carStatus->setAPPSBSEStatus(msg.at(0),
                                    msg.at(1),
                                    msg.at(2),
                                    msg.at(3));
        break;



        case STM_PEDALS:
            qDebug() << "Throttle: " << QString::number(msg.at(0));
            qDebug() << "Brake: " << QString::number(msg.at(1));

            if (msg.at(0) == 0x02){
               m_brakeVal = ( (int) msg.at(1) );
            }else{
               m_throttleVal = ( (int) msg.at(1));
            }

            emit brakeValChanged();
            emit throttleValChanged();

            break;
        case GET_ACTUATORS_RANGE_ACK:
            switch (msg.at(0)) {
                case 0:
                    if (msg.at(1) == 0){
                        //APPS min
                        qDebug() << "ACTUATORS_RANGE_ACK for APPS min";

                        m_actuatorRangePendingFlag = 2;
                        qDebug() << "set m_actuatorRangePendingFlag = 2";
                        emit actuatorRangePendingFlagCleared();
                    }
                    else if (msg.at(1) == 1){
                        //APPS max
                        qDebug() << "ACTUATORS_RANGE_ACK for APPS max";

                        m_actuatorRangePendingFlag = 3;
                        qDebug() << "set m_actuatorRangePendingFlag = 3";
                        emit actuatorRangePendingFlagCleared();
                      }
                    break;
                case 1:
                    if (msg.at(1) == 0){
                        //BSE min
                        qDebug() << "ACTUATORS_RANGE_ACK for BSE min";

                        m_actuatorRangePendingFlag = 5;
                        qDebug() << "set m_actuatorRangePendingFlag = 5";
                        emit actuatorRangePendingFlagCleared();
                    }
                    else if (msg.at(1) == 1){
                        //BSE max
                        qDebug() << "ACTUATORS_RANGE_ACK for BSE max";

                        m_actuatorRangePendingFlag = 6;
                        qDebug() << "set m_actuatorRangePendingFlag = 6";
                        emit actuatorRangePendingFlagCleared();
                      }
                    break;
                case 2:
                    if (msg.at(1) == 0){
                        //STEER min
                        qDebug() << "ACTUATORS_RANGE_ACK for STEER min";

                        m_actuatorRangePendingFlag = 8;
                        qDebug() << "set m_actuatorRangePendingFlag = 8";
                        emit actuatorRangePendingFlagCleared();
                    }
                    else if (msg.at(1) == 1){
                        //STEER max
                        qDebug() << "ACTUATORS_RANGE_ACK for STEER max";

                        m_actuatorRangePendingFlag = 9;
                        qDebug() << "set m_actuatorRangePendingFlag = 9";
                        emit actuatorRangePendingFlagCleared();
                      }
                    break;
            }
            break;





        case GET_STEER_STATUS:
            qDebug() << "STEER State: ";
            qDebug() << "STEER: " << QString::number(msg.at(0));
            qDebug() << "err: " << QString::number(msg.at(1));

            carStatus->setSTEERStatus(msg.at(0),
                                    msg.at(1));
            break;



        case ECU_MSG:
            if(msg.at(0) == ECU_WARNINGS){
               qDebug() << "Errors State:";
               qDebug() << "err_apps: " << QString::number((msg.at(1) >> 0) & 1);
               qDebug() << "err_bse: " << QString::number((msg.at(1) >> 1) & 1);
               qDebug() << "err_wheel_left: " << QString::number((msg.at(1) >> 2) & 1);
               qDebug() << "err_wheel_right: " << QString::number((msg.at(1) >> 3) & 1);
               qDebug() << "err_steer: " << QString::number((msg.at(1) >> 4) & 1);
               qDebug() << "err_imu_front: " << QString::number((msg.at(1) >> 5) & 1);
               qDebug() << "err_gps: " << QString::number((msg.at(1) >> 6) & 1);
               qDebug() << "err_imu_central: " << QString::number((msg.at(1) >> 7) & 1);
               qDebug() << "err_imu_rear: " << QString::number((msg.at(2) >> 0) & 1);

               carStatus->setERRStatus((msg.at(1) >> 7) & 1,
                                       (msg.at(1) >> 6) & 1,
                                       (msg.at(1) >> 5) & 1,
                                       (msg.at(1) >> 4) & 1,
                                       (msg.at(1) >> 3) & 1,
                                       (msg.at(1) >> 2) & 1,
                                       (msg.at(1) >> 1) & 1,
                                       (msg.at(1) >> 0) & 1,
                                       (msg.at(2) >> 7) & 1);

               qDebug() << (int)msg.at(1) << " " << (int)msg.at(2) << endl;
               if((int)msg.at(1) == -1 && (int)msg.at(2) >= -128 && (int)msg.at(2) <= -1) // -1 = 255 e -128 = 128, ovvero se tutti i bit sono a 1. Usate il qDebug sopra per scoprire il vostro valore magico
               {
                   carStatus->setWarning(0);
               }
               else
               {
                   carStatus->setWarning(1);
               }

            }else if(msg.at(0) == ECU_ERRORS){
                  qDebug() << "Car CANBUS State: ";
                  qDebug() << "INV_RIGHT: " << QString::number((msg.at(1) >> 0) & 1);
                  qDebug() << "INV_LEFT: " << QString::number((msg.at(1) >> 1) & 1);
                  qDebug() << "FRONT: " << QString::number((msg.at(1) >> 2) & 1);
                  qDebug() << "CENTRAL: " << QString::number((msg.at(1) >> 3) & 1);
                  qDebug() << "PEDALS: " << QString::number((msg.at(1) >> 4) & 1);
                  qDebug() << "REAR: " << QString::number((msg.at(1) >> 5) & 1);
                  qDebug() << "BMS_HV: " << QString::number((msg.at(1) >> 6) & 1);
                  qDebug() << "BMS_LV: " << QString::number((msg.at(1) >> 7) & 1);

                  carStatus->setCANStatus((msg.at(1) >> 7) & 1,
                                          (msg.at(1) >> 6) & 1,
                                          (msg.at(1) >> 5) & 1,
                                          (msg.at(1) >> 4) & 1,
                                          (msg.at(1) >> 3) & 1,
                                          (msg.at(1) >> 2) & 1,
                                          (msg.at(1) >> 1) & 1,
                                          (msg.at(1) >> 0) & 1);
                  if((int)msg.at(1) <= 0)
                  {
                      qDebug() << "error 0" << (int)msg.at(1);
                      carStatus->setError(0);
                  }
                  else
                  {
                      carStatus->setError(1);
                      qDebug() << "error 1" << (int)msg.at(1);

                  }
            } else if(msg.at(0) == ECU_INV_LEFT){
               QString oldStatus = carStatus->HVStatus();
               carStatus->setHVStatus(oldStatus.mid(0,1).toInt(), 1, oldStatus.mid(2,1).toInt());
               qDebug() << "Ricevuto Stato INV LEFT" << oldStatus.mid(0,1).toInt();
               qDebug() << oldStatus;
            } else if(msg.at(0) == ECU_INV_RIGHT){
               QString oldStatus = carStatus->HVStatus();
               carStatus->setHVStatus(oldStatus.mid(0,1).toInt(),oldStatus.mid(1,1).toInt(), 1);
               qDebug() << "Ricevuto Stato INV RIGHT" << oldStatus.mid(1,1).toInt();
               qDebug() << oldStatus;
            }

            break;

        case EXEC_MODE_ID:
            ctrlIsEnabled = carStatus->getCtrlIsEnabled();
            ctrlIsOn = carStatus->getCtrlIsOn();
            goStatus = carStatus->getCurrentStatus();
            // Get stop message
            // Get current map

            // NUOVA VERSIONE, DAL 20/02
            driveModeEnabled = (msg.at(0) >> 0) & 1; //dovrebbe voler dire msg.at(0)[0], aka il bit piu a dx
            warning = (msg.at(0) >> 1) & 1;
            error = (msg.at(0) >> 2) & 1;
            velocity = ( (int) msg.at(1) ) / 2;
            m_hvTemp = ( (int) msg.at(2) ) / 2;
            m_hvVolt = ( (int) msg.at(3) ) / 2 + 400;
            m_lvTemp = ( (int) msg.at(4) ) / 2;
            m_lvVolt = ( (int) msg.at(5) ) / 10;

            qDebug() << "Velocity: " << velocity;
            qDebug() << "hvTemp: " << m_hvTemp;
            qDebug() << "hvVolt: " << m_hvVolt;
            qDebug() << "lvTemp: " << m_lvTemp;
            qDebug() << "lvVolt: " << m_lvVolt;

            emit hvTempChanged();
            emit lvTempChanged();
            emit hvVoltChanged();
            emit lvVoltChanged();

            qDebug() << "Velocity: " << velocity;

            if (!warning & !error & !ctrlIsEnabled) {
                ctrlIsEnabled = 1;
            }

            if (error) {
                // Stop the car
                ctrlIsEnabled = 0;
            }

            if (warning & !error) {
                ctrlIsEnabled = 0;
            }

            // Set the current Car Status
            carStatus->setCarStatus(ctrlIsEnabled,
                                    ctrlIsOn,
                                    driveModeEnabled,
                                    velocity,
                                    warning,
                                    error);


            break;

        case BMS_STATUS_ID:
            qDebug() << "Stato BMS:";

            if (msg.at(3) == 0x2A) {
                // Save temperature
                carStatus->setTemperature(msg.at(4));
                qDebug() << "Temperature: " << msg.at(4);
            }

            if (msg.at(3) == 0xF) {
                // Save charge
                carStatus->setStateOfCharge(msg.at(4));
                qDebug() << "State of Charge: " << msg.at(4);
            }

            break;
    };

}

int Canbus::brakeVal() const {
    return m_brakeVal;
}
int Canbus::throttleVal() const {
    return m_throttleVal;
}

int Canbus::hvTemp() const {
    return m_hvTemp;
}
int Canbus::lvTemp() const {
    return m_lvTemp;
}
int Canbus::hvVolt() const {
    return m_hvVolt;
}
int Canbus::lvVolt() const {
    return m_lvVolt;
}

void Canbus::toggleCar() {
    ctrlIsOn = carStatus->getCtrlIsOn();
    goStatus = carStatus->getCurrentStatus();
    map = carStatus->getMap();

    QByteArray toggleCAN;

    qDebug() << "CtrlIsOn: " << ctrlIsOn;
    qDebug() << "GoIsOn: " << goStatus;
    qDebug() << "Map:" << map;

    if (goStatus == CAR_STATUS_STOP) {
        toggleCAN[0] = 100;
    } else {
        toggleCAN[0] = goStatus;
        toggleCAN[1] = ctrlIsOn;
        switch (map) {
           case 0:
               toggleCAN[2] = -20;
           break;
           case 1:
               toggleCAN[2] = 20;
           break;
           case 2:
               toggleCAN[2] = 40;
           break;
           case 3:
               toggleCAN[2] = 60;
           break;
           case 4:
               toggleCAN[2] = 80;
           break;
           case 5:
               toggleCAN[2] = 100;
           break;

        }
    }

    toggleCAN.resize(8);

    qDebug() << canMessage;

    sendCanMessage(CHANGE_EXEC_MODE_ID, toggleCAN);
}

void Canbus::sendCanMessage(int id, QByteArray message) {
    QCanBusFrame frame;
    frame.setFrameId(id);
    frame.setPayload(message);
    device->writeFrame(frame);

}

void Canbus::askHVUpdate(int target) {
    QByteArray arrayTarget;
    arrayTarget.resize(8);
    if(target == 0)
      arrayTarget[0] = ECU_INV_LEFT;
    else if(target == 1)
      arrayTarget[0] = ECU_INV_RIGHT;

   if(target != 2)
      sendCanMessage(ECU_MSG, arrayTarget);
}

void Canbus::setActuatorsRange(int actuatorID, int rangeSide) {
  /*
   * Actuators ID:
   * 0: APPS
   * 1: BSE
   * 2: STEER
   *
   * Range Sides:
   * 0: MIN
   * 1: MAX
   */

   QByteArray actuator;
   actuator.resize(8);
   actuator[0] = actuatorID;
   actuator[1] = rangeSide;

  qDebug() << "setActuatorsRange for " << actuatorID << " for " << rangeSide;
  sendCanMessage(SET_ACTUATORS_RANGES, actuator);//QString("%1%2").arg(QString::number(actuatorID), QString::number(rangeSide)));

  switch(actuatorID){
      case 0:
        m_actuatorRangePendingFlag = 1;
      break;
      case 1:
        m_actuatorRangePendingFlag = 4;
      break;
      case 2:
        m_actuatorRangePendingFlag = 7;
      break;
  }

  emit actuatorRangePendingFlagCleared();
/*
  QUESTO SERVE A MOSTRARE A UI CHE LA PROCEDURA È FINITA
  SETTO A 0 E FACCIO L'EMIT (NON VA INSERITO QUA MA IN FASE DI ACK)

  m_actuatorRangePendingFlag = 0;
  emit actuatorRangePendingFlagCleared();

  qDebug() << "actuatorRangePendingFlagCleared";
*/
}

void Canbus::parseSerial() {
    QByteArray canMsg;
    int canId;

    while(device->framesAvailable()){

      QCanBusFrame frame = device->readFrame();
      canMsg = frame.payload();
      canId = frame.frameId();

      if(canId != 0){
        //qDebug() << QString::number(canId);
        parseCANMessage(canId,canMsg);
      }

    }
}

Canbus::~Canbus() {
    qDebug() << "Closing CAN...";
}
