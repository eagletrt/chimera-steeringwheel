#########################################################
#  _________ __                      .__                #
# /   _____//  |_  ____   ___________|__| ____    ____  #
# \_____  \\   __\/ __ \_/ __ \_  __ \  |/    \  / ___\ #
# /        \|  | \  ___/\  ___/|  | \/  |   |  \/ /_/  >#
#/_______  /|__|  \___  >\___  >__|  |__|___|  /\___  / #
#        \/           \/     \/              \//_____/  #
#########################################################

TEMPLATE = app
TARGET = ChimeraSteeringWheel
INCLUDEPATH += . \
               lib/

QT += core gui qml quick serialbus 
CONFIG += qtquickcompiler

# Input
HEADERS += header/buttons.h \
           header/console.h \
           header/canbus.h \
           header/carstatus.h \
           header/inverters.h

SOURCES += core/main.cpp \
           core/buttons.cpp \
           core/console.cpp \
           core/canbus.cpp \
           core/carstatus.cpp
           core/inverters.cpp \

RESOURCES += qml.qrc

LIBS += -L/usr/local/lib -lwiringPi
#LIBS += -Llib -lwiringPi
