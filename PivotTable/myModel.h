#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
class myModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    myModel(QObject *parent);
    myModel(int number_rows, int number_cols, QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // MYMODEL_H
