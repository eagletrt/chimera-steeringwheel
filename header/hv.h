#ifndef HV_H
#define HV_H


class Hv
{
public:
    Hv();
    void setHvTemperature(int, int);
    void setHvVoltage(int, int , int);
    int getHvTemperature() const;
    int getHvVoltage() const;
private:
    int hvTemp;
    int hvVolt;
};

#endif // HV_H
