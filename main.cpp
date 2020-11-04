#include "mintawidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MintaWidget w;
    w.show();
    return a.exec();
}
