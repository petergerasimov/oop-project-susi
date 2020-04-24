#ifndef __MY_TYPES_HPP
#define __MY_TYPES_HPP

#include <string>

typedef unsigned int uint;

struct Course
{
    std::string name = "None";
    float grade = 0;
    bool mandatory = true;
};

#endif //__MY_TYPES_HPP