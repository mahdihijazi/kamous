#include <cstring>
#include <iostream>
#include "entry.h"
#include "util.h"

using std::cout;
using std::endl;
using std::string;

Entry::Entry()
{
    current = -1;
}

void Entry::fromLine(const string& line)
{
    int available;
    string tokenz[Entry::max_translations];
    
    string key = line.substr(0, line.find_first_of('=', 0));
    Util::trim(key);
    Util::lower(key);
    setWord(key);
    
    string value = line.substr(line.find_first_of('=', 0)+1, line.size());
    Util::trim(value);
    
    Util::split(value, "::", tokenz, Entry::max_translations, available);
    for (int i=0; i<available; i++)
    {
	string t = tokenz[i];
	Util::trim(t);
	addTranslation(t);
    }
}

int Entry::transNumber()
{
    return this->current;
}

void Entry::setWord(const string& _word)
{
   this->word = _word;
}

string Entry::getWord(){return this->word;}

void Entry::addTranslation(const string& _translation)
{
    translation[++current] = _translation;
}
string* Entry::getTranslations()
{
    return this->translation;
}

void Entry::print()
{
    cout << this->word << ":\t";
    for (int i=0; i<=current; i++)
	cout << this->translation[i] << " :: ";
    cout <<endl;
}
