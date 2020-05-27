#ifndef __MAJORS_HPP
#define __MAJORS_HPP

#include "mytypes.hpp"
#include <vector>

const std::vector< Program > programs = 
{
    {
        "Informatics", 
        {
            //Year 1
            {
                { "LA", 0, true },
                { "DIS1", 0, true },
                { "AG", 0, true },
                { "UP", 0, true },
                { "VA", 0, true },
                { "DIS2", 0, true },
                { "DS", 0, true },
                { "OOP", 0, true },
                { "OOP_PRACT", 0, false }
            },
            //Year 2
            {
                { "Math", 0, true },
                { "Prog", 0, true }
            },
        }
    }
    
};

#endif //__MAJORS__HPP