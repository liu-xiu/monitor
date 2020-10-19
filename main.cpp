#include "mainwindow.h"
#include <globaldef.hpp>
#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainwindow;
    LOADQSS(GlobalSpace::STYLE_QSS_FILE_PATH);
    mainwindow.showMaximized();
            //.showNormal();

    return a.exec();
}
