#include "buttons.h"
#include <QDebug>

#define BTN_TOP_LEFT        18
#define BTN_TOP_RIGHT       20
/*rotto
#define BTN_BOTTOM_LEFT
#define BTN_BOTTOM_RIGHT
#define PADDLE_LEFT
#define PADDLE_RIGHT
*/

// 4 27 22 23 24 5
#define MAP_1              7
#define MAP_2              2
#define MAP_3              3
#define MAP_4              4
#define MAP_5              5
#define MAP_6              16

Buttons::Buttons(QGuiApplication *app)
{
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
   preOldMap = -1;

   switchTimer = QTime();
   switchTimer.start();

   isBackFromMap6 = false;
   isBackFromMap3 = false;
   switchIsWrong = false;

   pinEnabled = {2,3,4,5,7,16,18,20,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115};

   /*
      1-
      2-
      3-
      4-7
      5-
      6-
   */

   //pinEnabled = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,21,22,23,24,25,26,27,28,29,30,31,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115};

   printf ("Raspberry Pi - MCP23017 Test\n") ;

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
   qDebug() << "Emitting " << btnAction << " on " << btnId;
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

         qDebug() << "Changed pinState at " << i;

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
            /*case BTN_BOTTOM_LEFT:
            emitBtnEvent(1, btnAction);
            break;
            case BTN_BOTTOM_RIGHT:
            emitBtnEvent(2, btnAction);
            break;*/
            case BTN_TOP_RIGHT:
            emitBtnEvent(3, btnAction);
            break;/*
            case PADDLE_LEFT:
            emitBtnEvent(4, btnAction);
            break;
            case PADDLE_RIGHT:
            emitBtnEvent(5, btnAction);
            break;*/
         }


         int map = -1;

         // Change Maps
         switch(i) {
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
      }

      previusPinState[i] = pinState.at(i);
   }
}
