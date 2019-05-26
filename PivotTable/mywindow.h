#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>

class QTableView;
class myTableModel;
class QWidget;
class QHBoxLayout;

class myWindow : public QWidget
{
     Q_OBJECT
public:
    myWindow(QWidget* parent = nullptr);
    QTableView* my_table_view;
    myTableModel* my_table_model;
    QWidget* my_widget;
    QHBoxLayout* my_layout;
};

#endif // MYWINDOW_H
