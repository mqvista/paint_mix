#ifndef WORKER00_H
#define WORKER00_H

#include <QObject>
#include <QThread>
#include <scalessmall.h>
#include <scalesbig.h>
#include <QQmlApplicationEngine>
#include <DriverGC.h>
#include <QTimer>

class Worker00 : public QObject
{
    Q_OBJECT
    //提供qt property功能，自动更新数据到 qml
    Q_PROPERTY(double scalesBigValue READ getScalesBigValue NOTIFY scalesBigDataChangedSig)
    Q_PROPERTY(double scalesSmallValue READ getScalesSmallValue NOTIFY scalesSmallDataChangedSig)
public:
    explicit Worker00(QObject *parent = nullptr);
    ~Worker00();
    Q_INVOKABLE void motorAction(quint16 boardNum ,quint8 channelNum, qint32 steps);
    Q_INVOKABLE void initAsixA();
    double getScalesBigValue();
    double getScalesSmallValue();


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
//    void actoinMotorFromQmlSlot(qint16 board, quint8 channel, qint32 steps);

private:
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
