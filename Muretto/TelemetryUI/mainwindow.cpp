#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setNewFileName();

    openSerial();

    /*
       ui->lblTempErr->setStyleSheet("background-color:green;");
       ui->lblVoltErr->setStyleSheet("background-color:green;");
       ui->lblCurrErr->setStyleSheet("background-color:green;");
       */

    //Create line plots
    QStringList strings = {"Throttle", "Time (s)", "Percentage (%)"};
    createLinePlot(ui->worstTempPlot, worstTempX, worstTempY, strings, 0, 100);
    QStringList strings2 = {"BSE", "Time (s)", "Percentage (%)"};
    createLinePlot(ui->branchCurrPlot, branchCurrX, branchCurrY, strings2, 0, 100);
    QStringList strings3 = {"TempHV", "Time(s)", "Percentage (%)"};
    createLinePlot(ui->totalCurrPlot, totalCurrX, totalCurrY, strings3, 0, 100);
    QStringList strings4 = {"Curr HV Left", "Time(s)", "Percentage (%)"};
    createLinePlot(ui->voltControlPlot, voltControlX, voltControlY, strings4, 0, 100);
    QStringList strings8 = {"Curr HV Right", "Time(s)", "Percentage (%)"};
    createLinePlot(ui->endurCurrPlot, endurCurrX, endurCurrY, strings8, 0, 100);

    /*
    //Create bars plots
    QStringList strings5 = {"Cell's Temperatures", "B1D   B1U             B2D   B2U             B3D   B3U", "Temperature (°C)"};
    cellTempX << 1 << 2 << 4 << 5 << 7 << 8;
    cellTempY << 40 << 80 << 40 << 80 << 40 << 80;
    createBarsPlot(ui->cellTempPlot, cellTempX, cellTempY, strings5, 20, 80, 9);
    QStringList strings6 = {"Cell's Voltages", "B1                         B2                         B3", "Voltage (V)"};
    cellVoltX << 1 << 3 << 5;
    cellVoltY << 1 << 2 << 3;
    createBarsPlot(ui->cellVoltPlot, cellVoltX, cellVoltY, strings6, 0, 4.3, 6);
    QStringList strings7 = {"Branch's Currents", "C1          C2          C3          C4          C5", "Current (A)"};
    branchCurrX << 1 << 2 << 3 << 4 << 5;
    branchCurrY << 10 << 20 << 30 << 40 << 50;
    createBarsPlot(ui->branchCurrPlot, branchCurrX, branchCurrY, strings7, 0, 50, 6);*/

    //initialize arrays
    for(int i = 0; i < size; i++)
    {
        worstTempX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
        worstTempY.append(-1);
        /*
           worstVoltX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
           worstVoltY.append(-1);

           totalCurrX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
           totalCurrY.append(-1);

           voltControlX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
           voltControlY.append(-1);

           endurCurrX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
           endurCurrY.append(-1);*/
    }
}

void MainWindow::createLinePlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, QStringList text, double minVal, double maxVal)
{
    plot->addGraph();
    plot->graph(0)->setData(x, y);
    plot->xAxis->setRange(0, 60);
    plot->yAxis->setRange(minVal, maxVal);
    //title
    plot->plotLayout()->insertRow(0);
    plot->plotLayout()->addElement(0, 0, new QCPTextElement(plot, text[0], QFont("sans", 12, QFont::Bold)));
    //labels
    plot->xAxis->setLabel(text[1]);
    plot->yAxis->setLabel(text[2]);

    plot->replot();
}

void MainWindow::createBarsPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, QStringList text, double minVal, double maxVal, double xRangeMax)
{
    QCPBars *myBars = new QCPBars(plot->xAxis, plot->yAxis);
    // now we can modify properties of myBars:
    //x << 1 << 2 << 4 << 5 << 7 << 8; //x
    //y << 0 << 0 << 0 << 0 << 0 << 0; //y
    //y << 40 << 80 << 40 << 80 << 40 << 80;
    myBars->setData(x, y);
    myBars->setWidth(1);
    myBars->setName("bars");
    plot->rescaleAxes();
    plot->yAxis->setRange(minVal, maxVal);
    plot->xAxis->setRange(0, xRangeMax);
    plot->xAxis->setVisible(false);
    //title
    plot->plotLayout()->insertRow(0);
    plot->plotLayout()->addElement(0, 0, new QCPTextElement(plot, text[0], QFont("sans", 12, QFont::Bold)));
    //labels
    plot->yAxis->setLabel(text[2]);
    //bottom labels
    QCPItemText *textLabel = new QCPItemText(plot);
    textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
    textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel->position->setCoords(0.5, 0.9); // place position at center/top of axis rect
    textLabel->setText(text[1]);

    plot->replot();
}

