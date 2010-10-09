#include <QApplication>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include "dictionary.h"
#include "util.h"

Dictionary::Dictionary()
{    
//    for (char i='A'; i<='Z'; i++)
//    {
//        QString fileName = getFileName(i);
//        int letter = i -'A';
	
//        list[letter].reserve(100);
//        QFile file(fileName);
//        QString line;
//        if ( file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
//            // file opened successfully
//            QTextStream t( &file );        // use a text stream
//            // until end of file...
//            while ( !t.atEnd() ) {

//                line = QString::fromUtf8(t.readLine().toLocal8Bit()).trimmed();         // line of text excluding '\n'
//                if(!line.isEmpty()) {
//                    Entry e;
//                    e.fromLine(line);
//                    list[letter].push_back(e);

//                }

//            }
//            // Close the file
//            file.close();
//        }

//    }
    
}

QString Dictionary::getFileName(const char ch)
{
    QString fileName(":/data/");
    fileName.append(ch);
    return fileName;

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

QVector<Entry> Dictionary::getListOnDemand(const QString &word)
{
    int firestLetter = word.toUpper().at(0).toAscii();
    QString fileName = getFileName(firestLetter);
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
                e.fromLine(line);
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

Entry Dictionary::search(QString &word)
{
    word = word.trimmed();
    word = word.toLower();

    QVector<Entry> list = getListOnDemand(word);
    int size = list.size();
    int index =  binarySearch(list, 0, size-1, word);
    if (index == -1)
        throw 200;
    else {
        Entry e = list[index];
        list.clear();
        return e;

    }

}
