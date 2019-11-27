#include "../header/lv.h"

LV::LV() {
    this->lvTemp = 0;
    this->lvVolt = 0;
}
void LV::setLvTemp(int val) {
    lvTemp = val;
}
void LV::setLvVolt(int val) {
    lvVolt = val;
}
int LV::getLvTemp() const {
    return lvTemp;
}
int LV::getLvVolt() const {
    return lvVolt;
}