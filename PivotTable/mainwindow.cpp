#include "mainwindow.h"
#include "mytablemodel.h"

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

    my_table_view->setModel(my_table_model);
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
    my_table_model->setRowCount(9);
    my_table_model->setColumnCount(9);

    my_table_model->setRowCount(4);
    my_table_model->setColumnCount(4);

    //my_table_view->show();

    my_widget = my_table_view;
    layout = new QHBoxLayout();
    my_widget->setLayout(layout);
    my_widget->show();
    this->setCentralWidget(my_widget);
}

MainWindow::~MainWindow()
{

}
