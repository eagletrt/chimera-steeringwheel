#include "arduinomgr.h"

#include <QDebug>
#include <QProcess>
#include <QFile>
#include <QTextStream>

ArduinoMgr::ArduinoMgr(QObject *parent) : QObject(parent){

    serial.setPortName("ttyACM0");
    serial.open(QIODevice::ReadWrite);
    qDebug() << "Open Serial Port: "<< serial.portName();
    if(!serial.isOpen())
    {
        qDebug()<<"port is not open"<<endl;
    }

    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    QObject::connect(&serial, &QSerialPort::readyRead, [=]()
    {
        databuf += serial.readAll();

        QString strData = databuf;
        if (!strData.contains("-"))//!strData.contains("B:") ||
            return;

        databuf.remove(0, strData.indexOf("-") + 2);
        strData = strData.right(strData.length() - strData.indexOf("B:"));
        strData = strData.left(strData.indexOf(("-")));
        auto datalist = strData.split("\r\n");
        Q_FOREACH(QString data, datalist)
        {
            if (data.startsWith("B:"))
            {
                QString brightness = data.right(data.length() - 2);
                if (m_brightness != brightness.toInt())
                {
                    m_brightness = brightness.toInt();
                    qDebug() << "Brightness: " << m_brightness;
                    writeToTxt("Brightness");
                    writeToTxt(brightness);
                    emit brightnessChanged();
                }
            }

            if (data.startsWith("V:"))
            {
                QString volume = data.right(data.length() - 2);
                if (m_volume != volume.toInt())
                {
                    m_volume = volume.toInt();
                   // QProcess exec;
                   // QString setVolumeCmd = "osascript -e \"set Volume " + QString::number(m_volume/102) + "\"";
                   // exec.start(setVolumeCmd);
                   // exec.waitForFinished();
                    qDebug() << "Volume: " << m_volume;
                    writeToTxt("Volume");
                    writeToTxt(volume);
                    emit volumeChanged();
                }
            }
        }
    });
}


void ArduinoMgr::turnOn(qint32 id)
{
    QString cmd = "TURN_ON_";
    cmd.append(QString::number(id));
    serial.write(cmd.toLocal8Bit());//.toLocal8Bit()
    serial.flush();
    writeToTxt(cmd);
    qDebug() << cmd;
}

void ArduinoMgr::turnOff(qint32 id)
{
    QString cmd = "TURN_OFF_";
    cmd.append(QString::number(id));
    serial.write(cmd.toLocal8Bit());
    serial.flush();
    writeToTxt(cmd);
    qDebug() << cmd;

}

qint32 ArduinoMgr::brightness()
{
    return m_brightness;
}

qint32 ArduinoMgr::volume()
{
    return m_volume;
}

void ArduinoMgr::writeToTxt(QString text){
    QFile mFile("logSerial.txt");
    if(!mFile.open(QFile::WriteOnly | QFile::Append)){
        qDebug() << "Impossibile aprire per scrittura";
        return;
    }
    QTextStream out(&mFile);
    if(mFile.pos()==0){
        out << "Request & Response from Arduino\n\n";
        //out << "Instruction\t , \tVal,\n\n";
    }
    if (text.startsWith("V") || text.startsWith("B")){
        out << text << ",";
    }else{
        out << text << ",\n";
    }

    mFile.flush();
    mFile.close();
}

void ArduinoMgr::readFromTxt(){
    QFile mFile("logSerial.txt");
    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Impossibile aprire per lettura";
        return;
    }
    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;

    mFile.close();
}
