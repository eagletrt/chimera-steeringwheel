#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileInfo>
#include <QSerialPort>
#include "qcustomplot.h"
#include "tempswindow.h"
#include "testwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    TempsWindow *window0_temps;
    TestWindow *window1_test;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_windowClosed(int windowID);

private slots:
    void on_pushButton_start_clicked();
    void parseMessage();
    void on_pushButton_pause_clicked();
    void on_pushButton_serialRetry_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QVector<bool> windowsOpened;

    QSerialPort serial;
    QString SERIAL_PORT = "/dev/ttyUSB0";

    int updateFrequency = 15; //Hz
    int bytesToReceive = 55; //byte
    int updateAfterNValues = 1; //1 = update each time, 2 = update once every 2 values received etc.
    int valuesSinceLastUpdate = 0;

    int size = 3000;
    QVector<double> worstTempX, worstTempY;
    QVector<double> worstVoltX, worstVoltY;
    QVector<double> totalCurrX, totalCurrY;
    QVector<double> voltControlX, voltControlY;
    QVector<double> endurCurrX, endurCurrY;

    QVector<double> cellTempX, cellTempY;
    QVector<double> cellVoltX, cellVoltY;
    QVector<double> branchCurrX, branchCurrY;

    QString filename = "log.txt";

    int lastValueReceived = -1;
    int valuesSkipped = 0;

    void createLinePlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, QStringList text, double minVal, double maxVal);
    void moveDataToLeft(QVector<double> &arr, int size);
    void addNewPoint(int value, QCustomPlot *plot, QVector<double> &x, QVector<double> &y);
    void setNewFileName();
    void writeToFile(QString stringToWrite);
    void openSerial();
};

#endif // MAINWINDOW_H
