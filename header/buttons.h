#ifndef BUTTONS_H
#define BUTTONS_H

#include <QTimer>
#include <QVector>
#include <QGuiApplication>
#include <QTime>

#include "lib/mcp23017.h"
#include "lib/wiringPi.h"

#define BTN_TOP_LEFT       110
#define BTN_TOP_RIGHT      108
#define BTN_BOTTOM_LEFT    111
#define BTN_BOTTOM_RIGHT   25
#define PADDLE_BTM_LEFT    109
#define PADDLE_BTM_RIGHT   23
#define PADDLE_TOP_LEFT    111109
#define PADDLE_TOP_RIGHT   1111009
#define PADDLE_LEFT        109
#define PADDLE_RIGHT       23

#define MAP_1              7
#define MAP_2              2
#define MAP_3              3
#define MAP_4              4
#define MAP_5              5
#define MAP_6              21

#define PUMP_1             106
#define PUMP_2             107
#define PUMP_3             115
#define PUMP_4             113
#define PUMP_5             114
#define PUMP_6             112

// TODO: Traction control
#define TC_1              971111
#define TC_2              921111
#define TC_3              931111
#define TC_4              941111
#define TC_5              951111
#define TC_6              911111

class Buttons : public QObject
{
    Q_OBJECT
    public:
        Buttons(QGuiApplication *app);
        QTimer *timer;
        enum Constants {
            BTN_NORMAL = 0,
            BTN_PRESSED = 1,
        };

        int btnAction;
        int map;
        int oldMap;
        int pump;
        int oldPump;
        int tc;
        int oldTc;

    public slots:
        void readGPIOState();
        void changeEncoders(int gpio);

    signals:
        void btnClicked(int btnID);
        void btnPressed(int btnID);
        void btnReleased(int btnID);
        void mapChanged(int mapID);
        void pumpChanged(int pumpID);
        void tcChanged(int tcID);

    private:

        bool isBackFromMap6;
        bool isBackFromMap3;
        bool switchIsWrong;

        QTime switchTimer;

        QVector<int> pinMap;
        QVector<int> pinState;
        QVector<int> btnState;
        QVector<int> previusPinState;

        QVector<int> pinEnabled;

        void emitBtnEvent(int btnId, int btnAction);
};

#endif // BUTTONS_H
