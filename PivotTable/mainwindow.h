#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTableView;
class myTableModel;
class QWidget;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    QTableView* my_table_view;
    myTableModel* my_table_model;
    QWidget* my_widget;
    QHBoxLayout* layout;
};

#endif // MAINWINDOW_H
