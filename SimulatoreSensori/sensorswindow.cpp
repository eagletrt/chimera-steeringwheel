#include "sensorswindow.h"
#include "ui_sensorswindow.h"
#include "buttons_x86Sim.h"
#include <QtQuick/QQuickView>
#include <QFileInfo>
#include <QQmlContext>

using namespace std;

/*Widget Data Structures*/
QApplication *app;
CarStatus carStatus;
Buttons* buttons;
Canbus* canInterface;

/*Car Data Structures*/
CarStatusSim* carStatusSim;
CanbusSim* canInterfaceSim;
vector<int> hvSensors {0, 0, 0}; //right, left, pre
vector<int> errorSensors {0, 0, 0, 0, 0, 0, 0, 0}; //Accel, Brake, Steer, WheelDx, WheelSx, IMUFront, IMUCenter, IMURear
vector<int> statusSensors {0, 0, 0, 0, 0, 0}; //dx, sx, pyFront, pyRear, HV, LV

//toggled bit in index position inside int indicate error in index position (es: 1 App error toggles bit 0 of int errApps)
vector<int> statusAPPSeBSE {0,0,0,0}; //Apps, #errApps, BSE, #errBse
vector<int> statusSTEER {0,0}; //Steer, errSteer

SensorsWindow::SensorsWindow(CarStatusSim* car, CanbusSim* can, QQuickView* qmlView, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SensorsWindow)
{
    ui->setupUi(this);


    //add widget with steering wheel interface
    app = (QApplication*)QApplication::instance();
    buttons = new Buttons(app);
    canInterface = new Canbus (&carStatus, SERIAL_PORT_V0);

    QObject::connect(buttons, &Buttons::presetChanged,
                     &carStatus, &CarStatus::changePreset);

    qmlView->rootContext()->setContextProperty("Buttons", buttons);
    qmlView->rootContext()->setContextProperty("CAN", canInterface);
    qmlView->rootContext()->setContextProperty("CarStatus", &carStatus);

    qmlView->setSource(QUrl::fromLocalFile(QFileInfo("../../Volante/main.qml").absoluteFilePath()));

    QVBoxLayout *layout = new QVBoxLayout(ui->widget);
    QWidget *container = QWidget::createWindowContainer(qmlView);
    layout->addWidget(container);

    qDebug() << "volante creato";

    //Initialize CarStatus and Canbus that I declared inside main.cpp
    car = new CarStatusSim();
    can = new CanbusSim(car, SERIAL_PORT_V1);

    carStatusSim = car;
    canInterfaceSim = can;

    QObject::connect(&(canInterfaceSim->serial), SIGNAL(readyRead()), this, SLOT(parseMessage()));
}

SensorsWindow::~SensorsWindow()
{
    delete ui;
}

//Events onClick for virtual steering wheel buttons(QADR) + manettino(spin box)
void SensorsWindow::on_btnVolanteQ_clicked()
{
    emit buttons->filter->keyboardBtnClicked(0);
}
void SensorsWindow::on_btnVolanteA_clicked()
{
    emit buttons->filter->keyboardBtnClicked(1);
}
void SensorsWindow::on_btnVolanteD_clicked()
{
    emit buttons->filter->keyboardBtnClicked(2);
}
void SensorsWindow::on_btnVolanteR_clicked()
{
    emit buttons->filter->keyboardBtnClicked(3);
}
void SensorsWindow::on_sbVolanteManettino_valueChanged(int arg1)
{
    emit buttons->filter->keyboardBtnClicked(arg1+10);
}

//Events onCLick for simulator buttons when a parameter is set
//INVERTER TAB
void SensorsWindow::on_btnInvSx_clicked()
{
    ChangeSensorStatus(ui->btnInvSx);
}
void SensorsWindow::on_btnInvDx_clicked()
{
    ChangeSensorStatus(ui->btnInvDx);
}
void SensorsWindow::on_btnPreCh_clicked()
{
    ChangeSensorStatus(ui->btnPreCh);
}

