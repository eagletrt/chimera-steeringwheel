TEMPLATE = app

QT += qml quick widgets serialport

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    arduinomgr.cpp

RESOURCES += qml.qrc

QML_IMPORT_PATH =


include(deployment.pri)

DISTFILES += \
    arduino.qml

HEADERS += \
    arduinomgr.h
