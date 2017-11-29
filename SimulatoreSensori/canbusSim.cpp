#include "canbusSim.h"
#include <QDebug>
#include <QFileInfo>

CanbusSim::CanbusSim(CarStatusSim* m_carStatus, const QString serial_port) {

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
}

void CanbusSim::checkCANCommunication(bool isOk = false) {
    if (isOk) {
        sendCanMessage(CHECK_CAN_COM, QString::number(1));
    } else {
        sendCanMessage(CHECK_CAN_COM, QString::number(0));
    }
}


void CanbusSim::toggleCar() {
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

void CanbusSim::sendCanMessage(int id, QString message) {
      // TODO: Change message from ASCII to sequence of numbers
    canMessage = QString("%1:%2\n").arg(QString::number(id), message); 
    serial.write(canMessage.toStdString().c_str(), canMessage.size());
}

void CanbusSim::MySendSerialMessage(int id, std::vector<int> values)
{
    QByteArray msg;
    int zero = 0;
    int arraySize = values.size();

    //Create the first 2 bytes
    msg.append(zero);
    msg.append(id);
    //Create the final 8 bytes
    for(int i = 0; i < arraySize; i++)
        msg.append(values[i]);
    for(int i = arraySize; i < 8; i++)
        msg.append(zero);
    //Add \n to terminate the message
    msg.append("\n");

    //Send message
    serial.write(msg.toStdString().c_str(), msg.length());
}

CanbusSim::~CanbusSim() {
    qDebug() << "Closing serial port...";
    serial.close();
}
