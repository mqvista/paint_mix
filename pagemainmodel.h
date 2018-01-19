#ifndef PAGEMAINMODEL_H
#define PAGEMAINMODEL_H

#include <QObject>
#include "worker00.h"
#include "xmlredwrite.h"
#include <QMetaObject>
#include <QMap>

class PageMainModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool busy READ getBusy NOTIFY busyChanged)
public:
    explicit PageMainModel(QObject *parent = nullptr);
    Q_INVOKABLE bool manualControl(QString yl1, QString yl2, QString yl3,
                       QString yl4, QString yl5, QString yl6,
                       QString yl7, QString sz1, QString zj1,
                       QString zj2, QString water1, QString water2);
    bool getBusy();


signals:
    void busyChanged();

public slots:


private:
    bool m_isBusy = false;
};

#endif // PAGEMAINMODEL_H
