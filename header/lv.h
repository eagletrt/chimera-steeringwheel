#ifndef LV_H
#define LV_H


class LV
{
public:
    LV();
    void setLvTemp(int);
    void setLvVolt(int);
    int getLvTemp() const;
    int getLvVolt() const;
private:
    int lvTemp;
    int lvVolt;
};

#endif // LV_H
