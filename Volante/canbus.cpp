#include "canbus.h"
#include <QDebug>
#include <QFileInfo>

Canbus::Canbus(CarStatus* m_carStatus, const QString serial_port) {

    carStatus = m_carStatus;

    qDebug() << "CAN Interface Init";

    /*
     * TODO: change from manual serial port name to
     * name discovered by the serialPortInfo module!!!
     */

    //old CAN working fine on sim
    QFileInfo file_info(serial_port);

    qDebug() << "Serial Port name: " << serial_port;

    if (file_info.isSymLink()) {
        // This file is a SYM Link
        // thus the serial needs to be be targeted correctly
        serial.setPortName(file_info.symLinkTarget());
    } else {
        serial.setPortName(file_info.path());
    }
    //end old CAN

    //new CAN not working on sim
    //serial.setPortName("/dev/ttyAMA0")

    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    // Open the serial
    bool serialIsOpen = serial.open(QIODevice::ReadWrite);

    if (serialIsOpen) {
        qDebug() << "Serial Communication: OK";
    } else {
        qDebug() << "Serial Communication: NO";
    }

    connect(&serial, SIGNAL(readyRead()),
            this, SLOT(parseSerial()));

    connect(carStatus, SIGNAL(toggleCar()),
            this, SLOT(toggleCar()));

    connect(carStatus, SIGNAL(CTRLEnabledChanged()),
            this, SLOT(toggleCar()));

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

    m_actuatorRangePendingFlag = 0;
}

int Canbus::actuatorRangePendingFlag() const {
  qDebug() << m_actuatorRangePendingFlag << "Asked m_actuatorRangePendingFlag";
  return m_actuatorRangePendingFlag;
}

void Canbus::checkSensorsError() {
    qDebug() << "CheckSensorsError";
    sendCanMessage(CHECK_SENSOR_ERROR_ID, "");
}

