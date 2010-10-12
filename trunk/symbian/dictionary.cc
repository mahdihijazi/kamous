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

void Dictionary::print(const char ch)
{
//    vector<Entry> v = list[ch-'A'];
//    Entry* eList = v.data();
    
//    for (size_t i=0; i<v.size(); i++)
//    {
//	eList->print();
//	eList++;
//    }
}

QVector<Entry> Dictionary::getList(const QString &word)
{
    int letter = word.toUpper().at(0).toAscii() - 'A';
    return list[ letter ];

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

QVector<Entry> Dictionary::getListOnDemand(const QString &fileName, const QString &word)
{
    int firestLetter = word.toUpper().at(0).toAscii();
    int letter = firestLetter -'A';

    list[letter].reserve(100);
    QFile file(fileName);
    QString line;
    if ( file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        // file opened successfully
        QTextStream t( &file );        // use a text stream
        // until end of file...
        while ( !t.atEnd() ) {

            line = QString::fromUtf8(t.readLine().toLocal8Bit()).trimmed();         // line of text excluding '\n'
            if(!line.isEmpty()) {
                Entry e;
                e.fromLine(line, word);
                list[letter].push_back(e);

            }

        }
        // Close the file
        file.close();
    }

    return list[ letter ];

}

int Dictionary::binarySearch(QVector<Entry> &list, int start, int end, const QString &key)
{
    int mid = (start + end)/2;
//    DEBUG_BS && cout<< "start " << start << " end " << end << " mid "<< mid<<endl;

    if (start > end) return -1;
    int cmp = key.compare(list[mid].getWord());

    if ( cmp <= -1)
            return binarySearch(list, start, mid-1, key);
    else if (cmp == 0)
            return mid;
    else
            return binarySearch(list, mid+1, end, key);
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
    /*
    QVector<Entry> list = getListOnDemand(fileName, word);
    int size = list.size();
    int index =  binarySearch(list, 0, size-1, word);
    if (index == -1)
        throw 200;
    else {
        Entry e = list[index];
        list.clear();
        return e;

    }*/

}
