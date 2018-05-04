#!/bin/bash

QMAKE="/home/$USER/Qt/5.7/gcc_64/bin/qmake"
QT_PROJECT_SIM="SimulatoreSensori.pro"
QT_PROJECT_VOL="EagleSteeringWheel_x86.pro"
DIR_VOL=../Volante/
BUILD=build/

#go to Volante directory + clean + compile + connect serial
cd $DIR_VOL
if [ "$( ls -A $BUILD)" ]; then
    rm -rf build
fi
mkdir build
cd $BUILD
socat -d -d pty,raw,nonblock,echo=0,link=ttyV0 pty,raw,nonblock,echo=0,link=ttyV1 &
$QMAKE $QT_PROJECT_VOL -o Makefile ../$QT_PROJECT_VOL
make || exit 1

#go back in SimulatoreSensori directory + clean + compile
cd ../../SimulatoreSensori
if [ "$( ls -A $BUILD)" ]; then
    rm -rf build
fi
mkdir build
cd $BUILD

$QMAKE $QT_PROJECT_SIM -o Makefile ../$QT_PROJECT_SIM
make || exit 1

./SimulatoreSensori
