#!/bin/bash

RASP_PI_ROOT=/mnt/rasp-pi-rootfs
RASP_PI_IMAGE=~/crosscompile-tools/raspbian.img
RASP_PI_QMAKE=/mnt/rasp-pi-rootfs/usr/local/qt5pi/bin/qmake
RASP_PI_PROJECT=chimeraSteeringWheel.pro
BUILD_DIR=build-arm/
#PI_ADDRESS=192.168.43.244
#PI_ADDRESS=192.168.43.88
PI_ADDRESS=192.168.8.102
DEPLOY_TARGET_DIR=/home/pi

# Mount image needed for crosscompilation dependencies
if [ ! "$(ls -A $RASP_PI_ROOT )" ]; then
    echo "E' Vuota!"
    #94208 98304 è variabile
    #Da parametrizzare usando gli array con $USER e block size (maggiore scalabilità)
    #if ["$USER" == "lucagump"]; then
    sudo mount -o loop,offset=$((512 * 94208)) $RASP_PI_IMAGE $RASP_PI_ROOT 
    #else 
        # sudo mount -o loop,offset=$((512 * 532480)) $RASP_PI_IMAGE $RASP_PI_ROOT 
    #fi
fi

if [ ! "$( ls -A $BUILD_DIR)" ]; then
    mkdir $BUILD_DIR
fi

cd $BUILD_DIR

$RASP_PI_QMAKE -spec devices/linux-rasp-pi-g++ -o Makefile ../$RASP_PI_PROJECT
make

#new host
#pi@eaglepi eaglepi

# Upload executable on the Rasp
scp ChimeraSteeringWheel root@$PI_ADDRESS:/
