#!/bin/bash

QMAKE="/home/$USER/Qt/5.7/gcc_64/bin/qmake"
QT_PROJECT="Muretto.pro"
BUILD=build/

if [ ! "$( ls -A $BUILD)" ]; then
    mkdir $BUILD
fi

cd $BUILD

sudo chmod 777 /dev/ttyUSB0
$QMAKE $QT_PROJECT -o Makefile ../$QT_PROJECT
make || exit 1

./Muretto