void Canbus::checkCANCommunication(bool isOk = false) {
    if (isOk) {
        sendCanMessage(CHECK_CAN_COM, QString::number(1));
    } else {
        sendCanMessage(CHECK_CAN_COM, QString::number(0));
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

        case GET_ERRORS_STATUS:
            qDebug() << "Errors State:";
            qDebug() << "err_apps: " << QString::number(msg.at(0));
            qDebug() << "err_bse: " << QString::number(msg.at(1));
            qDebug() << "err_steer: " << QString::number(msg.at(2));
            qDebug() << "err_wheel_right: " << QString::number(msg.at(3));
            qDebug() << "err_wheel_left: " << QString::number(msg.at(4));
            qDebug() << "err_imu_front: " << QString::number(msg.at(5));
            qDebug() << "err_imu_central: " << QString::number(msg.at(6));
            qDebug() << "err_imu_rear: " << QString::number(msg.at(7));

            carStatus->setERRStatus(msg.at(0),
                                    msg.at(1),
                                    msg.at(2),
                                    msg.at(3),
                                    msg.at(4),
                                    msg.at(5),
                                    msg.at(6),
                                    msg.at(7));
            break;

        case GET_CAN_STATUS:
            qDebug() << "Car CANBUS State: ";
            qDebug() << "INV_RIGHT: " << QString::number(msg.at(0));
            qDebug() << "INV_LEFT: " << QString::number(msg.at(1));
            qDebug() << "FRONT: " << QString::number(msg.at(2));
            qDebug() << "REAR: " << QString::number(msg.at(3));
            qDebug() << "BMS_HV: " << QString::number(msg.at(4));
            qDebug() << "BMS_LV: " << QString::number(msg.at(5));

            carStatus->setCANStatus(msg.at(0),
                                    msg.at(1),
                                    msg.at(2),
                                    msg.at(3),
                                    msg.at(4),
                                    msg.at(5));
            break;

        case GET_HV_STATE_ID:

            qDebug() << "Messaggio: " << msg;

            if (msg.at(0) != 0xAF) {
                // [INV_R, INV_L, PRE]
                invRightState = msg.at(0);
                invLeftState = msg.at(1);
                preChargeState = msg.at(2);

                carStatus->setHVStatus(preChargeState, invRightState, invLeftState);

                qDebug() << "Ricevuto Stato HV";
            }
            break;

        case EXEC_MODE_ID:
            ctrlIsEnabled = carStatus->getCtrlIsEnabled();
            ctrlIsOn = carStatus->getCtrlIsOn();
            goStatus = carStatus->getCurrentStatus();
            // Get stop message
            // Get current map

            /*
            // VERO FINO AL 20/02
            warning = msg.at(0);
            error = msg.at(1);
            driveModeEnabled = msg.at(2);
            velocity = (int) msg.at(4);*/

            // NUOVA VERSIONE, DAL 20/02
            driveModeEnabled = (msg.at(0) >> 0) & 1; //dovrebbe voler dire msg.at(0)[0], aka il bit piu a dx
            warning = (msg.at(0) >> 1) & 1;
            error = (msg.at(0) >> 2) & 1;
            //HV_fault = (msg.at(0) >> 5) & 1;
            //LV_fault = (msg.at(0) >> 6) & 1;
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

            //emit delle property changed
            //emit velocity???
            emit hvTempChanged();
            emit lvTempChanged();
            emit hvVoltChanged();
            emit lvVoltChanged();

            // END NUOVA VERSIONE

            qDebug() << "Velocity: " << velocity;

            if (!warning & !error & !ctrlIsEnabled) {
                ctrlIsEnabled = 1;
            }

            if (error) {
                // EXPLOOOOODE
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

            // Send current Execution Mode
            // [stop, go, ctrlIsOn, map], CHANGE_EXEC_MODE_ID
            /*
            canMessage = QString("%1:0%2%30\n")
                                 .arg(QString::number(CHANGE_EXEC_MODE_ID),
                                      QString::number(goIsOn),
                                      QString::number(ctrlIsOn));

            qDebug() << "EXEC_MODE_ID Answer: " << canMessage;

            serial.write(canMessage.toStdString().c_str(), canMessage.size());
            */

            break;

        case BMS_STATUS_ID:
            // BMS CAN Message formatted this way:
            // [0x4, 0x62, DATA_REG_1, DATA_REG_2, DATA_VALUE]
            // DATA_REG_2 = 0x2A -> Temperature Message
            // DATA_REG_2 = 0xF -> State of Charge Message
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

int Canbus::hvTemp() const {
    qDebug() << "Asked hvTemp";
    qDebug() << m_hvTemp;
    return m_hvTemp;
}
int Canbus::lvTemp() const {
    qDebug() << "Asked lvTemp";
    qDebug() << m_lvTemp;
    return m_lvTemp;
}
int Canbus::hvVolt() const {
    qDebug() << "Asked hvVolt";
    qDebug() << m_hvVolt;
    return m_hvVolt;
}
int Canbus::lvVolt() const {
    qDebug() << "Asked lvVolt";
    qDebug() << m_lvVolt;
    return m_lvVolt;
}

void Canbus::toggleCar() {
    ctrlIsOn = carStatus->getCtrlIsOn();
    goStatus = carStatus->getCurrentStatus();
    map = carStatus->getMap();

    qDebug() << "CtrlIsOn: " << ctrlIsOn;
    qDebug() << "GoIsOn: " << goStatus;
    qDebug() << "Map:" << map;

    /* CarStatus:
     * 0    CAR_STATUS_IDLE
     * 1    CAR_STATUS_GO
     * 2    CAR_STATUS_STOP
     * 3    CAR_STATUS_MAP
     */
    if (goStatus == CAR_STATUS_STOP) {
        canMessage = QString("c%1:1000\n").arg(QString::number(CHANGE_EXEC_MODE_ID));
    } else {
        canMessage = QString("c%1:0%2%3%4\n").arg(QString::number(CHANGE_EXEC_MODE_ID),
                                                  QString::number(goStatus),
                                                  QString::number(ctrlIsOn),
                                                  QString::number(map));
    }

    qDebug() << canMessage;

    // Here don't send can msg BUT simply change the status
    // in the CAN controller
    serial.write(canMessage.toStdString().c_str(), canMessage.size());
}

void Canbus::sendCanMessage(int id, QString message) {
    // TODO: Change message from ASCII to sequence of numbers
    canMessage = QString("%1:%2\n").arg(QString::number(id), message);
    serial.write(canMessage.toStdString().c_str(), canMessage.size());
}

void Canbus::askHVUpdate(int target) {
    sendCanMessage(ASK_HV_STATE_ID, QString::number(target));
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
  qDebug() << "setActuatorsRange for " << actuatorID << " for " << rangeSide;
  sendCanMessage(SET_ACTUATORS_RANGES, QString("%1%2").arg(QString::number(actuatorID), QString::number(rangeSide)));

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
    QByteArray canFrame;
    QByteArray canMsg;

    while (serial.canReadLine()) {
        canFrame = QByteArray();
        canMsg = QByteArray();

        canFrame = serial.readLine();

        //canID = *canFrame[0] << 8 | *canFrame[1];
        canID = (uint8_t) canFrame[0] << 8 | (uint8_t) canFrame[1];

        if (canID != 0) {
            // Init the new canMsg array
            for (int i = 0; i < 8; i++) {
                canMsg.append(canFrame.at(i+2));
            }

            qDebug() << "CAN ID: " << canID << " CAN MSG " << canMsg;
            parseCANMessage(canID, canMsg);
        }

    }


    /*
    if (bytesToBeRead > 0) {

        qDebug() << "Bytes to be read: " << bytesToBeRead;

        while (serial.canReadLine()) {
            qDebug() << "Data to read" << bytesToBeRead;
            if (bytesToBeRead >> 11) {
                qDebug() << "CAN Msg";
                canFrame = serial.readLine();
            } else {
                qDebug() << serial.readLine();
            }
        }

    }
    */
}

Canbus::~Canbus() {
    qDebug() << "Closing serial port...";
    serial.close();
}
