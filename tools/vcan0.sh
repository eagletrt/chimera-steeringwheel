#!/bin/bash

sudo modprobe vcan
sudo ip link add dev can0 type vcan
sudo ifconfig can0 up
