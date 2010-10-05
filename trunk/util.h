#ifndef UTIL_H
#define UTIL_H

#include <string>

class Util
{
public:
    static void trim(std::string&);
    static void split(std::string&, const std::string&, std::string[], int, int&);
    static std::string getExceptionMessage(int etype);
    static void lower(std::string&);
};

#endif // UTIL_H
