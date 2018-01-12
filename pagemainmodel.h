#ifndef PAGEMAINMODEL_H
#define PAGEMAINMODEL_H

#include <QObject>
#include "worker00.h"
#include "xmlredwrite.h"
#include <QMetaObject>

class PageMainModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList profileList READ getProfileList NOTIFY profileListChanged)
    Q_PROPERTY(QVector<QString> subList READ getSubList NOTIFY subListChanged)
    Q_PROPERTY(bool busy READ getBusy NOTIFY busyChanged)
public:
    explicit PageMainModel(QObject *parent = nullptr);
    Q_INVOKABLE void runTest();
    QStringList getProfileList();
    QVector<QString> getSubList();
    Q_INVOKABLE void reflushSubList(QString name);
    Q_INVOKABLE void runFromProfile(QString name);
    bool getBusy();


signals:
    void profileListChanged();
    void subListChanged();
    void busyChanged();

public slots:


private:
    QStringList m_profileList;
    QVector<QString> m_subList;
    bool m_isBusy = false;
};

#endif // PAGEMAINMODEL_H
