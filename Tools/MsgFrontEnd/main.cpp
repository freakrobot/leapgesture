#include "mainwindow.h"
#include <gestureconsumer.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GestureConsumer gs;

    gs.show();

    MainWindow w;
    w.show();

    return a.exec();
}
