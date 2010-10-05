/**
* Kamous, English->arabic dictionary.
* licensed under "waqf General Public license"
* http://www.ojuba.org/wiki/waqf/license
* 
* @auther mhewedy
* @email mohammed_a_hewedy@gmail.com
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "dictionary.h"
#include "util.h"

#define DEBUG_BS 0

using namespace std;

Dictionary::Dictionary()
{
    ifstream inStream;
    
    for (char i='A'; i<='Z'; i++)
    {
	char *fileName = getFileName(i);
	int letter = i -'A';
	
	list[letter].reserve(100);
	
	inStream.open(fileName);
	if (inStream.fail())
	{
	    throw 100;
	}
	
	while (!inStream.eof())
	{
	    const int max_len = 300;
	    char line[max_len];
	    inStream.getline(line, max_len);
	    
	    if (strcmp(line, "") != 0)
	    {
		Entry e;
		string s_line(line);
		e.fromLine(s_line);
		list[letter].push_back(e);
	    }
	}
	inStream.close();
	
	delete [] fileName;
    }
    
}

char* Dictionary::getFileName(const char ch)
{
    char* fileName = new char[7];
    strcpy(fileName, "data/");
    fileName[5] = ch;
    fileName[6] = '\0';
    return fileName;
}

void Dictionary::print(const char ch)
{
    vector<Entry> v = list[ch-'A'];
    Entry* eList = v.data();
    
    for (size_t i=0; i<v.size(); i++)
    {
	eList->print();	
	eList++;
    }
}

vector<Entry> Dictionary::getList(const string &word)
{
    const char *str = word.data();
    if (toupper(*str) < 'A' || toupper(*str) > 'Z')
	throw 300;
    return list[toupper(*str)-'A'];
}

int Dictionary::binarySearch(Entry *const list, int start, int end, const string &key)
{
    int mid = (start + end)/2;
    DEBUG_BS && cout<< "start " << start << " end " << end << " mid "<< mid<<endl;

    if (start > end) return -1;
    int cmp = key.compare(list[mid].getWord());

    if ( cmp <= -1)
	    return binarySearch(list, start, mid-1, key);
    else if (cmp == 0)
	    return mid;
    else// cmp >= 1
	    return binarySearch(list, mid+1, end, key);
}

Entry Dictionary::search(string &word)
{
    Util::lower(word);
    Util::trim(word);
    vector<Entry> v = getList(word);
    
    Entry* list = const_cast<Entry*>(v.data());
    int size = v.size();
    int index =  binarySearch(list, 0, size-1, word);
    if (index == -1) 
	throw 200;
    else return list[index];
}
