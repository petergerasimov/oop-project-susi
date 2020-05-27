#ifndef __MY_TYPES_HPP
#define __MY_TYPES_HPP

#include <string>
#include <vector>

typedef unsigned int uint;

struct Course
{
    std::string name = "None";
    float grade = 0;
    bool mandatory = true;
};

struct Program
{
    std::string name = "None";
    std::vector< std::vector< Course > > years;
};

#endif //__MY_TYPES_HPP