void MainWindow::updateBarsPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y)
{
    QCPBars *bars = qobject_cast<QCPBars*>(plot->plottable(0));

    bars->setData(x, y);
    plot->replot();
}

void MainWindow::parseMessage()
{
    qDebug() << "Qualcosa leggo";
    while(serial.canReadLine())
    {
        QByteArray received = serial.readLine();

        //log the data
        //received.remove("\n");
        //writeToFile(received);

        qDebug() << received.length();
        qDebug() << received;

        if(valuesSinceLastUpdate + 1 == updateAfterNValues)
        {
            valuesSinceLastUpdate = 0;

            //qDebug() << received;

            //qDebug() << valuesReceived;

            //add the values to the arrays
            // addNewPoint(valuesReceived[7].toDouble(), ui->totalCurrPlot, totalCurrX, totalCurrY);

            uint8_t values_array[] = {0,0,0,0,0};

            for (int i=0; i<received.length(); i++) {
                values_array[i] = ((uint8_t) received[i] - 50) / 2;
                qDebug() << values_array[i];	
            }

            addNewPoint(values_array[0], ui->worstTempPlot, worstTempX, worstTempY);
            addNewPoint(values_array[1], ui->branchCurrPlot, branchCurrX, branchCurrY);
            addNewPoint(values_array[2], ui->totalCurrPlot, totalCurrX, totalCurrY);
            addNewPoint(values_array[3], ui->voltControlPlot, voltControlX, voltControlY);
            addNewPoint(values_array[4], ui->endurCurrPlot, endurCurrX, endurCurrY);	
//addNewPoint(valuesReceived[8].toDouble() + valuesReceived[9].toDouble() + valuesReceived[10].toDouble(), ui->worstVoltPlot, worstVoltX, worstVoltY);
            //addNewPoint(valuesReceived[11].toDouble(), ui->voltControlPlot, voltControlX, voltControlY);
            //addNewPoint(valuesReceived[12].toDouble(), ui->endurCurrPlot, endurCurrX, endurCurrY);

            //update the bar plots
            /*
               cellTempY.clear();
               cellTempY << valuesReceived[1].toDouble() << valuesReceived[2].toDouble() << valuesReceived[3].toDouble() << valuesReceived[4].toDouble() << valuesReceived[5].toDouble() << valuesReceived[6].toDouble();
            //updateBarsPlot(ui->cellTempPlot, cellTempX, cellTempY);

            cellVoltY.clear();
            cellVoltY << valuesReceived[8].toDouble() << valuesReceived[9].toDouble() << valuesReceived[10].toDouble();
            //updateBarsPlot(ui->cellVoltPlot, cellVoltX, cellVoltY);

*/
            /*branchCurrY.clear();
              branchCurrY << valuesReceived[0].toDouble() << valuesReceived[0].toDouble() << valuesReceived[0].toDouble() << valuesReceived[0].toDouble() << valuesReceived[0].toDouble();
              updateBarsPlot(ui->branchCurrPlot, branchCurrX, branchCurrY);*/

            //setErrors
            /*
               if(valuesReceived[1].toDouble() > 80)
               {
               ui->lblTempErr->setStyleSheet("background-color:red;");
               }

               if(valuesReceived[8].toDouble() + valuesReceived[9].toDouble() + valuesReceived[10].toDouble() < 10)
               {
               ui->lblVoltErr->setStyleSheet("background-color:red;");
               }

               if(valuesReceived[7].toDouble() > 160)
               {
               ui->lblCurrErr->setStyleSheet("background-color:red;");
               }*/

        }
        else
            valuesSinceLastUpdate++;

        //set skipped value error
        /*if(lastValueReceived != -1)
          {
        //qDebug() << valuesReceived[0].toDouble() << ";" << (lastValueReceived + 1) % 100;
        if(valuesReceived[0].toInt() % 100 != (lastValueReceived + 1) % 100)
        {
        valuesSkipped++;
        if(valuesSkipped <= 5)
        ui->lblSkippedData->setStyleSheet("background-color:orange;");
        else
        ui->lblSkippedData->setStyleSheet("background-color:red;");
        ui->lblSkippedData->setText("Skip: " + QString::number(valuesSkipped));
        }
        }
        lastValueReceived = valuesReceived[0].toInt();*/
    }
}
void MainWindow::addNewPoint(int value, QCustomPlot *plot, QVector<double> &x, QVector<double> &y)
{
    //add the point, removing the oldest one first
    moveDataToLeft(x, size);
    moveDataToLeft(y, size);
    y[size - 1] = value;
    x[size - 1] = x[size - 2] + (1.0 / updateFrequency) * updateAfterNValues;
    //update the graph
    plot->xAxis->setRange(x[0], x[size - 1]);
    plot->graph(0)->setData(x, y);
    plot->replot();
}

