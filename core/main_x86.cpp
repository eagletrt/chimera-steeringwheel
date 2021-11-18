#include <QDebug>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>

#include "../header/buttons_x86.h"

#include <QCanBus>

#include "../header/canbus.h"
#include "../header/carstatus.h"
#include "../header/console.h"

int main(int argc, char *argv[]) {
  qDebug() << "Running x86";

  QGuiApplication app(argc, argv);
  QQuickView *view = new QQuickView();

  Buttons buttons(&app);
  Console logger;
  CarStatus carStatus;
  Canbus canInterface(&carStatus);

  QObject::connect(&buttons, &Buttons::presetChanged, &carStatus,
                   &CarStatus::changePreset);

  QObject::connect(&buttons, &Buttons::pumpChanged, &carStatus,
                   &CarStatus::changePump);

  view->rootContext()->setContextProperty("Buttons", &buttons);
  view->rootContext()->setContextProperty("CAN", &canInterface);
  view->rootContext()->setContextProperty("CarStatus", &carStatus);

  // QObject::connect(&carStatus, &CarStatus::showPopup, &carStatus,
  //                  [](const QString &message) {
  //                    qDebug() << message;
  //                  });

  view->setSource(QUrl("qrc:///qml/main.qml"));
  view->show();

  return app.exec();
}
