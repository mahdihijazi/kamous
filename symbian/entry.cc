//#include <cstring>
//#include <iostream>
#include <QString>
#include <QStringList>
#include "entry.h"
#include "util.h"

//using std::cout;
//using std::endl;

Entry::Entry()
{
    current = -1;
}

void Entry::fromLine(const QString& line)
{
    QStringList keyValPair = line.split("=");

    QString key = keyValPair[0];
    key = key.trimmed();
    key = key.toLower();
    setWord(key);

    QString value = keyValPair[1];
    value = value.trimmed();
    
    QStringList translations = value.split("::");
    for (int i = 0; i < translations.size(); ++i) {
        QString t = translations[i];
        t = t.trimmed();
        addTranslation(t);

    }

//    QStringListIterator iterator(translations);
//    while (iterator.hasNext()) {
//         QString t = iterator.next().toLocal8Bit().constData();
//         t = t.trimmed();
////         addTranslation(t);
    
//     }

}

int Entry::transNumber()
{
    return this->current;
}

void Entry::setWord(const QString& _word)
{
   this->word = _word;
}

QString Entry::getWord(){return this->word;}

void Entry::addTranslation(const QString& _translation)
{
    translation[++current] = _translation;
}

QString* Entry::getTranslations()
{
    return this->translation;
}

void Entry::print()
{
//    cout << this->word << ":\t";
//    for (int i=0; i<=current; i++)
//	cout << this->translation[i] << " :: ";
//    cout <<endl;
}
