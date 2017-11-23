#ifndef KEYPRESSEVENTFILTERSIM_H
#define KEYPRESSEVENTFILTERSIM_H

#include <QObject>

class KeyPressEventFilterSim : public QObject {

    Q_OBJECT

    public:
        explicit KeyPressEventFilterSim(QObject* parent = nullptr);

    protected: 
        bool eventFilter(QObject * obj, QEvent *event) override;

    signals: 
        void keyboardBtnClicked(int btnID);
};

#endif // KEYPRESSEVENTFILTERSIM_H


