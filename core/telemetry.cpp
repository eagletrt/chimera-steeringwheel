#include "../header/telemetry.h"

Telemetry::Telemetry()
{
    for(int i = 0 ; i < 11; i++){
        this->telemetry[i] = 2;
    }
    this->sender = false;
    this->telemetryEnStatus = 0; //0 off, 1 is setting up, 2 setted
    this->popup = 3; //Welcome
}

void Telemetry::setTelemetry( int val1,
                              int val2,
                              int val3,
                              int val4,
                              int val5,
                              int val6,
                              int val7,
                              int val8,
                              int val9,
                              int val10,
                              int val11){
    this->telemetry[0] = val1;
    this->telemetry[1] = val2;
    this->telemetry[2] = val3;
    this->telemetry[3] = val4;
    this->telemetry[4] = val5;
    this->telemetry[5] = val6;
    this->telemetry[6] = val7;
    this->telemetry[7] = val8;
    this->telemetry[8] = val9;
    this->telemetry[9] = val10;
    this->telemetry[10] = val11;
}

void Telemetry::setSender(){
    this->sender == false ? this->sender = true : this->sender = false;
}

void Telemetry::setTelemetryStatus(int val){
    this->telemetryEnStatus = val;
}

void Telemetry::setPopupMessage(int val){
    this->popup = val;
}

void Telemetry::setTelemetryIndex(int index){
    this->telemetry[index] = (telemetry[index] + 1) % 2;
}

int Telemetry::getTelemetry(int index) const{
    return this->telemetry[index];
}

bool Telemetry::getSender() const{
    return this->sender;
}

int Telemetry::getTelemetryStatus() const{
    return this->telemetryEnStatus;
}

int Telemetry::getPopupMessage() const{
    return this->popup;
}
