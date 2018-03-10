#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QDebug>
#include <QFileInfo>
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSerialPort serial;
    QString SERIAL_PORT = "/dev/ttyUSB0";

    int updateFrequency = 50; //Hz
    int updateAfterNValues = 1; //1 = update each time, 2 = update once every 2 values received etc.
    int valuesSinceLastUpdate = 0;

    int size = 600;
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

    explicit MainWindow(QWidget *parent = 0);
    void createLinePlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, QStringList text, double minVal, double maxVal);
    void createBarsPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y, QStringList text, double minVal, double maxVal, double xRangeMax);
    void moveDataToLeft(QVector<double> &arr, int size);
    void updateBarsPlot(QCustomPlot *plot, QVector<double> x, QVector<double> y);
    void addNewPoint(int value, QCustomPlot *plot, QVector<double> &x, QVector<double> &y);
    void setNewFileName();
    void writeToFile(QString stringToWrite);
    void openSerial();
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void parseMessage();
    void on_btnStart_clicked();
    void on_btnPause_clicked();
    void on_btnSerialRetry_clicked();
    void on_btnLogRetry_clicked();
};

#endif // MAINWINDOW_H
