#ifndef BUTTONS_X86SIM_H
#define BUTTONS_X86SIM_H

#include <QVector>
#include <QGuiApplication>

#include "keypresseventfilterSim.h"

class Buttons : public QObject
{
    Q_OBJECT
    public:
        Buttons(QGuiApplication *app);
        KeyPressEventFilterSim *filter;

    signals:
        void btnClicked(int btnID);
        void btnPressed(int btnID);
        void btnReleased(int btnID);
        void presetChanged(int presetID);

    public slots:
        void handleKeyboardPress(int btnID);

    private:
        enum Constants {
            BTN_NORMAL = 0,
            BTN_PRESSED = 1,
        };

        int counter;
        QVector<int> pinMap;
        QVector<int> pinState;
        QVector<int> btnState;
        QVector<int> previusPinState;
};

#endif // BUTTONS_X86SIM_H

