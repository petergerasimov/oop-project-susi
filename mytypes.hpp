#ifndef __MY_TYPES_HPP
#define __MY_TYPES_HPP

#include <string>
#include <vector>

typedef unsigned int uint;

/**
* Структура за дисциплина.
*/
struct Course
{
    /**
    * Име на дисциплината.
    */
    std::string name = "None";
    /**
    * Оценка от дисциплината.
    */
    float grade = 0;
    /**
    * Булева променлива, която показва дали дисциплината е задължителна.
    */
    bool mandatory = true;
};

/**
* Структура за специалност.
*/
struct Program
{
    /**
    * Име на специалността.
    */
    std::string name = "None";
    /**
    * Масив от курсове. Състои се от масив от дисциплини.
    */
    std::vector< std::vector< Course > > years;
};

#endif //__MY_TYPES_HPP