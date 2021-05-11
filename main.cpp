#include "tick8.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tick8 w;
    w.show();
    return a.exec();
}
