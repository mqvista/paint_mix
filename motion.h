#ifndef MOTION_H
#define MOTION_H

#include <QObject>
#include <DriverGC.h>

class Motion : public QObject
{
    Q_OBJECT
public:
    static Motion *Instance();
    //explicit Motion(QObject *parent = nullptr);
    bool initAsixM0();
    bool initAsixM1();
    bool initAsixM2();
    bool initAsixM3();
    bool initAsixM4();
    bool initAsixM5();
    bool initAsixM6();
    bool initAsixM7();
    bool initAsixM8();
    bool initAsixM9();
    bool initAsixM10();
    bool initAsix(quint8 motor);
    bool moveToAsix(quint8 motor);
    enum scales1Motor {
        scales1Motor01 = 36,
        scales1Motor02 = 72,
        scales1Motor03 = 108,
        scales1Motor04 = 144,
        scales1Motor05 = 180,
        scales1Motor06 = 216,
        scales1Motor07 = 252,
        scales1Motor08 = 288,
        scales1Motor09 = 324,
        scales1Motor10 = 0
    };

signals:

public slots:

private:
    //单例
    explicit Motion(QObject *parent = nullptr);
    quint8 m_currentMotor;
    quint8 m_currentDegree;

};

#endif // MOTION_H
