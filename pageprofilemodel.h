#ifndef PAGEPROFILEMODEL_H
#define PAGEPROFILEMODEL_H

#include <QObject>
#include "xmlredwrite.h"


class PageProfileModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList profileList READ getProfileList NOTIFY profileListChanged)
    Q_PROPERTY(QVector<QString> subList READ getSubList NOTIFY subListChanged)
public:
    explicit PageProfileModel(QObject *parent = nullptr);
    QStringList getProfileList();
    QVector<QString> getSubList();
    Q_INVOKABLE void reflushSubList(QString name);

signals:
    void profileListChanged();
    void subListChanged();

public slots:

private:
    QStringList m_profileList;
    QVector<QString> m_subList;
};

#endif // PAGEPROFILEMODEL_H
