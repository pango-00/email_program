#include "serverpart.h"

#include <QApplication>
#include<clientpart.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Serverpart w;
    ClientPart w2;

    w.show();
    w2.show();
    return a.exec();
}
