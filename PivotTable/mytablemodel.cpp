#include "mytablemodel.h"

#include <QAbstractTableModel>

myTableModel::myTableModel(QObject *parent)
            :QAbstractTableModel(parent)
{
}

int myTableModel::rowCount(const QModelIndex &parent = QModelIndex()) const
{
    Q_UNUSED(parent);
    return number_rows;
}

int myTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return number_columns;
}


bool myTableModel::insertRows(int position, int count, const QModelIndex &parent)
{
    int first = position;
    int last = position+count-1;
    beginInsertRows(parent, first, last);
    number_rows += count;

    for(int row =first; row<last; row++)
    {
        for(int col=0; col<number_columns; col++)
        {
            QString value = "";
            QModelIndex index = this->index(row, col);
            this->setData(index, value);
        }
    }
    endInsertRows();
    return true;
}

bool myTableModel::insertColumns(int position, int count, const QModelIndex &parent)
{
    int first = position;
    int last = position+count-1;
    beginInsertColumns(parent, first, last);
    number_columns += count;

    for(int col =first; col<last; col++)
    {
        for(int row=0; row<number_rows; row++)
        {
            QString value = "";
            QModelIndex index = this->index(row, col);
            this->setData(index, value);
        }
    }
    endInsertColumns();
    return true;
}

bool myTableModel::removeRows(int position, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, position, position+count-1);
    number_rows -= count;
    endRemoveRows();
    return true;
}

bool myTableModel::removeColumns(int position, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, position, position+count-1);
    number_columns -= count;
    endRemoveColumns();
    return true;
}

bool myTableModel::setRowCount(int new_number_rows, const QModelIndex &parent)
{
    if(new_number_rows > number_rows)
        return insertRows(number_rows, new_number_rows-number_rows, parent);

    if(new_number_rows < number_rows)
        return removeRows(new_number_rows, number_rows-new_number_rows, parent);

    return true;
}

bool myTableModel::setColumnCount(int new_number_columns, const QModelIndex &parent)
{
    if(new_number_columns > number_columns)
        return insertColumns(number_columns, new_number_columns-number_columns, parent);

    if(new_number_columns < number_columns)
        return removeColumns(new_number_columns, number_columns-new_number_columns, parent);

    return true;
}

QVariant myTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    int row = index.row();
    int column = index.column();
    if(role == Qt::DisplayRole)
    {
        return QString("Row%1, Column%2").arg(row).arg(column);
    }

    return QVariant();

}



