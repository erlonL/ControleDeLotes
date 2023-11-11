#include "maincontext.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainContext w;
    w.show();
    return a.exec();
}
