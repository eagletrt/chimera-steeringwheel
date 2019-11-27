#ifndef HV_H
#define HV_H


class Hv
{
public:
    Hv();
    void setHvTemp(int, int);
    void setHvVolt(int, int , int);
    int getHvTemperature() const;
    int getHvVoltage() const;
private:
    int hvTemp;
    int hvVolt;
};

#endif // HV_H
