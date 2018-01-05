#ifndef PAGEFACTORYMODEL_H
#define PAGEFACTORYMODEL_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include "DriverGC.h"
#include "worker00.h"

class PageFactoryModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList dirverDebugInfo READ getDriverDebugInfo NOTIFY dirverDebugInfoChangedSig)
    Q_PROPERTY(qint32 EncoderData READ getEncoderData NOTIFY EncoderDataChanged)
    //Q_PROPERTY(QList<QList<bool>> LimitData READ getLimitData NOTIFY LimitDataChanged)
    Q_PROPERTY(QVariantList LimitData READ getLimitData NOTIFY LimitDataChanged)


public:
    explicit PageFactoryModel(QObject *parent = nullptr);
    QStringList getDriverDebugInfo();
    qint32 getEncoderData();
    //QList<QList<bool>> getLimitData();

    QVariantList getLimitData();

    void initEncoderTimer();
    void initLimitTimer();

    //Q_INVOKABLE void motorAction(quint8 boardNum ,quint8 channelNum, qint32 steps);

public slots:
    void driverGcDebugSlot(QString msg, QDateTime dataTime);
    void getEncoderValueWithTimerSlot();
    void getLimitValueWithTimerSlot();
    //启动步进电机信号
    //void motorActionSig(quint8 boardNum ,quint8 channelNum, qint32 steps);

signals:
    void dirverDebugInfoChangedSig();
    void EncoderDataChanged();
    void LimitDataChanged();

private:
    Worker00 m_worker;
    QStringList m_driverGCdebugInfo;
    qint32 m_EncoderData;
    QList<QBitArray> m_LimitData;
};

#endif // PAGEFACTORYMODEL_H
