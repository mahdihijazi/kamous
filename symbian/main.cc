#include <QtGui/QApplication>
#include "dictwin.h"
#include "dictionary.h"
#include "entry.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DictWin w;
    w.showFullScreen();
    return a.exec();
}
