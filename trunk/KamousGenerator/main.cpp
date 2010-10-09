#include <QtCore/QCoreApplication>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>

QString getFileName(const char);
int filesCounter = 1;
int MAXIMUM_WORDS_IN_BLOCK  = 300;
int wordsCounter = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile* outFile = NULL;
    QTextStream* out;

    QString baseLocation =  "d://out/";

    QFile keysFile(baseLocation + "keys.txt");
    if (!keysFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return 0;
    QTextStream tsKeys(&keysFile);


    qDebug() << "Start";

    for (char i='A'; i<='Z'; i++)
    {
        QString fileName = getFileName(i);

        qDebug() << "Read File: " << fileName;
        QFile file(fileName);
        QString line;
        if ( file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
            // file opened successfully
            QTextStream t( &file );        // use a text stream
            // until end of file...
            while ( !t.atEnd() ) {
                line = QString::fromUtf8(t.readLine().toLocal8Bit()).trimmed();  // line of text excluding '\n'
                if(!line.isEmpty()) {
                    if( wordsCounter % MAXIMUM_WORDS_IN_BLOCK == 0 ) {
                        try {
                            if( outFile != NULL && outFile->isOpen() )
                                outFile->close();
                        } catch( int e ) {

                        }

                        qDebug() << "Write File " << ( baseLocation + QString::number(filesCounter) + ".txt") ;
                        outFile = new QFile( baseLocation + QString::number(filesCounter) + ".txt");
                        filesCounter++;
                        if (!outFile->open(QIODevice::WriteOnly | QIODevice::Text))
                            return 0;

                        out = new QTextStream(outFile);
                        QStringList key = line.split( "=" );
                        QString k = key[0];
                        tsKeys << k.trimmed() << "\n";
                    }

                    wordsCounter++;
                    (*out) << line << "\n";

                }

            }

            // Close the file
            file.close();
        }

    }

    if( outFile != NULL && outFile->isOpen() )
        outFile->close();

    keysFile.close();

    return a.exec();
}

QString getFileName(const char ch)
{
    QString fileName(":/data/");
    fileName.append(ch);
    return fileName;

}
