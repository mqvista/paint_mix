#include "pagesidebarmodel.h"

PageSideBarModel::PageSideBarModel(QObject *parent) : QObject(parent)
{

}

QString PageSideBarModel::getSmallScales()
{
    return m_SmallScalesValue;
}

QString PageSideBarModel::getBigScales()
{
    return m_BigScalesValue;
}

void PageSideBarModel::getSmallScalesValue(double value)
{
    m_SmallScalesValue = QString::number(value, 10, 2);
    emit smallScalesChanged();
}

void PageSideBarModel::getBigScalesValue(double value)
{
    m_BigScalesValue = QString::number(value, 10, 2);
    emit bigScalesChanged();
}
