#ifndef ENTRY_H
#define ENTRY_H

#include <string>
using std::string;

class Entry
{
public:
    Entry();
    void fromLine(const string&);
    string getWord();
    int transNumber();
    string* getTranslations();
    void print();
private:
    static const int max_translations = 15;
    string word;
    string translation[max_translations];
    int current;
    void setWord(const string&);
    void addTranslation(const string&);
};

#endif // ENTRY_H
