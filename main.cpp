#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // creates object which manages settings, resources, etc
    QApplication a(argc, argv);
    //creates an instance of mainwindow class
    MainWindow w;
    //shows window on screen
    w.show();
    return a.exec();
}
