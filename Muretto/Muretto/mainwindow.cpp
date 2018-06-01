#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    windowsOpened.fill(false, 3); //set default windows state = closed

    //create all windows
    window0_temps = new TempsWindow(this);
    window1_test = new TestWindow(this);

    //connect windows to signal slot for when they close
    connect(window0_temps,SIGNAL(windowClosed(int)),this, SLOT(on_windowClosed(int)));
    connect(window1_test,SIGNAL(windowClosed(int)),this, SLOT(on_windowClosed(int)));

    setNewFileName();

    openSerial();

    //initialize arrays
    for(int i = 0; i < size; i++)
    {
        worstTempX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
        worstTempY.append(-1);

        worstVoltX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
        worstVoltY.append(-1);

        totalCurrX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
        totalCurrY.append(-1);

        voltControlX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
        voltControlY.append(-1);

        endurCurrX.append(i * (1.0 / updateFrequency) * updateAfterNValues - 60);
        endurCurrY.append(-1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_start_clicked()
{
    serial.clear();
    QObject::connect(&serial, SIGNAL(readyRead()), this, SLOT(parseMessage()));
    ui->pushButton_pause->setEnabled(true);
    ui->pushButton_start->setEnabled(false);
    ui->label_skippedData->setStyleSheet("background-color:green;");
    ui->label_skippedData->setText("Skip: 0");

    //Create line plots
//    QStringList strings = {"Throttle", "Time (s)", "Percentage (%)"};
//    createLinePlot(ui->worstTempPlot, worstTempX, worstTempY, strings, 0, 100);
//    QStringList strings2 = {"BSE", "Time (s)", "Percentage (%)"};
//    createLinePlot(ui->branchCurrPlot, branchCurrX, branchCurrY, strings2, 0, 100);
//    QStringList strings3 = {"TempHV", "Time(s)", "Percentage (%)"};
//    createLinePlot(ui->totalCurrPlot, totalCurrX, totalCurrY, strings3, 0, 100);
//    QStringList strings4 = {"Curr HV Left", "Time(s)", "Percentage (%)"};
//    createLinePlot(ui->voltControlPlot, voltControlX, voltControlY, strings4, 0, 100);
//    QStringList strings8 = {"Curr HV Right", "Time(s)", "Percentage (%)"};
//    createLinePlot(ui->endurCurrPlot, endurCurrX, endurCurrY, strings8, 0, 100);

    //open requested windows
    if (ui->checkBox_temps->isChecked() && !windowsOpened[0]) { //if requested and not open ATM

        //Create line plots
        QStringList strings_tempHV = {"TempHV", "Time(s)", "Percentage (%)"};
        createLinePlot(window0_temps->findChild<QCustomPlot*>("plot_tempHV"), totalCurrX, totalCurrY, strings_tempHV, 0, 100);
        QStringList strings_temp2 = {"Temp2", "Time(s)", "Percentage (%)"};
        createLinePlot(window0_temps->findChild<QCustomPlot*>("plot_temp2"), totalCurrX, totalCurrY, strings_temp2, 0, 100);

        windowsOpened[0] = true;
        window0_temps->show(); //show window
    }
    if (ui->checkBox_test->isChecked() && !windowsOpened[1]) { //if requested and not open ATM

        //Create line plots
        QStringList strings_test0 = {"Test0", "Time(s)", "Armadi (a)"};
        createLinePlot(window1_test->findChild<QCustomPlot*>("plot_test0"), totalCurrX, totalCurrY, strings_test0, 0, 100);
        QStringList strings_test1 = {"Test1", "Time(s)", "Giuseppi (g)"};
        createLinePlot(window1_test->findChild<QCustomPlot*>("plot_test1"), totalCurrX, totalCurrY, strings_test1, 0, 20);
        QStringList strings_test2 = {"Test2", "Time(s)", "Sedie (s)"};
        createLinePlot(window1_test->findChild<QCustomPlot*>("plot_test2"), totalCurrX, totalCurrY, strings_test2, 0, 100);

        windowsOpened[1] = true;
        window1_test->show(); //show window
    }
}

void MainWindow::on_pushButton_pause_clicked()
{
    QObject::disconnect(&serial, SIGNAL(readyRead()), this, SLOT(parseMessage()));
    ui->pushButton_pause->setEnabled(false);
    ui->pushButton_start->setEnabled(true);
}

void MainWindow::on_pushButton_serialRetry_clicked()
{
    openSerial();
}

void MainWindow::on_windowClosed(int windowID)
{
    windowsOpened[windowID] = false;
    qDebug() << "closed window: " << windowID;

    //reset window that closed
    switch (windowID) {
        case 0:
            window0_temps = new TempsWindow(this);
            connect(window0_temps,SIGNAL(windowClosed(int)),this, SLOT(on_windowClosed(int)));
            qDebug() << "reset window to new TempsWindow";
        break;
        case 1:
            window1_test = new TestWindow(this);
            connect(window1_test,SIGNAL(windowClosed(int)),this, SLOT(on_windowClosed(int)));
            qDebug() << "reset window to new TestWindow";
        break;
    }

}

void MainWindow::openSerial()
{
    qDebug() << "Trying to open serial";

    SERIAL_PORT = ui->lineEdit_serialPort->text();
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
        ui->label_serial->setStyleSheet("background-color:green;");
        ui->pushButton_serialRetry->setEnabled(false);
        ui->pushButton_start->setEnabled(true);
    } else {
        qDebug() << "Serial Communication: NO";
        qDebug() << "Error: " << serial.error();
        ui->label_serial->setStyleSheet("background-color:red;");
        ui->pushButton_serialRetry->setEnabled(true);
        ui->pushButton_start->setEnabled(false);
    }
}

void MainWindow::parseMessage()
{
    qDebug() << "Qualcosa leggo";
    while(serial.canReadLine())
    {
        QByteArray received = serial.readLine();

        qDebug() << received.length();
        qDebug() << received;
        uint8_t values_array[bytesToReceive];
        if(valuesSinceLastUpdate + 1 == updateAfterNValues)
        {
            valuesSinceLastUpdate = 0;

            //qDebug() << received;

            //qDebug() << valuesReceived;

            //add the values to the arrays
            // addNewPoint(valuesReceived[7].toDouble(), ui->totalCurrPlot, totalCurrX, totalCurrY);


            // - 2 perchè tolgo /r/n
            for (int i=0; i<received.length() - 2; i++) {
                values_array[i] = ((uint8_t) received[i] - 50);
                qDebug() << values_array[i];
            }

            //update the plots that are in an opened windows
            if (windowsOpened[0]) {
                addNewPoint(values_array[0], window0_temps->findChild<QCustomPlot*>("plot_tempHV"), totalCurrX, totalCurrY);
                addNewPoint(values_array[1], window0_temps->findChild<QCustomPlot*>("plot_temp2"), totalCurrX, totalCurrY);
            }
            //update the plots that are in an opened windows
            if (windowsOpened[1]) {
                addNewPoint(values_array[2], window1_test->findChild<QCustomPlot*>("plot_test0"), totalCurrX, totalCurrY);
                addNewPoint(values_array[3], window1_test->findChild<QCustomPlot*>("plot_test1"), totalCurrX, totalCurrY);
                addNewPoint(values_array[4], window1_test->findChild<QCustomPlot*>("plot_test2"), totalCurrX, totalCurrY);
            }

            QString toLog = "";
            for(int i = 0; i < bytesToReceive; i++)
            {
                toLog.append(QString::number(values_array[i]));
                if(i != bytesToReceive-1)
                    toLog.append("\t");
            }
            writeToFile(toLog);

        }
        else
            valuesSinceLastUpdate++;

        //set skipped value error
        if(lastValueReceived != -1)
        {
            //qDebug() << valuesReceived[0].toDouble() << ";" << (lastValueReceived + 1) % 100;
            if(values_array[bytesToReceive-1] % 100 != (lastValueReceived + 1) % 100)
            {
                valuesSkipped++;
                if(valuesSkipped <= 5)
                    ui->label_skippedData->setStyleSheet("background-color:orange;");
                else
                    ui->label_skippedData->setStyleSheet("background-color:red;");
                ui->label_skippedData->setText("Skip: " + QString::number(valuesSkipped));
                writeToFile("===SKIP===");
            }
        }
        lastValueReceived = values_array[bytesToReceive-1];
    }
}

void MainWindow::createLinePlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, QStringList text, double minVal, double maxVal)
{
    plot->addGraph();
    plot->graph(0)->setData(x, y);

    //set dark theme
    plot->graph(0)->setPen(QPen(QColor(128,216,255)));
    plot->xAxis->setBasePen(QPen(Qt::white, 1));
    plot->yAxis->setBasePen(QPen(Qt::white, 1));
    plot->xAxis->setTickPen(QPen(Qt::white, 1));
    plot->yAxis->setTickPen(QPen(Qt::white, 1));
    plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    plot->xAxis->setTickLabelColor(Qt::white);
    plot->yAxis->setTickLabelColor(Qt::white);
    plot->xAxis->setLabelColor(Qt::gray);
    plot->yAxis->setLabelColor(Qt::gray);
    plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    plot->xAxis->grid()->setSubGridVisible(true);
    plot->yAxis->grid()->setSubGridVisible(true);
    plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    plot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    plot->axisRect()->setBackground(axisRectGradient);

    plot->xAxis->setRange(0, 60);
    plot->yAxis->setRange(minVal, maxVal);

    //title
    plot->plotLayout()->insertRow(0);
    QCPTextElement* plotTitle = new QCPTextElement(plot, text[0], QFont("sans", 12, QFont::Thin));
    plotTitle->setTextColor(Qt::white);
    plot->plotLayout()->addElement(0, 0, plotTitle);

    //labels
    plot->xAxis->setLabel(text[1]);
    plot->yAxis->setLabel(text[2]);

    plot->replot();
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
    QDir _dir;
    _dir.mkdir( "logs" );

    filename =  "logs/log_" + QDate::currentDate().toString().replace(" ", "_") + "_" + QTime::currentTime().toString().replace(" ", "_").replace(":", "_") + ".txt";
    qDebug() << "Saving to: " << filename;

    //see if it works
    QFile file(filename);
    if ( file.open( QIODevice::WriteOnly | QIODevice::Append) )
    {
        ui->label_log->setStyleSheet("background-color:green;");
        //ui->lblFile->setText("Saving to: " + filename);
        //ui->btnLogRetry->setEnabled(false);
        file.close();
    }
    else
    {
        ui->label_log->setStyleSheet("background-color:red;");
        //ui->btnLogRetry->setEnabled(true);
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
