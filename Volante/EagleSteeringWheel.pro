######################################################################
# Automatically generated by qmake (3.0) mer giu 28 23:47:31 2017
######################################################################

TEMPLATE = app
TARGET = EagleSteeringWheel 
INCLUDEPATH += . \
               lib/
              
               

QT += core gui qml quick serialport

# Input
HEADERS += buttons.h \
           console.h \
           canbus.h \ 
           carstatus.h

SOURCES += main.cpp \
           buttons.cpp \
           console.cpp \
           canbus.cpp \
           carstatus.cpp

RESOURCES += qml.qrc

#LIBS += -L/usr/local/lib -lwiringPi
LIBS += -Llib -lwiringPi