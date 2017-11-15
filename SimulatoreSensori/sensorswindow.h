#ifndef SENSORSWINDOW_H
#define SENSORSWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "canbus.h"
#include "carstatus.h"

#define SERIAL_PORT "../../Volante/build/ttyV1"

namespace Ui {
class SensorsWindow;
}

class SensorsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SensorsWindow(CarStatus* car, Canbus* canInterface, QWidget *parent = 0);
    ~SensorsWindow();

private slots:
    void MyParseMessage();

    //HV
    void on_btnInvSx_clicked();
    void on_btnInvDx_clicked();
    void on_btnPreCh_clicked();

    //ERRORS
    void on_btnApps_clicked();
    void on_btnBSE_clicked();
    void on_btnSteer_clicked();
    void on_btnWheelLeft_clicked();
    void on_btnWheelRight_clicked();
    void on_btnIMUFront_clicked();
    void on_btnIMUCenter_clicked();
    void on_btnIMURear_clicked();

    //STATUS
    void on_btnInvRight_clicked();
    void on_btnInvLeft_clicked();
    void on_btnUPyFront_clicked();
    void on_btnUPyRear_clicked();
    void on_btnBMSHV_clicked();
    void on_btnBMSLV_clicked();

private:
    Ui::SensorsWindow *ui;
    void ChangeSensorStatus(QPushButton*);
    void ToggleSensor(int*);
    void ToggleColor(QPushButton*);
    void MySendSerialMessage(int, std::vector<int>);

};

#endif // SENSORSWINDOW_H
