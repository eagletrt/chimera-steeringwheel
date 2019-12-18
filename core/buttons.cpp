#include "../header/buttons.h"
#include <QDebug>

/*

This class is used to handle events from rpi gpio

Encoder 1-2-3

100  1        106  1        108   1
101  2        107  2        109   2
102  3        115  3        110   3
103  4        113  4        111   4  
104  5        114  5        112   5
105  6        112  6        113   6

Buttons:

paddle top L/R  108/109
paddle bottom L/R  

bottom left/right 110/111

*/

Buttons::Buttons(QGuiApplication *app){

    // Init GPIO access
    wiringPiSetup();
    mcp23017Setup (100, 0x20) ;
    // Create a timer
    timer = new QTimer(this);

    pinMap = QVector<int>();
    pinState = QVector<int>();
    previusPinState = QVector<int>();
    btnState = QVector<int>();

    btnAction = -1;
    map = -1;
    oldMap = -1;
    pump = -1;
    oldPump = -1;
    tc = -1;
    oldTc = -1;

    switchTimer = QTime();
    switchTimer.start();

    isBackFromMap6 = false;
    isBackFromMap3 = false;
    switchIsWrong = false;

    pinEnabled = {2,3,4,5,7,21,23,25,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115};

    for (int i=0; i < pinEnabled.size(); i++) {
        pinMode(pinEnabled[i], INPUT);
        pullUpDnControl(pinEnabled[i], PUD_UP);

        pinState.append(1);
        previusPinState.append(1);
        btnState.append(BTN_NORMAL);
    }

    // Setup signal/slot mechanism
    connect(timer, SIGNAL(timeout()),this, SLOT(readGPIOState()));

    // Start timer
    timer->start(30);
}

void Buttons::readGPIOState(){
  // Controllo degli input di Raspberry

    for (int i=0; i < pinEnabled.size(); i++) {
        pinState[i] = digitalRead(pinEnabled.at(i));

        if (pinState.at(i) != previusPinState.at(i)) {
            btnAction = -1;

            // qDebug() << "####### PIN " << pinEnabled[i] << "is " << pinState[i] << " #######";

            switch (btnState.at(i)) {
                case BTN_NORMAL:
                    btnState[i] = BTN_PRESSED;
                    btnAction = BTN_PRESSED;
                break;
                case BTN_PRESSED:
                    btnState[i] = BTN_NORMAL;
                    btnAction = BTN_NORMAL;
                break;
            }

            // Emit btn events
            switch (pinEnabled[i]) {
                case BTN_TOP_LEFT:
                    emitBtnEvent(0, btnAction);
                break;
                case BTN_BOTTOM_LEFT:
                    emitBtnEvent(1, btnAction);
                break;
                case BTN_BOTTOM_RIGHT:
                    emitBtnEvent(2, btnAction);
                break;
                case BTN_TOP_RIGHT:
                    emitBtnEvent(3, btnAction);
                break;
                case PADDLE_LEFT:
                    emitBtnEvent(4, btnAction);
                break;
                case PADDLE_RIGHT:
                    emitBtnEvent(5, btnAction);
                break;
            }

            int pump = -1;
            int map = -1;
            int tc = -1;

            // Change Maps
            switch((pinEnabled[i])) {
            case PUMP_1:
                pump = 1;
            break;
            case PUMP_2:
                pump = 2;
            break;
            case PUMP_3:
                pump = 3;
            break;
            case PUMP_4:
                pump = 4;
            break;
            case PUMP_5:
                pump = 5;
            break;
            case PUMP_6:
                pump = 6;
            break;
            case MAP_1:
                map = 1;
            break;
            case MAP_2:
                map = 2;
            break;
            case MAP_3:
                map = 3;
            break;
            case MAP_4:
                map = 4;
            break;
            case MAP_5:
                map = 5;
            break;
            case MAP_6:
                map = 6;
            break;
            case TC_1:
                tc = 1;
            break;
            case TC_2:
                tc = 2;
            break;
            case TC_3:
                tc = 3;
            break;
            case TC_4:
                tc = 4;
            break;
            case TC_5:
                tc = 5;
            break;
            case TC_6:
                tc = 6;
            break;
            }

            if ((map != -1 && map != oldMap) || (pump != -1 && pump != oldPump) || (tc != -1 && tc != oldTc)) {
                
                int timeElapsed = switchTimer.restart();

                if (timeElapsed < 15) {
                    switchIsWrong = true;
                }

                if (!switchIsWrong) {
                    if(map != -1 && map != oldMap){
                        mapChanged(map);
                        oldMap = map;
                    }
                    if(pump != -1 && pump != oldPump){
                        pumpChanged(pump);
                        oldPump = pump;
                    }
                    if(tc != -1 && tc != oldTc){
                        tcChanged(tc);
                        oldTc = tc;
                    }
                }

                switchIsWrong = false;
            }
        }

      previusPinState[i] = pinState.at(i);
    }
}

void Buttons::emitBtnEvent(int btnId, int btnAction) {
    if (btnAction == BTN_PRESSED) {
        emit btnPressed(btnId);
    } else {
       emit btnReleased(btnId);
       emit btnClicked(btnId);
    }
}
        
