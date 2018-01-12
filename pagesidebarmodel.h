#ifndef PAGESIDEBAR_H
#define PAGESIDEBAR_H

#include <QObject>

class PageSideBarModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString smallScales READ getSmallScales NOTIFY smallScalesChanged)
    Q_PROPERTY(QString bigScales READ getBigScales NOTIFY bigScalesChanged)
public:
    explicit PageSideBarModel(QObject *parent = nullptr);
    QString getSmallScales();
    QString getBigScales();

signals:
    void smallScalesChanged();
    void bigScalesChanged();

public slots:
    void getSmallScalesValue(double value);
    void getBigScalesValue(double value);
private:
    QString m_BigScalesValue = "";
    QString m_SmallScalesValue ="";
};

#endif // PAGESIDEBAR_H
