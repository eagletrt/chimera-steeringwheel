#ifndef TELEMETRY_H
#define TELEMETRY_H


class Telemetry
{
public:
    Telemetry();
    static int telemetry[11];
    bool sender;
    int telemetryEnStatus;
    int popup;
private:
    void setTelemetry(int, int, int, int, int ,int ,int ,int ,int ,int ,int);
    void setSender();
    void setTelemetryStatus(int);
    void setPopupMessage(int);
    void setTelemetryIndex(int);
    int getTelemetry(int) const;
    bool getSender() const;
    int getTelemetryStatus() const;
    int getPopupMessage() const;
};

#endif // TELEMETRY_H
