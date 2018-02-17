#!/bin/bash

QMAKE="/home/$USER/Qt/5.7/gcc_64/bin/qmake"
QT_PROJECT="SimulatoreSensori.pro"
BUILD_DIR_SIM=../../SimulatoreSensori/build/
BUILD_DIR_VOL=../Volante/build/

#crea seriali in volante/build
cd $BUILD_DIR_VOL
socat -d -d pty,raw,nonblock,echo=0,link=ttyV0 pty,raw,nonblock,echo=0,link=ttyV1 &

#torna in SimulatoreSensori/build/
cd $BUILD_DIR_SIM

$QMAKE $QT_PROJECT -o Makefile ../$QT_PROJECT
make 

./SimulatoreSensori
