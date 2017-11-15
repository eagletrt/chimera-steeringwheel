#include "sensorswindow.h"
#include "ui_sensorswindow.h"

using namespace std;

/*Car Data Structures*/
CarStatus* carStatus;
Canbus* can;
vector<int> hvSensors {0, 0, 0}; //right, left, pre
vector<int> errorSensors {0, 0, 0, 0, 0, 0, 0, 0}; //Accel, Brake, Steer, WheelDx, WheelSx, IMUFront, IMUCenter, IMURear
vector<int> statusSensors {0, 0, 0, 0, 0, 0}; //dx, sx, pyFront, pyRear, HV, LV

SensorsWindow::SensorsWindow(CarStatus* car, Canbus* canInterface, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SensorsWindow)
{
    ui->setupUi(this);

    carStatus = car;
    can = canInterface;
    //Connect the serial to listen to messages
    connect(&(can->serial), SIGNAL(readyRead()), this, SLOT(MyParseMessage()));
}

SensorsWindow::~SensorsWindow()
{
    delete ui;
}

//Connect Clicked Events
//HV
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

//ERRORS
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

//STATUS
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

//Functions

void SensorsWindow::MyParseMessage()
{
    /*QByteArray canFrame;
    QByteArray canMsg;

    while (can->serial.canReadLine()) {
        canFrame = QByteArray();
        canMsg = QByteArray();

        canFrame = can->serial.readLine();

        //canID = *canFrame[0] << 8 | *canFrame[1];
        int canID = (int)canFrame[1];

        if (canID != 0) {
            // Init the new canMsg array
            for (int i = 0; i < 8; i++) {
                canMsg.append(canFrame.at(i+2));
            }

            qDebug() << "CAN ID: " << canID << " CAN MSG " << canMsg;
            //parseCANMessage(canID, canMsg);
        }

    }*/
}

void SensorsWindow::ChangeSensorStatus(QPushButton *btn)
{
    QString btnName = btn->objectName();

    //HV
    if(btnName.compare("btnInvDx") == 0)
        ToggleSensor(&hvSensors[0]);
    else if(btnName.compare("btnInvSx") == 0)
        ToggleSensor(&hvSensors[1]);
    else if(btnName.compare("btnPreCh") == 0)
        ToggleSensor(&hvSensors[2]);

    //ERRORS
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

    //STATUS
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


    ToggleColor(btn);
}

void SensorsWindow::ToggleSensor(int* sensor)
{
    *sensor = (*sensor == 0 ? 1 : 0);
    carStatus->setHVStatus(hvSensors[0], hvSensors[1], hvSensors[2]);
    carStatus->setERRStatus(errorSensors[0], errorSensors[1], errorSensors[2], errorSensors[3], errorSensors[4], errorSensors[5], errorSensors[6], errorSensors[7]);
    carStatus->setCarStatus(statusSensors[0], statusSensors[1], statusSensors[2], statusSensors[3], statusSensors[4], statusSensors[5]);
    //can->sendCanMessage(HV_STATE_ID, carStatus->HVStatus());

    /*QByteArray msg;
    int zero = 0;
    msg.append(zero);
    msg.append(HV_STATE_ID);
    msg.append(hvSensors[0]);
    msg.append(hvSensors[1]);
    msg.append(hvSensors[2]);
    msg.append(zero);
    msg.append(zero);
    msg.append(zero);
    msg.append(zero);
    msg.append(zero);
    msg.append("\n");
    can->serial.write(msg.toStdString().c_str(), msg.length());*/

    MySendSerialMessage(HV_STATE_ID, hvSensors);
    MySendSerialMessage(GET_ERRORS_STATUS, errorSensors);
    MySendSerialMessage(GET_CAN_STATUS, statusSensors);
}

void SensorsWindow::MySendSerialMessage(int id, vector<int> values)
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
    can->serial.write(msg.toStdString().c_str(), msg.length());
}

void SensorsWindow::ToggleColor(QPushButton *btn)
{
    QString currColor = btn->palette().background().color().name();
    if(currColor.compare("#008000") == 0) //green = #008000
        btn->setStyleSheet("background-color:red;");
    else
        btn->setStyleSheet("background-color:green;");
}
