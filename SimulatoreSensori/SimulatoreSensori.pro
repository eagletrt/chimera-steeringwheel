#-------------------------------------------------
#
# Project created by QtCreator 2017-10-28T10:36:19
#
#-------------------------------------------------

QT       += core gui serialport qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimulatoreSensori
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        sensorswindow.cpp \
        canbusSim.cpp \
        carstatusSim.cpp \
        ../Volante/canbus.cpp \
        ../Volante/carstatus.cpp \
        buttons_x86Sim.cpp \
        keypresseventfilterSim.cpp


HEADERS += \
        sensorswindow.h \
        canbusSim.h \
        carstatusSim.h \
        ../Volante/canbus.h \
        ../Volante/carstatus.h \
        buttons_x86Sim.h \
        keypresseventfilterSim.h

FORMS += \
        sensorswindow.ui
