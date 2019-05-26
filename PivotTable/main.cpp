#include "mywindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWindow w;
    w.resize(600,300);
    w.show();
    return a.exec();
}