//ERRORS TAB
void SensorsWindow::on_btnApps_clicked()
{
    ChangeSensorStatus(ui->btnApps);
}
void SensorsWindow::on_btnBSE_clicked()
{
    ChangeSensorStatus(ui->btnBSE);
}
void SensorsWindow::on_btnSteer_clicked()
{
    ChangeSensorStatus(ui->btnSteer);
}
void SensorsWindow::on_btnWheelLeft_clicked()
{
    ChangeSensorStatus(ui->btnWheelLeft);
}
void SensorsWindow::on_btnWheelRight_clicked()
{
    ChangeSensorStatus(ui->btnWheelRight);
}
void SensorsWindow::on_btnIMUFront_clicked()
{
    ChangeSensorStatus(ui->btnIMUFront);
}
void SensorsWindow::on_btnIMUCenter_clicked()
{
    ChangeSensorStatus(ui->btnIMUCenter);
}
void SensorsWindow::on_btnIMURear_clicked()
{
    ChangeSensorStatus(ui->btnIMURear);
}

//STATUS TAB
void SensorsWindow::on_btnInvRight_clicked()
{
    ChangeSensorStatus(ui->btnInvRight);
}
void SensorsWindow::on_btnInvLeft_clicked()
{
    ChangeSensorStatus(ui->btnInvLeft);
}
void SensorsWindow::on_btnUPyFront_clicked()
{
    ChangeSensorStatus(ui->btnUPyFront);
}
void SensorsWindow::on_btnUPyRear_clicked()
{
    ChangeSensorStatus(ui->btnUPyRear);
}
void SensorsWindow::on_btnBMSHV_clicked()
{
    ChangeSensorStatus(ui->btnBMSHV);
}
void SensorsWindow::on_btnBMSLV_clicked()
{
    ChangeSensorStatus(ui->btnBMSLV);
}

//SENSORS TAB
void SensorsWindow::on_sliderApps_valueChanged(int value)
{
    SetInteger(&statusAPPSeBSE[0], value);
}
void SensorsWindow::on_btnErrApps1_clicked()
{
    ChangeSensorStatus(ui->btnErrApps1);
}
void SensorsWindow::on_btnErrApps2_clicked()
{
    ChangeSensorStatus(ui->btnErrApps2);
}
void SensorsWindow::on_btnErrApps3_clicked()
{
    ChangeSensorStatus(ui->btnErrApps3);
}
void SensorsWindow::on_btnErrApps4_clicked()
{
    ChangeSensorStatus(ui->btnErrApps4);
}
void SensorsWindow::on_btnErrApps5_clicked()
{
    ChangeSensorStatus(ui->btnErrApps5);
}

void SensorsWindow::on_sliderBse_valueChanged(int value)
{
    SetInteger(&statusAPPSeBSE[2], value);
}
void SensorsWindow::on_btnErrBse1_clicked()
{
    ChangeSensorStatus(ui->btnErrBse1);
}
void SensorsWindow::on_btnErrBse2_clicked()
{
    ChangeSensorStatus(ui->btnErrBse2);
}
void SensorsWindow::on_btnErrBse3_clicked()
{
    ChangeSensorStatus(ui->btnErrBse3);
}
void SensorsWindow::on_btnErrBse4_clicked()
{
    ChangeSensorStatus(ui->btnErrBse4);
}

void SensorsWindow::on_sliderSteer_valueChanged(int value)
{
    SetInteger(&statusSTEER[0], value);
}
void SensorsWindow::on_btnErrSteer1_clicked()
{
    ChangeSensorStatus(ui->btnErrSteer1);
}

//FUNCTIONS

