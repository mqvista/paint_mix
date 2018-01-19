#ifndef PAGECOLORCONFIGGRIDVIEW_H
#define PAGECOLORCONFIGGRIDVIEW_H

#include <QAbstractListModel>
#include <QDebug>

class PageColorConfigGrid
{
public:
    PageColorConfigGrid(const QString &name, const QString &setValue, const QString &realValue);

    QString name() const;
    QString setValue() const;
    QString realValue() const;

private:
    QString m_name;
    QString m_setValue;
    QString m_realValue;
};

class PageColorConfigGridView : public QAbstractListModel
{
    Q_OBJECT

public:
    enum PageColorRoles {
        NameRole = Qt::UserRole + 1,
        SetValueRole = Qt::UserRole + 2,
        RealValueRole = Qt::UserRole + 3
    };
    explicit PageColorConfigGridView(QObject *parent = nullptr);

    // Header:
//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE void insert(int index, const PageColorConfigGrid &pageColorConfigGrid);
    Q_INVOKABLE void append(const PageColorConfigGrid &pageColorConfigGrid);
    Q_INVOKABLE void remove(int index);
    Q_INVOKABLE void append(const QVariantMap map);
    Q_INVOKABLE void removeAll();

signals:
    void countChanged(int arg);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    int count() const;
    QList<PageColorConfigGrid> m_list;
};

#endif // PAGECOLORCONFIGGRIDVIEW_H
