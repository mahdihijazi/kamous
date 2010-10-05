#include <QApplication>
#include <QDir>
#include "dictwin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir::setCurrent(QApplication::applicationDirPath());
    DictWin w;
    w.show();
    return a.exec();
}
