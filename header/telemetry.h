#ifndef TELEMETRY_H
#define TELEMETRY_H

#define NUM_TESTS 5
#define NUM_DRIVERS 3

/*
Changes:
    add NUM_TESTS
    add NUM_DRIVERS
    del void setTelemetry(int, int ...)
    add void setTest(int)
    add void setDriver(int)
    del int getTelemetry(int)
    add int getTest()
    add int getDriver()
*/

class Telemetry
{
public:
    Telemetry();
    void setTest(int);
    void setDriver(int);
    void setSender();
    void setTelemetryStatus(int);
    void setPopupMessage(int);
    int getTest() const;
    int getDriver() const;
    bool getSender() const;
    int getTelemetryStatus() const;
    int getPopupMessage() const;
private:
    bool test[NUM_TESTS];
    bool driver[NUM_DRIVERS];
    bool sender;
    int telemetryEnStatus;
    int popup;
};

#endif // TELEMETRY_H
