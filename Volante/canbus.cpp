#include "canbus.h"
#include <QDebug>
#include <QFileInfo>

Canbus::Canbus(CarStatus* m_carStatus, const QString serial_port) {

    carStatus = m_carStatus;

    qDebug() << "CAN Interface Init";

    QFileInfo file_info(serial_port);

    if (file_info.isSymLink()) {
        // This file is a SYM Link
        // thus the serial needs to be be targeted correctly
        serial.setPortName(file_info.symLinkTarget());
    } else {
        serial.setPortName(file_info.path());
    }

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

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(LoopSensorsUpdate()));
}

void Canbus::startSensorsUpdate() {
    qDebug() << "startSensorsUpdate";
    timer->start(30);
}

void Canbus::stopSensorsUpdate() {
    qDebug() << "stopSensorsUpdate";
    timer->stop();
}

//sends Sensors Status every 30ms
void Canbus::LoopSensorsUpdate(){
    sendCanMessage(ASK_SENSORS_VALUE_ID, "");
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
            carStatus->setAPPSBSEStatus(msg.at(0),
                                    msg.at(1),
                                    msg.at(2),
                                    msg.at(3));
            break;

        case GET_STEER_STATUS:
            carStatus->setSTEERStatus(msg.at(0),
                                    msg.at(1));
            break;

        case GET_ERRORS_STATUS:
            qDebug() << "Errors State: ";
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

            warning = msg.at(0);
            error = msg.at(1);
            driveModeEnabled = msg.at(2);
            velocity = (int) msg.at(4);

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

void Canbus::toggleCar() {
    ctrlIsOn = carStatus->getCtrlIsOn();
    goStatus = carStatus->getCurrentStatus();

    qDebug() << "CtrlIsOn: " << ctrlIsOn;
    qDebug() << "GoIsOn: " << goStatus;

    /* CarStatus:
     * 0    CAR_STATUS_IDLE
     * 1    CAR_STATUS_GO
     * 2    CAR_STATUS_STOP
     */
    if (goStatus == CAR_STATUS_STOP) {
        canMessage = QString("c%1:100\n").arg(QString::number(CHANGE_EXEC_MODE_ID));
    } else {
        canMessage = QString("c%1:0%2%3\n").arg(QString::number(CHANGE_EXEC_MODE_ID), QString::number(goStatus), QString::number(ctrlIsOn));
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
