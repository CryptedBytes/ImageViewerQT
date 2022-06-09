#include "mainwindow.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{

std::cout << "init";

    for(int i = 0; i < argc; i++){
        qDebug() << "\narguments #" << i << ":" << argv[i] << "\n";
    }




    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();



}
