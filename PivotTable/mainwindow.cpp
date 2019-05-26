#include "mainwindow.h"
#include "mytablemodel.h"
#include "RbTableHeaderView.h"

#include <QAbstractTableModel>
#include <QTableView>
#include <QDebug>
#include <QVariant>
#include <QHBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    my_table_view = new QTableView(this);
    my_table_model = new myTableModel(this);

//    my_table_view->setModel(my_table_model);
    my_table_view->resizeColumnsToContents();

    // checking if the view is getting updated or not;
    // result: view is updating;
    // without reimplementation insertRows and insertColumns does not work
    my_table_model->insertRows(1,2);
    my_table_model->insertColumns(2,1);

    // remove rows also needs reimplementation; base class is just returning false;
    // result: reimplementation working, view is updating
    my_table_model->removeRows(1,2);
    my_table_model->removeColumns(2,1);

    // now going to setRowCount and setColumnCount
        // which is nothing but the combinations of implementations of
        // above performed four operations
    my_table_model->setRowCount(4);
    my_table_model->setColumnCount(4);

    my_table_view->setModel(my_table_model);

    int number_rows = my_table_model->rowCount();
    int number_cols = my_table_model->columnCount();

    RbTableHeaderView* horizontal_header_view = new RbTableHeaderView(Qt::Horizontal, 2, number_cols);
    RbTableHeaderView* vertical_header_view = new RbTableHeaderView(Qt::Vertical, number_rows, 1);


      QAbstractItemModel* horizontal_header_model = horizontal_header_view->model();
      QAbstractItemModel* vertical_header_model = vertical_header_view->model();


      horizontal_header_view->setSpan(0,0,3,0);
      horizontal_header_view->setSpan(0,1,2,2);
      horizontal_header_view->setSpan(1,3,2,0);
      horizontal_header_model->setData(horizontal_header_model->index(0,0),QString("cell1"),Qt::DisplayRole);
      horizontal_header_model->setData(horizontal_header_model->index(0,1),QString("cell2"),Qt::DisplayRole);
      horizontal_header_model->setData(horizontal_header_model->index(2,1),QString("cell3"),Qt::DisplayRole);
      horizontal_header_model->setData(horizontal_header_model->index(2,2),QString("cell4"),Qt::DisplayRole);
      horizontal_header_model->setData(horizontal_header_model->index(0,3),QString("cell5"),Qt::DisplayRole);
      horizontal_header_model->setData(horizontal_header_model->index(1,3),QString("cell6"),Qt::DisplayRole);

      vertical_header_view->setSpan(0,0,0,3);
      vertical_header_view->setSpan(1,0,3,0);
      vertical_header_view->setSpan(1,1,2,0);
      vertical_header_model->setData(vertical_header_model->index(0,0),QString("cell1"),Qt::DisplayRole);
      vertical_header_model->setData(vertical_header_model->index(1,0),QString("cell2"),Qt::DisplayRole);
      vertical_header_model->setData(vertical_header_model->index(1,1),QString("cell3"),Qt::DisplayRole);
      vertical_header_model->setData(vertical_header_model->index(3,1),QString("cell4"),Qt::DisplayRole);
      vertical_header_model->setData(vertical_header_model->index(1,2),QString("cell5"),Qt::DisplayRole);
      vertical_header_model->setData(vertical_header_model->index(2,2),QString("cell6"),Qt::DisplayRole);
      vertical_header_model->setData(vertical_header_model->index(3,2),QString("cell7"),Qt::DisplayRole);

      horizontal_header_view->setRowHeight(0,30);
      horizontal_header_view->setRowHeight(1,30);
      horizontal_header_view->setRowHeight(2,30);

      vertical_header_view->setRowHeight(0,30);
      vertical_header_view->setRowHeight(1,30);
      vertical_header_view->setRowHeight(2,30);
      vertical_header_view->setColumnWidth(0,50);
      vertical_header_view->setColumnWidth(1,50);
      vertical_header_view->setColumnWidth(2,50);


//    RbTableHeaderModel* horizontal_header_model = new RbTableHeaderModel(2,number_cols);
//    RbTableHeaderModel* vertical_header_model = new RbTableHeaderModel(number_rows,1);

//    horizontal_header_model->setBaseSectionSize(horizontal_header_view->getBaseSectionSize());
//    vertical_header_model->setBaseSectionSize(vertical_header_view->getBaseSectionSize());

//    horizontal_header_view->setModel(horizontal_header_model);
//    vertical_header_view->setModel(vertical_header_model);

//    for(int row=0; row<number_rows;row++)
//    {
//        QModelIndex index = vertical_header_model->index(row,0);
//        QString value = tr("row number %1").arg(row);
//        vertical_header_model->setData(index, value, Qt::DisplayRole);
//    }

//    for(int row=0; row<2; row++){
//        for(int col=0; col<number_cols;col++)
//        {
//            QModelIndex index = horizontal_header_model->index(row,col);
//            QString value = tr("row %1, col %2").arg(row).arg(col);
//            horizontal_header_model->setData(index, value, Qt::DisplayRole);
//        }
//    }

//    horizontal_header_view->setRowHeight(0,30);
//    horizontal_header_view->setRowHeight(1,30);

    my_table_view->setHorizontalHeader(horizontal_header_view);
    my_table_view->setVerticalHeader(vertical_header_view);

//    horizontal_header_view->setModel(horizontal_header_model);
//    vertical_header_view->setModel(vertical_header_model);




    my_widget = my_table_view;
    //my_layout = new QHBoxLayout();
    layout()->addWidget(my_widget);
    //my_widget->setLayout(layout);
    //my_widget->show();
    //this->setCentralWidget(my_widget);
}

MainWindow::~MainWindow()
{

}
