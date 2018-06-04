#include "buttons.h"
#include <QDebug>

/*
 * OLD CONFIGURATION - Raspi Zero W *
#define BTN_TOP_LEFT        12
#define BTN_BOTTOM_LEFT     14
#define BTN_BOTTOM_RIGHT    20
#define BTN_TOP_RIGHT       22
*/

#define BTN_TOP_LEFT        14
#define BTN_BOTTOM_LEFT     13
#define BTN_BOTTOM_RIGHT    12
#define BTN_TOP_RIGHT       0
#define PADDLE_LEFT         8
#define PADDLE_RIGHT        7

#define MAP_0               11
//#define MAP_1               8
#define MAP_2               10
#define MAP_3               13
#define MAP_4               9
//#define MAP_5               7
//#define MAP_6               16

/*
  Bisogna decidere i GPIO per i vari bottoni.
  la libreria wiringPi va scommentata
  come anche tutte le varie chiamate
  i commenti sono quelli all'inizio della riga
*/

Buttons::Buttons(QGuiApplication *app)
{
    // Init GPIO access
    wiringPiSetup();

    // Create a timer
    timer = new QTimer(this);

    pinMap = QVector<int>();
    pinState = QVector<int>();
    previusPinState = QVector<int>();
    btnState = QVector<int>();

    btnAction = -1;
    map = -1;
    oldMap = -1;
    preOldMap = -1;

    switchTimer = QTime();
    switchTimer.start();

    isBackFromMap6 = false;
    isBackFromMap3 = false;
    switchIsWrong = false;

    pinEnabled = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,18,21,22,23,24,25,26,27,28,29,30,31};//add 28

    for (int i=0; i < pinEnabled.size(); i++) {
        pinMode(pinEnabled[i], INPUT);
        pullUpDnControl(pinEnabled[i], PUD_UP);

        pinState.append(1);
        previusPinState.append(1);
        btnState.append(BTN_NORMAL);
    }

    // Setup signal/slot mechanism
    connect(timer, SIGNAL(timeout()),
            this, SLOT(readGPIOState()));

    // Start timer
    timer->start(30);
}

void Buttons::emitBtnEvent(int btnId, int btnAction) {
    //qDebug() << "Emitting " << btnAction << " on " << btnId;
    if (btnAction == BTN_PRESSED) {
        emit btnPressed(btnId);
    } else {
        emit btnReleased(btnId);
        emit btnClicked(btnId);
    }
}

void Buttons::readGPIOState()
{
    // Controllo degli input di Raspberry

    for (int i=0; i < pinEnabled.size(); i++) {
        pinState[i] = digitalRead(pinEnabled.at(i));

        if (pinState.at(i) != previusPinState.at(i)) {
            btnAction = -1;

            //qDebug() << "Changed pinState at " << i;

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
            switch (i) {
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

            /*

            int map = -1;

            // Change Maps
            switch(i) {
                case MAP_0:
                    map = 1;
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
            }

            if (map != -1 && map != oldMap) {

                int timeElapsed = switchTimer.restart();

                if (timeElapsed < 15) {
                    switchIsWrong = true;
                }

                if (!switchIsWrong) {
                    presetChanged(map);
                    oldMap = map;
                }

                switchIsWrong = false;
            }
        */
        }

        previusPinState[i] = pinState.at(i);
    }
}
