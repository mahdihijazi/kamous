/**
* Kamous, English->arabic dictionary.
* licensed under "waqf General Public license"
* http://www.ojuba.org/wiki/waqf/license
* 
* @auther mhewedy
* @email mohammed_a_hewedy@hotmail.com
*/
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include <entry.h>

class Dictionary
{
public:
    Dictionary();
    Entry search(std::string&);
    void print(const char);
    
private://function
    char* getFileName(const char);
    int binarySearch(Entry *const, int, int, const std::string&);
    
private://data
    std::vector<Entry> getList(const std::string&);
    std::vector<Entry> list[26];
};

#endif // DICTIONARY_H
