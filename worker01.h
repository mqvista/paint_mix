#ifndef WORKER01_H
#define WORKER01_H

#include <QObject>
#include <QThread>
#include "scalessmall.h"
#include "scalesbig.h"

class Worker01 : public QObject
{
    Q_OBJECT
public:
    static Worker01 *Instance();
    ~Worker01();
    Q_INVOKABLE void openScales();
    Q_INVOKABLE void closeScales();
    Q_INVOKABLE double getScalesBigValue();
    Q_INVOKABLE double getScalesSmallValue();

signals:
    void scalesSmallOpenSig(QString name, quint32 baud);
    void scalesBigOpenSig(QString name, quint32 baud);
    void scalesSmallCloseSig();
    void scalesBigCloseSig();
    //发送信号，通知page去更新数据
    void scalesSmallDataChangedSig();
    void scalesBigDataChangedSig();

public slots:
    //接收秤信号发回的数据
    void getScalesBigDataSlot(double value, QString unit);
    void getScalesSmallDataSlot(double value, QString unit);


private:
    explicit Worker01(QObject *parent = nullptr);
    //新建两秤的线程
    QThread threadScalesBig;
    QThread threadScalesSmall;
    //实例化两个秤
    ScalesSmall scalesSmall;
    ScalesBig scalesBig;
    //秤数值的单位的保存
    double m_BigScalesValue = 0;
    double m_SmallScalesValue = 0;
    QString m_BigScalesUnit = "";
    QString m_SmallScalesUnit = "";
};

#endif // WORKER01_H
