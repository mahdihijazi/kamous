#ifndef UTIL_H
#define UTIL_H

#include <iostream>

using std::string;

class Util
{
public:
    static void trim(string&);
    static void split(string&, const string&, string[], int, int&);
    static string getExceptionMessage(int etype);
    static void lower(string&);
};

#endif // UTIL_H
