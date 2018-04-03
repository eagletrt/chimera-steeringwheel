#include "sensorswindow.h"
#include <QApplication>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QQuickView *qmlView = new QQuickView();

    //inizializzati all interno di sensorswindow.cpp dopo aver fatto la widget del volante
    CarStatusSim* carStatus; //= new CarStatus();
    CanbusSim* canInterface; //= new Canbus(carStatus, SERIAL_PORT_V1);

    SensorsWindow* w = new SensorsWindow(carStatus, canInterface, qmlView);

    qDebug() << "main";
    qmlView->show();
    w->show();

    return a.exec();
}
