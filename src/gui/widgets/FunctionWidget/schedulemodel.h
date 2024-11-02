#ifndef SCHEDULEMODEL_H
#define SCHEDULEMODEL_H

#include <QAbstractTableModel>

class ScheduleModel : public QAbstractTableModel {
    Q_OBJECT

  public:
    explicit ScheduleModel(QObject* parent = nullptr);
    ~ScheduleModel();
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int             section,
                        Qt::Orientation orientation,
                        int             role = Qt::DisplayRole) const override;

  private:
    QStringList        _header;
    QList<QStringList> _dataList;
    QList<QIcon>       _iconList;
};

#endif // SCHEDULEMODEL_H