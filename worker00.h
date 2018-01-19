#ifndef WORKER00_H
#define WORKER00_H

#include <QObject>
#include <QThread>
#include <scalessmall.h>
#include <scalesbig.h>
#include <QQmlApplicationEngine>
#include <DriverGC.h>
#include <QTimer>
#include "motion.h"
#include <xmlredwrite.h>
#include <QStringListIterator>

class Worker00 : public QObject
{
    Q_OBJECT
    //提供qt property功能，自动更新数据到 qml
    //-Q_PROPERTY(double scalesBigValue READ getScalesBigValue NOTIFY scalesBigDataChangedSig)
    //-Q_PROPERTY(double scalesSmallValue READ getScalesSmallValue NOTIFY scalesSmallDataChangedSig)
public:
    static Worker00 *Instance();
    ~Worker00();
    Q_INVOKABLE void motorAction(quint16 boardNum ,quint8 channelNum, qint32 steps);
    Q_INVOKABLE void initAsix(quint8 asix);
    Q_INVOKABLE void moveToAsix(quint8 motor);
    Q_INVOKABLE void moveToAsixBig(quint8 motor);
    Q_INVOKABLE void runTest();
    Q_INVOKABLE void runFromProfile(QString name);
    Q_INVOKABLE void manualControl(QStringList params);
    Q_INVOKABLE void openSerial485();
    Q_INVOKABLE void closeSerial485();
    Q_INVOKABLE void initSystem();

signals:

public slots:
    void getSmallScalesValue(double value);
    void getBigScalesValue(double value);


private:
    explicit Worker00(QObject *parent = nullptr);
    //获取worker01的秤数值并保存
    double m_BigScalesValue = 0;
    double m_SmallScalesValue = 0;
};

#endif // WORKER00_H
