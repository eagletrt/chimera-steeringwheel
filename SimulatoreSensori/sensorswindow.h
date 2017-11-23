#ifndef SENSORSWINDOW_H
#define SENSORSWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QQuickView>
#include "canbusSim.h"
#include "carstatusSim.h"
#include "../Volante/canbus.h"
#include "../Volante/carstatus.h"

#define SERIAL_PORT_V1 "../../Volante/build/ttyV1"
#define SERIAL_PORT_V0 "../../Volante/build/ttyV0"

namespace Ui {
class SensorsWindow;
}

class SensorsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SensorsWindow(CarStatusSim* car, CanbusSim* canInterface, QQuickView* qml, QWidget *parent = 0);
    ~SensorsWindow();

private slots:
    void parseMessage();

    //BUTTONS VOLANTE
    void on_btnVolanteQ_clicked();
    void on_btnVolanteA_clicked();
    void on_btnVolanteD_clicked();
    void on_btnVolanteR_clicked();
    void on_sbVolanteManettino_valueChanged(int arg1);

    //INVERTER TAB EVENTS
    void on_btnInvSx_clicked();
    void on_btnInvDx_clicked();
    void on_btnPreCh_clicked();

    //ERRORS TAB EVENTS
    void on_btnApps_clicked();
    void on_btnBSE_clicked();
    void on_btnSteer_clicked();
    void on_btnWheelLeft_clicked();
    void on_btnWheelRight_clicked();
    void on_btnIMUFront_clicked();
    void on_btnIMUCenter_clicked();
    void on_btnIMURear_clicked();

    //STATUS TAB EVENTS
    void on_btnInvRight_clicked();
    void on_btnInvLeft_clicked();
    void on_btnUPyFront_clicked();
    void on_btnUPyRear_clicked();
    void on_btnBMSHV_clicked();
    void on_btnBMSLV_clicked();

    //SENSORS TAB EVENTS
    void on_sliderApps_valueChanged(int value);
    void on_btnErrApps1_clicked();
    void on_btnErrApps2_clicked();
    void on_btnErrApps3_clicked();
    void on_btnErrApps4_clicked();
    void on_btnErrApps5_clicked();
    void on_sliderBse_valueChanged(int value);
    void on_btnErrBse1_clicked();
    void on_btnErrBse2_clicked();
    void on_btnErrBse3_clicked();
    void on_btnErrBse4_clicked();
    void on_sliderSteer_valueChanged(int value);
    void on_btnErrSteer1_clicked();

private:
    Ui::SensorsWindow *ui;
    void ChangeSensorStatus(QPushButton*);
    void SetInteger(int*,int);
    void ToggleErrorBit(int*, int);
    void ToggleSensor(int*);
    void ToggleColor(QPushButton*);

};

#endif // SENSORSWINDOW_H
