#include "tsunamievacmodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TsunamiEvacModel w;
    w.show();

    return a.exec();
}
