/**
* Kamous, English->arabic dictionary.
* licensed under "waqf General Public license"
* http://www.ojuba.org/wiki/waqf/license
* 
* @auther mhewedy
* @email mohammed_a_hewedy@hotmail.com
*/
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
