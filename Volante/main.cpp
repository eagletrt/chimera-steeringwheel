#include <QGuiApplication>
#include <QDebug>
#include <QQuickView>
#include <QQmlContext>

#include "buttons.h"

#include "console.h"
#include "canbus.h"
#include "carstatus.h"

const QString CAN_INTERFACE = "socketcan";

int main(int argc, char* argv[])
{
    qDebug() << "Running in raspiARM mode";
    qDebug() << "Start Core Application...";

    QGuiApplication app(argc, argv);
    QQuickView* view = new QQuickView();

    Buttons buttons(&app);
    Console logger;
    CarStatus carStatus;
    Canbus canInterface(&carStatus, CAN_INTERFACE);

    QObject::connect(&buttons, &Buttons::presetChanged,
                     &carStatus, &CarStatus::changePreset);

    view->rootContext()->setContextProperty("Buttons", &buttons);
    view->rootContext()->setContextProperty("CAN", &canInterface);
    view->rootContext()->setContextProperty("CarStatus", &carStatus);

    view->setSource(QUrl("qrc:///main.qml"));
    view->show();

    return app.exec();
}
