#ifndef TELEMETRY_H
#define TELEMETRY_H

#define NUM_TESTS 5
#define NUM_DRIVERS 3

class Telemetry
{
public:
    Telemetry();
    void setTest(int);
    void setDriver(int);
    void setAsk(bool);
    void setTelemetryStatus(int);
    void setPopupMessage(int);
    void setSender();
    int getTest() const;
    int getDriver() const;
    bool getAsk();
    int getTelemetryStatus() const;
    int getPopupMessage() const;
    bool getSender() const;
private:
    bool test[NUM_TESTS];
    bool driver[NUM_DRIVERS];
    bool ask;
    bool sender;
    int telemetryEnStatus;
    int popup;
};

#endif // TELEMETRY_H
