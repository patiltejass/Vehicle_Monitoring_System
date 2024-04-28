#include "mainwindow.h"

#include <QApplication>
#include<gtest/gtest.h>
using namespace testing;

int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();
    InitGoogleTest(&argc ,argv);
    return RUN_ALL_TESTS();
}
