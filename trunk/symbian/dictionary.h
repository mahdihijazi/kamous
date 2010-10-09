#ifndef DICTIONARY_H
#define DICTIONARY_H

//#include <vector>
//#include <string>
#include <QString>
#include <QVector>
#include <entry.h>

//using namespace std;

class Dictionary
{
public:
    Dictionary();
    Entry search(QString&);
    void print(const char);
    
private://function
    QString getFileName(const char);
    int binarySearch(QVector<Entry>& , int, int, const QString&);
    
private://data
    QVector<Entry> getList(const QString&);
    QVector<Entry> getListOnDemand(const QString&);
    QVector<Entry> list[26];
};

#endif // DICTIONARY_H
