#ifndef PAGECOLORCONFIGMODEL_H
#define PAGECOLORCONFIGMODEL_H

#include <QObject>
#include <QDebug>
#include <QStringListModel>
#include "worker00.h"
#include "xmlredwrite.h"
#include "pagecolorconfiggridview.h"

class PageColorConfigModel : public QObject
{
    Q_OBJECT
    //QML 主列表
    Q_PROPERTY(QStringList profileList READ getProfileList NOTIFY profileListChanged)
    Q_PROPERTY(QVector<QString> subList READ getSubList NOTIFY subListChanged)
    //秤信数据
    Q_PROPERTY(QString smallScales READ getSmallScales NOTIFY smallScalesChanged)
    Q_PROPERTY(QString bigScales READ getBigScales NOTIFY bigScalesChanged)
    //系统繁忙属性
    Q_PROPERTY(bool busy READ getBusy NOTIFY busyChanged)
public:
    explicit PageColorConfigModel(QObject *parent = nullptr);
    void givePagClrGv(PageColorConfigGridView &pageColorGV);
    bool getBusy();
    QStringList getProfileList();
    QVector<QString> getSubList();
    QString getSmallScales();
    QString getBigScales();
    Q_INVOKABLE void reflushGridView(QString name);
    Q_INVOKABLE void runFromProfile(QString name);
    Q_INVOKABLE void reflushSubList(QString name);
    Q_INVOKABLE bool saveNewColorConfig(QString name, QString yl1, QString yl2,
                                        QString yl3, QString yl4, QString yl5,
                                        QString yl6, QString yl7, QString water1,
                                        QString sz1, QString zj1, QString zj2);


signals:
    void profileListChanged();
    void subListChanged();
    void busyChanged();
    void smallScalesChanged();
    void bigScalesChanged();

public slots:
    void getSmallScalesValue(double value);
    void getBigScalesValue(double value);


private:
    QStringList m_profileList;
    QVector<QString> m_subList;
    bool m_isBusy = false;
    QString m_BigScalesValue = "";
    QString m_SmallScalesValue ="";
    PageColorConfigGridView *m_pagClrGv;
};

#endif // PAGECOLORCONFIGMODEL_H
