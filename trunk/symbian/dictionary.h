#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QString>
#include <QVector>
#include <entry.h>
#include <QStringList>

class Dictionary
{
public:
    Dictionary();
    QStringList search(QString&);
    void print(const char);
    
private://function
    QString getFileName(const int);
    int binarySearch(QVector<Entry>& , int, int, const QString&);
    void loadKeysFile();
    int findWordBlock(const QString&);

private://data
    QVector<Entry> getList(const QString&);
    QVector<Entry> getListOnDemand(const QString&, const QString&);
    QStringList getTranslations(const QString&, const QString&);
    QVector<Entry> list[26];
    QStringList keys;

};

#endif // DICTIONARY_H
