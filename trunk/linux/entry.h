/**
* Kamous, English->arabic dictionary.
* licensed under "waqf General Public license"
* http://www.ojuba.org/wiki/waqf/license
* 
* @auther mhewedy
* @email mohammed_a_hewedy@hotmail.com
*/
#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry
{
public:
    Entry();
    void fromLine(const std::string&);
    std::string getWord();
    int transNumber();
    std::string* getTranslations();
    void print();
private:
    static const int max_translations = 15;
    std::string word;
    std::string translation[max_translations];
    int current;
    void setWord(const std::string&);
    void addTranslation(const std::string&);
};

#endif // ENTRY_H