//the button pressed is passed to this function, an action is taken accordingly to the tab in which it is in
void SensorsWindow::ChangeSensorStatus(QPushButton *btn)
{
    QString btnName = btn->objectName();

    //INVERTER TAB
    if(btnName.compare("btnInvDx") == 0)
        ToggleSensor(&hvSensors[0]);
    else if(btnName.compare("btnInvSx") == 0)
        ToggleSensor(&hvSensors[1]);
    else if(btnName.compare("btnPreCh") == 0)
        ToggleSensor(&hvSensors[2]);

    //ERRORS TAB
    if(btnName.compare("btnApps") == 0)
        ToggleSensor(&errorSensors[0]);
    else if(btnName.compare("btnBSE") == 0)
        ToggleSensor(&errorSensors[1]);
    else if(btnName.compare("btnSteer") == 0)
        ToggleSensor(&errorSensors[2]);
    else if(btnName.compare("btnWheelLeft") == 0)
        ToggleSensor(&errorSensors[3]);
    else if(btnName.compare("btnWheelRight") == 0)
        ToggleSensor(&errorSensors[4]);
    else if(btnName.compare("btnIMUFront") == 0)
        ToggleSensor(&errorSensors[5]);
    else if(btnName.compare("btnIMUCenter") == 0)
        ToggleSensor(&errorSensors[6]);
    else if(btnName.compare("btnIMURear") == 0)
        ToggleSensor(&errorSensors[7]);

    //STATUS TAB
    if(btnName.compare("btnInvRight") == 0)
        ToggleSensor(&statusSensors[0]);
    else if(btnName.compare("btnInvLeft") == 0)
        ToggleSensor(&statusSensors[1]);
    else if(btnName.compare("btnUPyFront") == 0)
        ToggleSensor(&statusSensors[2]);
    else if(btnName.compare("btnUPyRear") == 0)
        ToggleSensor(&statusSensors[3]);
    else if(btnName.compare("btnBMSHV") == 0)
        ToggleSensor(&statusSensors[4]);
    else if(btnName.compare("btnBMSLV") == 0)
        ToggleSensor(&statusSensors[5]);

    //SENSORS TAB
    if(btnName.compare("btnErrApps1") == 0)
        ToggleErrorBit(&statusAPPSeBSE[1], 0);
    else if(btnName.compare("btnErrApps2") == 0)
        ToggleErrorBit(&statusAPPSeBSE[1], 1);
    else if(btnName.compare("btnErrApps3") == 0)
        ToggleErrorBit(&statusAPPSeBSE[1], 2);
    else if(btnName.compare("btnErrApps4") == 0)
        ToggleErrorBit(&statusAPPSeBSE[1], 3);
    else if(btnName.compare("btnErrApps5") == 0)
        ToggleErrorBit(&statusAPPSeBSE[1], 4);
    else if(btnName.compare("btnErrBse1") == 0)
        ToggleErrorBit(&statusAPPSeBSE[3], 0);
    else if(btnName.compare("btnErrBse2") == 0)
        ToggleErrorBit(&statusAPPSeBSE[3], 1);
    else if(btnName.compare("btnErrBse3") == 0)
        ToggleErrorBit(&statusAPPSeBSE[3], 2);
    else if(btnName.compare("btnErrBse4") == 0)
        ToggleErrorBit(&statusAPPSeBSE[3], 3);
    else if(btnName.compare("btnErrSteer1") == 0)
        ToggleErrorBit(&statusSTEER[1], 0);

    //BATTERY TAB
    //TODO

    ToggleColor(btn);
}

//value of sliders il set
void SensorsWindow::SetInteger(int* sensor, int value)
{
    *sensor = value;
    carStatusSim->setSTEERStatus(statusSTEER[0], statusSTEER[1]);
    carStatusSim->setAPPSBSEStatus(statusAPPSeBSE[0], statusAPPSeBSE[1], statusAPPSeBSE[2], statusAPPSeBSE[3]);
    carStatusSim->setHVStatus(hvSensors[0], hvSensors[1], hvSensors[2]);
    carStatusSim->setERRStatus(errorSensors[0], errorSensors[1], errorSensors[2], errorSensors[3], errorSensors[4], errorSensors[5], errorSensors[6], errorSensors[7]);
    carStatusSim->setCarStatus(statusSensors[0], statusSensors[1], statusSensors[2], statusSensors[3], statusSensors[4], statusSensors[5]);

}

