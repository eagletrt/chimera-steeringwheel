#include "sensorswindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CarStatus* carStatus = new CarStatus();
    Canbus* canInterface = new Canbus(carStatus, SERIAL_PORT);
    SensorsWindow* w = new SensorsWindow(carStatus, canInterface);

    w->show();

    return a.exec();
}
