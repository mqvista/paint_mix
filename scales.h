#ifndef SCALES_H
#define SCALES_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QSerialPort>
#include <QSerialPortInfo>

class Scales : public QObject
{
    Q_OBJECT
public:
    explicit Scales(QObject *parent = nullptr);
    void open(QString port, quint32 baud);
    void close(void);
    void goToThread(QThread *thread);

protected:
    QString m_receivedata;
    double m_scalesValue;
    QString m_scalesStatus;
    QString m_scalesUnit;
    virtual void serialStrConver2Data(QString msg) = 0;     //must rewrite


signals:
    void receiveDataPush(double value, QString unit);

public slots:
    void rawSerialReceiveSlot();
    void scalesOpenSlot(QString port, quint32 baud);
    void scalesCloseSlot();

private:
    QSerialPort serial_port;
    QString receivedata;
};

#endif // SCALES_H
