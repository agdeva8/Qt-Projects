#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H
#include <QAbstractTableModel>

class myTableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    myTableModel(QObject* parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // these two functions append the data at last or remove from last;
    bool setRowCount(int rows, const QModelIndex &parent = QModelIndex());
    bool setColumnCount(int columns, const QModelIndex &parent = QModelIndex());


//    void setRowCount(int rows);
//    void setColumnCount(int cols);
private:
    int number_rows = 3;
    int number_columns = 4;

};

#endif // MYTABLEMODEL_H
