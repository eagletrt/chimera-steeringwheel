#include "../header/telemetry.h"

Telemetry::Telemetry()
{
    for(int i = 0; i < NUM_TESTS; i++){
        test[i] = 0;
    }
    for(int i = 0; i < NUM_DRIVERS; i++) {
        driver[i] = 0;
    }
    this->sender = false;
    this->telemetryEnStatus = 0; //0 off, 1 is setting up, 2 setted
    this->popup = 3; //Welcome
}

//param val identify the id of the test to be enabled
void Telemetry::setTest(int val){
    bool found = false;
    int i = 0;
    while (!found && i < NUM_TESTS){
        if(test[i]) {
            test[i] = false;
            found = true;
        }
        i++;
    }
    
    test[val] = true;
}

//param val identify the id of the driver to be enabled
void Telemetry::setDriver(int val){
    bool found = false;
    int i = 0;
    while (!found && i < NUM_DRIVERS){
        if(driver[i]) {
            driver[i] = false;
            found = true;
        }
        i++;
    }
    
    driver[val] = true;
}

void Telemetry::setSender(){
    sender = !sender;
}

void Telemetry::setTelemetryStatus(int val){
    this->telemetryEnStatus = val;
}

void Telemetry::setPopupMessage(int val){
    this->popup = val;
}

//void Telemetry::setTelemetryIndex(int index){
//    this->telemetry[index] = (telemetry[index] + 1) % 2;
//}

//return the id of the current test
int Telemetry::getTest() const{
    int pos = -1;
    int i = 0;
    bool found = false;

    while(!found && i < NUM_TESTS) {
        if(test[i]) {
            pos = i;
            found = true;
        }
        i++;
    }

    return pos;
}

int Telemetry::getDriver() const{
    int pos = -1;
    int i = 0;
    bool found = false;

    while(!found && i < NUM_DRIVERS) {
        if(driver[i]) {
            pos = i;
            found = true;
        }
        i++;
    }

    return pos;
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
