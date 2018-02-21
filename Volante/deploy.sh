#!/bin/bash

QMAKE="/home/$USER/Qt/5.7/gcc_64/bin/qmake"
QT_PROJECT="EagleSteeringWheel_x86.pro"
BUILD_DIR=build/

cd $BUILD_DIR

socat -d -d pty,raw,nonblock,echo=0,link=ttyV0 pty,raw,nonblock,echo=0,link=ttyV1 &

$QMAKE $QT_PROJECT -o Makefile ../$QT_PROJECT
make 

./EagleSteeringWheel_x86