//toggle single bit inside integer to indicate error in index position
void SensorsWindow::ToggleErrorBit(int* errorInt, int index)
{
    *errorInt |= 1UL << index;
    carStatusSim->setSTEERStatus(statusSTEER[0], statusSTEER[1]);
    carStatusSim->setAPPSBSEStatus(statusAPPSeBSE[0], statusAPPSeBSE[1], statusAPPSeBSE[2], statusAPPSeBSE[3]);
    carStatusSim->setHVStatus(hvSensors[0], hvSensors[1], hvSensors[2]);
    carStatusSim->setERRStatus(errorSensors[0], errorSensors[1], errorSensors[2], errorSensors[3], errorSensors[4], errorSensors[5], errorSensors[6], errorSensors[7]);
    carStatusSim->setCarStatus(statusSensors[0], statusSensors[1], statusSensors[2], statusSensors[3], statusSensors[4], statusSensors[5]);
}

//the value of the sensor is toggled between 0 and 1 (only for buttons)
void SensorsWindow::ToggleSensor(int* sensor)
{
    *sensor = (*sensor == 0 ? 1 : 0);
    carStatusSim->setSTEERStatus(statusSTEER[0], statusSTEER[1]);
    carStatusSim->setAPPSBSEStatus(statusAPPSeBSE[0], statusAPPSeBSE[1], statusAPPSeBSE[2], statusAPPSeBSE[3]);
    carStatusSim->setHVStatus(hvSensors[0], hvSensors[1], hvSensors[2]);
    carStatusSim->setERRStatus(errorSensors[0], errorSensors[1], errorSensors[2], errorSensors[3], errorSensors[4], errorSensors[5], errorSensors[6], errorSensors[7]);
    carStatusSim->setCarStatus(statusSensors[0], statusSensors[1], statusSensors[2], statusSensors[3], statusSensors[4], statusSensors[5]);
}

//the color of the button in the interface is toggled between red and green
void SensorsWindow::ToggleColor(QPushButton *btn)
{
    QString currColor = btn->palette().background().color().name();
    if(currColor.compare("#008000") == 0) //green = #008000
        btn->setStyleSheet("background-color:red;");
    else
        btn->setStyleSheet("background-color:green;");
}

//get and respond to a steering wheel request
void SensorsWindow::parseMessage()
{
    int canID;
    int canMsg;

    while(canInterfaceSim->serial.canReadLine())
    {
        QString received = canInterfaceSim->serial.readLine();
        received.remove("\n");

        //Divide the message and assign the ID and Msg part of it to the correct variables
        qDebug() << received;
        if(received.at(0) == 'c')
        {
            qDebug() << "Related to Car Status";
            return;
        }
        canID = received.split(":")[0].toInt();
        canMsg = received.split(":")[1].toInt();
        //qDebug() << "ID: " << canID << "; Msg: " << canMsg;

        //Send the requested information to the steering wheel
        switch(canID)
        {
            case CHECK_CAN_COM:
            {
                if(canMsg == 0)
                {
                    canInterfaceSim->MySendSerialMessage(GET_CAN_STATUS, statusSensors);
                }
                else if(canMsg == 1)
                {
                    qDebug() << "'mpizzo la car!";
                }
                break;
            }
            case ASK_HV_STATE_ID:
            {
                if(canMsg == 0)
                {
                    canInterfaceSim->MySendSerialMessage(GET_HV_STATE_ID, hvSensors);
                }
                else if(canMsg == 1)
                {
                    canInterfaceSim->MySendSerialMessage(GET_HV_STATE_ID, hvSensors);
                }
                else if(canMsg == 2)
                {
                    canInterfaceSim->MySendSerialMessage(GET_HV_STATE_ID, hvSensors);
                }
                break;
            }
            case CHECK_SENSOR_ERROR_ID:
            {
                canInterfaceSim->MySendSerialMessage(GET_ERRORS_STATUS, errorSensors);
                break;
            }
            case ASK_SENSORS_VALUE_ID:
            {
                canInterfaceSim->MySendSerialMessage(GET_APPS_BSE_STATUS, statusAPPSeBSE);
                canInterfaceSim->MySendSerialMessage(GET_STEER_STATUS, statusSTEER);
                break;
            }
            case ASK_BATTERY_STATUS:
            {
                qDebug() << "Tab 5";
                break;
            }
            case CHANGE_EXEC_MODE_ID:
            {
                qDebug() << "Change exec mode";
                break;
            }
        }
    }
}
