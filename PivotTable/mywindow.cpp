#include "mywindow.h"
#include "mytablemodel.h"
#include "RbTableHeaderView.h"

#include <QAbstractTableModel>
#include <QTableView>
#include <QDebug>
#include <QVariant>
#include <QHBoxLayout>
#include <QWidget>


myWindow::myWindow(QWidget* parent)
    :QWidget(parent)
{
    my_table_view = new QTableView(this);
    my_table_model = new myTableModel(this);

    my_table_view->setModel(my_table_model);

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

    int number_rows = 4;
    int number_cols = 6;
    my_table_model->setRowCount(number_rows);
    my_table_model->setColumnCount(number_cols);


    RbTableHeaderView* horizontal_header_view = new RbTableHeaderView(Qt::Horizontal);
    RbTableHeaderView* vertical_header_view = new RbTableHeaderView(Qt::Vertical);

    RbTableHeaderModel* horizontal_header_model = new RbTableHeaderModel(3,number_cols+1);
    RbTableHeaderModel* vertical_header_model = new RbTableHeaderModel(number_rows+1,3);

    horizontal_header_model->setBaseSectionSize(horizontal_header_view->getBaseSectionSize());
    vertical_header_model->setBaseSectionSize(vertical_header_view->getBaseSectionSize());

    //    horizontal_header_model->setOrientation(Qt::Horizontal);
    //    vertical_header_model->setOrientation(Qt::Vertical);

    horizontal_header_view->setModel(horizontal_header_model);
    vertical_header_view->setModel(vertical_header_model);

//    horizontal_header_view->setSectionResizeMode(QHeaderView::ResizeToContents);
//    vertical_header_view->setSectionResizeMode(QHeaderView::ResizeToContents);

    horizontal_header_view->setSectionsClickable(true);
    vertical_header_view->setSectionsClickable(true);

    horizontal_header_model->setSpan(0,0,2,2);
    horizontal_header_model->setSpan(0,2,2,2);
    horizontal_header_model->setSpan(0,4,2,2);

    // for now this one is important to make complete height of header visible
    // will set height later or can hide this header:
    horizontal_header_model->setSpan(0,number_cols,3,0);

    horizontal_header_model->setData(horizontal_header_model->index(0,0),QString("layer 1 cell 1"),Qt::DisplayRole);
    horizontal_header_model->setData(horizontal_header_model->index(0,2),QString("layer 1 cell 2"),Qt::DisplayRole);
    horizontal_header_model->setData(horizontal_header_model->index(0,4),QString("layer 1 cell 3"),Qt::DisplayRole);
    horizontal_header_model->setData(horizontal_header_model->index(2,0),QString("layer 2 cell 1"),Qt::DisplayRole);
    horizontal_header_model->setData(horizontal_header_model->index(2,1),QString("layer 2 cell 2"),Qt::DisplayRole);
    horizontal_header_model->setData(horizontal_header_model->index(2,2),QString("layer 2 cell 3"),Qt::DisplayRole);
    horizontal_header_model->setData(horizontal_header_model->index(2,3),QString("layer 2 cell 4"),Qt::DisplayRole);
    horizontal_header_model->setData(horizontal_header_model->index(2,4),QString("layer 2 cell 5"),Qt::DisplayRole);
    horizontal_header_model->setData(horizontal_header_model->index(2,5),QString("layer 2 cell 6"),Qt::DisplayRole);

    // for now this one is important to make complete width of header visible
    // will set height later or can hide this header:
    vertical_header_model->setSpan(number_rows,0,0,3);

    vertical_header_model->setSpan(0,0,2,2);
    vertical_header_model->setSpan(2,0,2,2);

    vertical_header_model->setData(vertical_header_model->index(0,0),QString("layer 1 cell 1"),Qt::DisplayRole);
    vertical_header_model->setData(vertical_header_model->index(2,0),QString("layer 1 cell 2"),Qt::DisplayRole);
    vertical_header_model->setData(vertical_header_model->index(0,2),QString("layer 2 cell 1"),Qt::DisplayRole);
    vertical_header_model->setData(vertical_header_model->index(1,2),QString("layer 2 cell 2"),Qt::DisplayRole);
    vertical_header_model->setData(vertical_header_model->index(2,2),QString("layer 2 cell 3"),Qt::DisplayRole);
    vertical_header_model->setData(vertical_header_model->index(3,2),QString("layer 2 cell 4"),Qt::DisplayRole);


    my_table_view->setHorizontalHeader(horizontal_header_view);
    my_table_view->setVerticalHeader(vertical_header_view);

    //    horizontal_header_view->setModel(horizontal_header_model);
    //    vertical_header_view->setModel(vertical_header_model);
    my_layout = new QHBoxLayout();
    my_layout->addWidget(my_table_view);
    setLayout(my_layout);
}



