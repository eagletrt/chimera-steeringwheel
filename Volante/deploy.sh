#!/bin/bash

QT_PROJECT="EagleSteeringWheel_x86.pro"
BUILD_DIR=build/

cd $BUILD_DIR

socat -d -d pty,raw,nonblock,echo=0,link=ttyV0 pty,raw,nonblock,echo=0,link=ttyV1 &

qmake $QT_PROJECT -o Makefile ../$QT_PROJECT
make 

./EagleSteeringWheel_x86
