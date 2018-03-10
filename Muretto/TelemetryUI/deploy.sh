#!/bin/bash

QMAKE="/home/$USER/Qt/5.7/gcc_64/bin/qmake"
QT_PROJECT="BatteryGraph.pro"

cd build

sudo chmod 777 /dev/ttyUSB0
$QMAKE $QT_PROJECT -o Makefile ../$QT_PROJECT
make 

./BatteryGraph