void MainWindow::moveDataToLeft(QVector<double> &arr, int size)
{
    for(int i = 0; i < size - 1; i++)
        arr[i] = arr[i+1];
    arr[size - 1] = 0; //useless value
}

void MainWindow::setNewFileName()
{
    filename =  "log_" + QDate::currentDate().toString().replace(" ", "_") + "_" + QTime::currentTime().toString().replace(" ", "_").replace(":", "_") + ".txt";
    qDebug() << filename;

    //see if it works
    QFile file(filename);
    if ( file.open( QIODevice::WriteOnly | QIODevice::Append) )
    {
        ui->lblLog->setStyleSheet("background-color:green;");
        ui->lblFile->setText("Saving to: " + filename);
        ui->btnLogRetry->setEnabled(false);
        file.close();
    }
    else
    {
        ui->lblLog->setStyleSheet("background-color:red;");
        ui->btnLogRetry->setEnabled(true);
    }
}

void MainWindow::writeToFile(QString stringToWrite)
{
    QFile file(filename);
    if ( file.open( QIODevice::WriteOnly | QIODevice::Append) )
    {
        QTextStream stream( &file );
        stream << stringToWrite << endl;
        file.close();
    }
}

void MainWindow::openSerial()
{
    qDebug() << "Trying to open serial";

    SERIAL_PORT = ui->txtSerialName->toPlainText();
    QFileInfo file_info(SERIAL_PORT);

    if (file_info.isSymLink()) {
        // This file is a SYM Link
        // thus the serial needs to be be targeted correctly
        serial.setPortName(file_info.symLinkTarget());
    } else {
        serial.setPortName(file_info.absoluteFilePath());
    }

    qDebug() << serial.portName();

    serial.setBaudRate(115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    // Open the serial
    bool serialIsOpen = serial.open(QIODevice::ReadWrite);

    if (serialIsOpen) {
        qDebug() << "Serial Communication: OK";
        ui->lblSerial->setStyleSheet("background-color:green;");
        ui->btnSerialRetry->setEnabled(false);
        ui->btnStart->setEnabled(true);
    } else {
        qDebug() << "Serial Communication: NO";
        qDebug() << "Error: " << serial.error();
        ui->lblSerial->setStyleSheet("background-color:red;");
        ui->btnSerialRetry->setEnabled(true);
        ui->btnStart->setEnabled(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    serial.clear();
    QObject::connect(&serial, SIGNAL(readyRead()), this, SLOT(parseMessage()));
    ui->btnPause->setEnabled(true);
    ui->btnStart->setEnabled(false);

    ui->lblSkippedData->setStyleSheet("background-color:green;");
    ui->lblSkippedData->setText("Skip: 0");
}

void MainWindow::on_btnPause_clicked()
{
    QObject::disconnect(&serial, SIGNAL(readyRead()), this, SLOT(parseMessage()));
    ui->btnPause->setEnabled(false);
    ui->btnStart->setEnabled(true);
}

void MainWindow::on_btnSerialRetry_clicked()
{
    openSerial();
}

void MainWindow::on_btnLogRetry_clicked()
{
    setNewFileName();
}
