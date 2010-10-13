#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QVector>
#include <QStringList>
#include <QString>
#include "entry.h"

class Dictionary
{
public:
    Dictionary();
    QStringList search(QString&);
    
private://function
    QString getFileName(const int);
    void loadKeysFile();
    int findWordBlock(const QString&);

private://data
    QStringList getTranslations(const QString&, const QString&);
    QVector<Entry> list[26];
    QStringList keys;

};

#endif // DICTIONARY_H
