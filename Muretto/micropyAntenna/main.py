import pyb
import sys
from pyb import CAN

# Blue LED for Signaling correct functioning
pyb.LED(4).on()

# Global FLAGs for Debug/Configuration
FAKE_MODE_ENABLED = True

###########################
# ENABLE AND INIT CAN BUS #
###########################

# Init can on the bus 1
# CAN.NORMAL is for actually communicating over the bus
can = CAN(1, CAN.NORMAL)
# Set filter for listening. You ONLY listen to IDS that are in some
# filter. Listening means that the controller reads packages on the
# channel and save them ONLY IF their ID is in some filter bank.
# We can create up to 14 banks, with up to 4 IDS per bank 
can.setfilter(0, CAN.LIST16, 0, (0xDF,0xDD,0xEC,0xEF))
can.setfilter(1, CAN.LIST16, 0, (0x201,0x202,0x181,0x182))
can.setfilter(2, CAN.LIST16, 0, (0x7e3,0xDB,0xAF,0x7ec))
can.setfilter(3, CAN.LIST16, 0, (0xEA,0xDA,0xEB,0xED))
can.setfilter(4, CAN.LIST16, 0, (0xDC,0x7EB,0xFA,0xFB))
can.setfilter(5, CAN.LIST16, 0, (0x40,10,0xF0,0x51))
can.setfilter(6, CAN.LIST16, 0, (0xFA,0xFB,0xFC,0xFD))
can.setfilter(7, CAN.LIST16, 0, (0xAA,0xAB,0xCA,0xCB))
can.setfilter(8, CAN.LIST16, 0, (0x7aa,0xbb,0xbc,0x7dd))
can.setfilter(9, CAN.LIST16, 0, (0x7bb,0x7cc,0x7ee,0x7ff))

# Set CAN Frequency/Speed, in KB/s.
# Possible speed: [125,250,500,1000] KB/s
can_freq = 1000

# Set frequency for the CAN bus by setting the prescaler value.
# The baudrate (bitrate) of the CANBUS (=speed) is the frequency of the
# micropython divided by the prescaler factor 
# Lower prescaler == higher CAN speed
if can_freq == 125:
    can.init(CAN.NORMAL, extframe=False, prescaler=16, sjw=1, bs1=14,bs2=6)
elif can_freq == 250:
    can.init(CAN.NORMAL, extframe=False, prescaler=8, sjw=1, bs1=14, bs2=6)
elif can_freq == 500:
    can.init(CAN.NORMAL, extframe=False, prescaler=4, sjw=1, bs1=14,bs2=6)
else:
    can.init(CAN.NORMAL, extframe=False, prescaler=2, sjw=1, bs1=14, bs2=6)

########################################
# SET BOARD FUNCTION BASED ON USE FILE # 
########################################

# Based on the file present on the Filesystem get the use of this board
try:
    boardTarget = open("USE", "r").read()
except:
    boardTarget = "DEBUG"

print("BoardTarget: {0}".format(boardTarget))

if boardTarget == "DEBUG":
    print("Debug mode...")
    print("Inseririre un nuovo Target")

    # Signal that we are in debug mode and not in the "right" one
    pyb.LED(4).off()
    pyb.LED(1).on()
    pyb.LED(2).on()

    while True:
        pass

if boardTarget == "MYPY":
    from Mypy import Mypy

    mypy = Mypy(can = can, fake_mode=FAKE_MODE_ENABLED)
    mypy.loop()

if boardTarget == "BMS_HV":
    print("Starting BMS_HV loop")

if boardTarget == "BMS_LV":
    from BMS_LV import BMS_LV

    bms = BMS_LV(can)
    bms.loop()

if boardTarget == "STEER_CAN":
    from SteerCan import SteerCan

    steer_can = SteerCan(can)
    steer_can.loop()

if boardTarget == "LORA":
    from Lora import Lora

    lora = Lora()
    #lora.loop()

###########################
# FIRMWARE UPDATE VIA CAN # 
###########################

# There only if there are updates
print("Updates on the Mypy")

"""

# Ack starting Update
can.send(bytearray([boardID, 0x1]), 0x41)

# Get if there are updates
updatesFinished = False

while not updatesFinished:
    recvFile(can)

    # Ask if there are more updates
    can.send(bytearray([boardID, 0x2]), 0x41)
    
    while True:
        if can.any(0):
            mid, nu1, nu2, msg = can.recv(0)

            if mid == 0x40:
                if msg[0] == 0x1:
                    updatesFinished = True
                break

# Reboot the Pyboard
sys.exit()
"""

