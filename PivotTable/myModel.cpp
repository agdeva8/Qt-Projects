#include "myModel.h"

myModel::myModel(QObject *parent=nullptr)
        :QAbstractTableModel(parent)
{
    // since this is simple table model so dont do anything
    Q_UNUSED(parent);
}

myModel::myModel(int number_rows, int number_cols, QObject *parent = nullptr)
        :QAbstractTableModel (parent)
{
    // since this is simple table model so dont do anything
    Q_UNUSED(parent);
    number_rows =
}


int myModel::rowCount(const QModelIndex &parent) const
{

}

int myModel::columnCount(const QModelIndex &parent) const
{

}

QVariant myModel::data(const QModelIndex &index, int role) const
{

}
