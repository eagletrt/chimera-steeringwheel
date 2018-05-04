#!/bin/bash

QMAKE="/home/$USER/Qt/5.7/gcc_64/bin/qmake"
QT_PROJECT="EagleSteeringWheel_x86.pro"
BUILD=build/

if [ "$( ls -A $BUILD)" ]; then
    rm -rf build
fi
mkdir build
cd $BUILD

socat -d -d pty,raw,nonblock,echo=0,link=ttyV0 pty,raw,nonblock,echo=0,link=ttyV1 &

$QMAKE $QT_PROJECT -o Makefile ../$QT_PROJECT
make || exit 1

./EagleSteeringWheel_x86
