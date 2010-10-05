#include <string>
#include <cstring>
#include <cctype>
#include "util.h"

using std::string;

void Util::split(string &str,		    /*IN*/
		 const string &delimiter,   /*IN*/
		 string tokenz[],	    /*OUT*/
		 int arr_len,
		 int &max)		    /*OUT*/
{
    int i=0;
    char *c_str = const_cast<char*>(str.data());
    const char *del = delimiter.c_str();
    
    char* token = strtok(c_str, del);
    while (token != NULL && i < arr_len)
    {
	tokenz[i++] = token;
	token = strtok(NULL, del);
    }
    max = i;
}

void Util::lower(string &str)
{
    char *data = const_cast<char*>(str.data());
    char *ptr = data;
    while (*data != '\0')
    {
	*data = tolower(*data);
	data++;
    }
    str = string(ptr);
}

string Util::getExceptionMessage(int etype)
{
    string msg;
    if (etype == 100)
	msg = "ملفات البيانات مفقوده, الرجاء إعادة تثبيت البرنامج!";
    if (etype == 200)
	msg = "لم يتم العثور على معنى للكلمة!";
    if (etype == 300)
	msg = "خطأ بالمدخلات!";
    
    return msg;
}

void Util::trim(string &str)
{
    char *c_str = const_cast<char*>(str.data());
    char *ptr_str = c_str;
    
    bool charStarts = false;
    while (*c_str != '\0')
    {
	if (*c_str == ' ' && !charStarts)
	    ptr_str++;
	else
	    charStarts = true;
	c_str++;
    }
    c_str--;
    charStarts = false;
    while (c_str >= ptr_str)
    {
	if (*c_str == ' ' && !charStarts)
	    *c_str = '\0';
	else
	    break;
	c_str--;
    }
    str = string(ptr_str);
}
