#include "../header/manettini.h"

Manettini::Manettini() {

    this->map = 1;
    this->pump = 6;
    this->tc = 1;

}

void Manettini::setMap(int val) {

    this->map = val;

}

void Manettini::setTc(int val) {

    this->tc = val;

}

void Manettini::setPump(int val) {

    this->pump = val;

}

int Manettini::getMap() const {

    return this->map;

}

int Manettini::getTc() const {

    return this->tc;

}

int Manettini::getPump() const {

    return this->pump;

}

void Manettini::incMap(const int MAP_NUMBER) {

    this->map++;
    if(this->map > MAP_NUMBER) this->map % MAP_NUMBER;

}

void Manettini::incPump(const int PUMP_NUMBER) {

    this->pump++;
    if(this->pump > PUMP_NUMBER) this->pump % PUMP_NUMBER;

}

void Manettini::incTc(const int TC_NUMBER) {

    this->tc++;
    if(this->pump > TC_NUMBER) this->pump % TC_NUMBER;

}