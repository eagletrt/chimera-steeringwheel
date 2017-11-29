#include <QGuiApplication>
#include <QDebug>
#include <QQuickView>
#include <QQmlContext>

#include "buttons.h"

#include "console.h"
#include "canbus.h"
#include "carstatus.h"

const QString SERIAL_PORT = "/dev/ttyAMA0";

int main(int argc, char* argv[]) 
{
    qDebug() << "Running in raspiARM mode";
    qDebug() << "Start Core Application...";

    QGuiApplication app(argc, argv);
    QQuickView* view = new QQuickView();

    Buttons buttons(&app);
    Console logger;
    CarStatus carStatus;
    Canbus canInterface(&carStatus, SERIAL_PORT);

    QObject::connect(&buttons, &Buttons::presetChanged,
                     &carStatus, &CarStatus::changePreset);

    view->rootContext()->setContextProperty("Buttons", &buttons);
    view->rootContext()->setContextProperty("CAN", &canInterface);
    view->rootContext()->setContextProperty("CarStatus", &carStatus);

    view->setSource(QUrl("qrc:///main.qml"));
    view->show();

    /*
    QObject::connect(&timer, &MyTimer::btnClicked,
            &logger, &Console::onClicked);

    QObject::connect(&timer, &MyTimer::btnPressed,
            &logger, &Console::onPressed);

    QObject::connect(&timer, &MyTimer::btnReleased,
            &logger, &Console::onReleased);
    */

    return app.exec();
}