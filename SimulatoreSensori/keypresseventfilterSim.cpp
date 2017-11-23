#include "keypresseventfilterSim.h"

#include <QDebug>
#include <QKeyEvent>

KeyPressEventFilterSim::KeyPressEventFilterSim(QObject * parent)
    : QObject(parent) 
{
    parent->installEventFilter(this);
}

bool KeyPressEventFilterSim::eventFilter(QObject *obj, QEvent *event) {
    return QObject::eventFilter(obj, event);
}
