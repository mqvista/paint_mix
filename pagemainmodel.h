#ifndef PAGEMAINMODEL_H
#define PAGEMAINMODEL_H

#include <QObject>
#include "worker00.h"
#include <QMetaObject>

class PageMainModel : public QObject
{
    Q_OBJECT
public:
    explicit PageMainModel(QObject *parent = nullptr);
    Q_INVOKABLE void runTest();

signals:

public slots:
};

#endif // PAGEMAINMODEL_H
