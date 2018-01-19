#ifndef MOTION_H
#define MOTION_H

#include <QObject>
#include <DriverGC.h>
#include <QMap>
#include <QTimer>
#include "xmlredwrite.h"

class Motion : public QThread
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
    bool initAsixM11();
    bool initAsix(quint8 motor);
    bool moveToAsix(quint16 motor);
    enum scales1Motor :quint16{
        scales1Motor01 = 324,
        scales1Motor02 = 288,
        scales1Motor03 = 252,
        scales1Motor04 = 216,
        scales1Motor05 = 180,
        scales1Motor06 = 144,
        scales1Motor07 = 108,
        scales1Motor08 = 72,
        scales1Motor09 = 36,
        scales1Motor10 = 0
    };
    enum scales2Motor :quint16{
        scales2Motor01 = 108,
        scales2Motor02 = 72,
        scales2Motor03 = 36,
        scales2Motor04 = 0,
        scales2Motor05 = 324,
        scales2Motor06 = 288,
        scales2Motor07 = 252,
        scales2Motor08 = 216,
        scales2Motor09 = 180,
        scales2Motor10 = 144
    };
    bool dropLiquid(quint8 motor, quint16 weight);
    bool stopDrop(quint8 motor);
    bool addWater(quint8 scalesNum, quint16 weight);
    void waitWhileFree(quint16 motor);
//    bool getDriverGCSerialStatus();
    bool getBusyStatus();
    bool moveSmallScalesWaterToBigScalles();


signals:

public slots:
    void getSmallScalesValue(double value);
    void getBigScalesValue(double value);

private:
    //单例
    explicit Motion();
    quint8 m_currentMotor;
    quint16 m_currentDegree;
    bool m_asixMoveState;
    double m_BigScalesValue = 0;
    double m_SmallScalesValue = 0;
    bool m_isBusy = false;
//    bool systemSerialStatus();
};

#endif // MOTION_H
