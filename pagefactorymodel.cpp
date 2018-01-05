#include "pagefactorymodel.h"

PageFactoryModel::PageFactoryModel(QObject *parent) : QObject(parent)
{
    connect(DriverGC::Instance(), &DriverGC::DebugOut, this, &PageFactoryModel::driverGcDebugSlot);
    initEncoderTimer();
    //initLimitTimer();
}

QStringList PageFactoryModel::getDriverDebugInfo()
{
    return m_driverGCdebugInfo;
}

qint32 PageFactoryModel::getEncoderData()
{
    return m_EncoderData;
}

QVariantList PageFactoryModel::getLimitData()
{
    if (m_LimitData.isEmpty())
    {
        QBitArray tmp(8);
        for(int i=0; i<8; i++)
        {
            m_LimitData.append(tmp);
        }
    }
    QVariantList tmpList;
    tmpList.clear();
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (m_LimitData[i][j])
            {
                tmpList.append(1);
            }
            else
            {
                tmpList.append(0);
            }
        }
    }
    return tmpList;
}

void PageFactoryModel::driverGcDebugSlot(QString msg, QDateTime dataTime)
{
    QString tmp = "Time: " + dataTime.toString("hh:mm:ss:zzz") + "  Msg: " + msg;
    m_driverGCdebugInfo.append(tmp);
    emit dirverDebugInfoChangedSig();
    if (m_driverGCdebugInfo.length() >=5)
    {
        m_driverGCdebugInfo.removeFirst();
    }
}

void PageFactoryModel::getEncoderValueWithTimerSlot()
{
    DriverGC::Instance()->Inquire_Encoder(6, 2, m_EncoderData);
    emit EncoderDataChanged();
}

void PageFactoryModel::getLimitValueWithTimerSlot()
{
    m_LimitData.clear();
    for (int i=1; i<7; i++)
    {
        QBitArray tmpData;
        DriverGC::Instance()->Inquire_Limit(i, tmpData);
        m_LimitData.append(tmpData);
    }
    emit LimitDataChanged();
}

void PageFactoryModel::initEncoderTimer()
{
    DriverGC::Instance()->Setting_Encoder_Zero(6,2);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PageFactoryModel::getEncoderValueWithTimerSlot);
    timer->start(2000);
}

void PageFactoryModel::initLimitTimer()
{
    QTimer *timers = new QTimer(this);
    connect(timers, &QTimer::timeout, this, &PageFactoryModel::getLimitValueWithTimerSlot);
    timers->start(500);
}
