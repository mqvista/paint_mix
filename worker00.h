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

class Worker00 : public QObject
{
    Q_OBJECT
    //提供qt property功能，自动更新数据到 qml
    Q_PROPERTY(double scalesBigValue READ getScalesBigValue NOTIFY scalesBigDataChangedSig)
    Q_PROPERTY(double scalesSmallValue READ getScalesSmallValue NOTIFY scalesSmallDataChangedSig)
public:
    static Worker00 *Instance();
    ~Worker00();
    Q_INVOKABLE void motorAction(quint16 boardNum ,quint8 channelNum, qint32 steps);
    Q_INVOKABLE void initAsix(quint8 asix);
    Q_INVOKABLE double getScalesBigValue();
    Q_INVOKABLE double getScalesSmallValue();
    Q_INVOKABLE void goToMotor(quint8 motor);


signals:
    void scalesSmallOpenSig(QString name, quint32 baud);
    void scalesBigOpenSig(QString name, quint32 baud);
    void scalesSmallCloseSig();
    void scalesBigCloseSig();
    void scalesSmallDataChangedSig();
    void scalesBigDataChangedSig();

public slots:
    void getScalesBigDataSlot(double value, QString unit);
    void getScalesSmallDataSlot(double value, QString unit);

private:
    explicit Worker00(QObject *parent = nullptr);
    QThread threadScalesBig;
    QThread threadScalesSmall;
    ScalesSmall scalesSmall;
    ScalesBig scalesBig;
    double m_BigScalesValue = 0;
    double m_SmallScalesValue = 0;
    QString m_BigScalesUnit = "";
    QString m_SmallScalesUnit = "";
};

#endif // WORKER00_H
