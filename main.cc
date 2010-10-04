#include <QtGui/QApplication>
#include "dictwin.h"
#include "dictionary.h"
#include "entry.h"
#include "util.h"

using std::vector;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DictWin w;
    w.show();
    return a.exec();
}
