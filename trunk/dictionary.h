#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <string>
#include <entry.h>

using namespace std;

class Dictionary
{
public:
    Dictionary();
    Entry search(string&);
    void print(const char);
    
private://function
    char* getFileName(const char);
    int binarySearch(Entry *const, int, int, const string&);
    
private://data
    vector<Entry> getList(const string&);
    vector<Entry> list[26];
};

#endif // DICTIONARY_H
