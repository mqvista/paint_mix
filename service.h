#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QDebug>
#include "worker00.h"
#include "worker01.h"

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(QObject *parent = nullptr);
    ~Service();

signals:

public slots:
    void closeThread();

private:
    QThread worker00Thread;
    QThread worker01Thread;
};

#endif // SERVICE_H
