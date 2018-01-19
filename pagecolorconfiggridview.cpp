#include "pagecolorconfiggridview.h"

////数据类
/// \brief PageColorConfigGrid::Data
/// \param name
/// \param setValue
/// \param realValue
////
PageColorConfigGrid::PageColorConfigGrid(const QString &name, const QString &setValue, const QString &realValue)
    :m_name(name), m_setValue(setValue), m_realValue(realValue)
{
}

QString PageColorConfigGrid::name() const
{
    return m_name;
}

QString PageColorConfigGrid::setValue() const
{
    return m_setValue;
}

QString PageColorConfigGrid::realValue() const
{
    return m_realValue;
}




////模型类
PageColorConfigGridView::PageColorConfigGridView(QObject *parent)
    : QAbstractListModel(parent)
{
}

//QVariant PageColorConfigGridView::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    // FIXME: Implement me!
//}

int PageColorConfigGridView::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
//    if (parent.isValid())
//        return 0;

    // FIXME: Implement me!
    Q_UNUSED(parent);
    return m_list.count();
}

QVariant PageColorConfigGridView::data(const QModelIndex &index, int role) const
{
//    if (!index.isValid())
//        return QVariant();

    // FIXME: Implement me!
    if (index.row() < 0 || index.row() >= m_list.count())
        return QVariant();

    const PageColorConfigGrid &pageColorConfigGrid = m_list[index.row()];
    qDebug() << "in->"<< index.row();

    if (role == NameRole)
        return pageColorConfigGrid.name();
    else if (role == SetValueRole)
        return pageColorConfigGrid.setValue();
    else if (role == RealValueRole)
        return pageColorConfigGrid.realValue();

    return QVariant();
}

void PageColorConfigGridView::insert(int index, const PageColorConfigGrid &pageColorConfigGrid)
{
    if (index < 0 || index > m_list.count())
        return;
    emit beginInsertRows(QModelIndex(), index, index);
    m_list.insert(index, pageColorConfigGrid);
    emit endInsertRows();
    emit countChanged(m_list.count());
}

void PageColorConfigGridView::remove(int index)
{
    if(index < 0 || index >= m_list.count()) {
        return;
    }
    emit beginRemoveRows(QModelIndex(), index, index);
    m_list.removeAt( index );
    emit endRemoveRows();
    emit countChanged(m_list.count());
}

void PageColorConfigGridView::append(const PageColorConfigGrid &pageColorConfigGrid)
{
    insert(count(), pageColorConfigGrid);
}

void PageColorConfigGridView::append(const QVariantMap map)
{
    QString name = map["name"].toString();
    QString setValue = map["setValue"].toString();
    QString realValue = map["realValue"].toString();

    PageColorConfigGrid pageColorConfigGrid(name, setValue, realValue);
    insert(count(), pageColorConfigGrid);
}

void PageColorConfigGridView::removeAll()
{
    if (m_list.count() > 0)
    {
        int cot = m_list.count();
        for (int i=0 ; i<= cot; i++)
        {
            remove(0);
        }
    }
}



QHash<int, QByteArray> PageColorConfigGridView::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[SetValueRole] = "setValue";
    roles[RealValueRole] = "realValue";
    return roles;
}

int PageColorConfigGridView::count() const
{
    return rowCount(QModelIndex());
}


