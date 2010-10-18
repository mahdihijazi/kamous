#include <QtGui/QApplication>
#include <QLibraryInfo>
#include <QTranslator>
#include <QString>
#include "dictwin.h"
#include "dictionary.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTranslator qtTranslator;
//    QString qtTranslationsPath("qt_");
//    qtTranslationsPath.append("ar");

//    qtTranslator.load( qtTranslationsPath, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
//    a.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    //myappTranslator.load("dict" + QLocale::system().name());
    QString path("dict_");
    path.append("ar");
    myappTranslator.load(path);
    a.installTranslator(&myappTranslator);

    DictWin w;
#if defined(Q_OS_SYMBIAN)
    w.showMaximized();
#else
    w.show();
#endif



    return a.exec();
}
