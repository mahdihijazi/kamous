/**
* Kamous, English->arabic dictionary.
* licensed under "waqf General Public license"
* http://www.ojuba.org/wiki/waqf/license
* 
* @auther mhewedy
* @email mohammed_a_hewedy@gmail.com
*/
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
