#ifndef ENTRY_H
#define ENTRY_H

#include <QString>

class Entry
{
public:
    Entry();
    void fromLine(const QString&, const QString&);
    QString getWord();
    int transNumber();
    QString* getTranslations();
    void print();
private:
    static const int max_translations = 15;
    QString word;
    QString translation[max_translations];
    int current;
    void setWord(const QString&);
    void addTranslation(const QString&);
};

#endif // ENTRY_H
