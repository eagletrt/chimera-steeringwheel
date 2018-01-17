#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
  ui->setupUi(this);

  arduino_is_available = false;
  arduino_port_name = "";
  arduino = new QSerialPort;

  //qDebug per ottenere i dati di arduino e configurare qt
  qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
  foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
    qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
    if(serialPortInfo.hasVendorIdentifier()){
      qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
    }
    qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
    if(serialPortInfo.hasProductIdentifier()){
      qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
    }
  }


  foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
    if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
      if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
        if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
          arduino_port_name = serialPortInfo.portName();
          arduino_is_available = true;
        }
      }
    }
  }

  if(arduino_is_available){
    // apre e configura la seriale
    arduino->setPortName(arduino_port_name);
    arduino->open(QSerialPort::ReadWrite);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    // Connettere l'evento readyRead() a una funziona che stampa
    // il contenuto del Messaggio
    // connect(*sender_obj, SIGNAL, receiver_obj, SLOT);
    connect(arduino, SIGNAL(readyRead()),
            this, SLOT(printSerial()));

  }else{
    // errore porta
    //QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
    qDebug() << "Port Error, Couldn' find the Arduino";
  }
}

void MainWindow::printSerial() {
  while (arduino->canReadLine()) {
      qDebug() << arduino->readLine() << endl;
  }
}

MainWindow::~MainWindow(){
  if(arduino->isOpen()){
      arduino->close();
  }

  delete arduino;
  delete ui;
}


void MainWindow::on_animationButton_clicked(){
  if (arduino->isOpen() && arduino->isWritable()){
    QByteArray output("a");
    QByteArray input;
    arduino->write(output);
    arduino->flush();
    qDebug() << "data has been send to arduino" << endl;

    /*blocco per leggere qui dobbiamo sistemare:
    "/n" come sequenza di fine
    metti tutto in un file di log per poter aggiornare
    arduino->waitForBytesWritten(1);
    arduino->waitForReadyRead(1);
    if(arduino->bytesAvailable()>=1){
    input=arduino->read(64);//18
    qDebug()<<input;

    arduino->close();
    }*/
  }
}

void MainWindow::on_redButton_clicked(){
    if (arduino->isOpen() && arduino->isWritable()){
      QByteArray output("r");
      QByteArray input;
      arduino->write(output);
      arduino->flush();
      qDebug() << "data has been send to arduino" << endl;
    }
}
void MainWindow::on_greenButton_clicked(){
    if (arduino->isOpen() && arduino->isWritable()){
      QByteArray output("g");
      QByteArray input;
      arduino->write(output);
      arduino->flush();
      qDebug() << "data has been send to arduino" << endl;
    }
}
void MainWindow::on_yellowButton_clicked(){
    if (arduino->isOpen() && arduino->isWritable()){
      QByteArray output("y");
      QByteArray input;
      arduino->write(output);
      arduino->flush();
      qDebug() << "data has been send to arduino" << endl;
    }
}

void MainWindow::on_sendButton_clicked(){
    if (arduino->isOpen() && arduino->isWritable()){

      QByteArray output("a");//getText da form e send

    }
}

