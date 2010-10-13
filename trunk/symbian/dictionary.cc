#include <QApplication>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include "dictionary.h"
#include "util.h"

Dictionary::Dictionary() : keys()
{    
    loadKeysFile();

}

void Dictionary::loadKeysFile()
{
    QString kesyFileName = ":/data/keys.txt";
    QFile file(kesyFileName);
    QString line;
    if ( file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        QTextStream t( &file );
        while ( !t.atEnd() ) {
            line = QString::fromUtf8(t.readLine().toLocal8Bit()).trimmed();
            if(!line.isEmpty()) {
                keys.append(line);

            }

        }

    }

    file.close();

}

int Dictionary::findWordBlock(const QString& word)
{
    /**
      Note that actually the blocks are started from index 1 not form Zero.
    */

    int size = keys.size();
    for( int i=0;i<size;i++ ) {
        QString key = keys[i];
        int found = key.compare(word, Qt::CaseInsensitive);
        if( found >=1 )
            return i;       // it is in the previous block
        else if( found == 0 )
            return i >= size - 1 ? i : i + 1;       // it is the key of this block, if I am on the last block use the previus block index because I added the last word in the dictionary as a keyword, otherwise use the current block

    }

    return -1;

}

QString Dictionary::getFileName(const int blockNumber)
{
    return QString(":/data/" + QString::number(blockNumber) + ".txt");

}


QStringList Dictionary::getTranslations(const QString& fileName, const QString& word )
{
    QFile file(fileName);
    QString line;
    if ( file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        // file opened successfully
        QTextStream t( &file );        // use a text stream
        // until end of file...
        while ( !t.atEnd() ) {
            line = QString::fromUtf8(t.readLine().toLocal8Bit()).trimmed();
            QStringList keyValPair = line.split("=");

            QString key = keyValPair[0];
            key = key.trimmed();
            key = key.toLower();
            if( word.compare(key, Qt::CaseInsensitive) !=0 )
                continue;

            QString value = keyValPair[1];
            value = value.trimmed();

            QStringList translations = value.split("::");
            return translations;

        }

        throw 200;

    } else {
        throw 200;

    }

}

QStringList Dictionary::search(QString &word)
{
    word = word.trimmed();
    word = word.toLower();

    int fileNumber = findWordBlock(word);
    if( fileNumber < 1 )
        throw 200;

    QString fileName = getFileName(fileNumber);

    return getTranslations(fileName, word );

}
