#include <QDebug>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>

#include "../header/buttons.h"

#include "../header/canbus.h"
#include "../header/carstatus.h"
#include "../header/console.h"

int main(int argc, char *argv[]) {
  qDebug() << "Running ARM";

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

  QObject::connect(&buttons, &Buttons::ecuControlChanged, &carStatus,
                   &CarStatus::changeEcuControl);

  view->rootContext()->setContextProperty("Buttons", &buttons);
  view->rootContext()->setContextProperty("CAN", &canInterface);
  view->rootContext()->setContextProperty("CarStatus", &carStatus);

  view->setSource(QUrl("qrc:///qml/main.qml"));
  view->show();

  return app.exec();
}
