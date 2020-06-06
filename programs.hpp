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
                { "AE1", 0, true },
                { "DUP", 0, true },
                { "EAI", 0, true },
                { "IO", 0, true },
                { "SDP", 0, true },
                { "AE2", 0, true },
                { "DAA", 0, true },
                { "KARH", 0, true },
                { "LP", 0, true },
                { "CHM", 0, true }
            },
            //Year 3
            {
                { "MATH", 0, true },
                { "PROG", 0, true },
            },
            //Year 4
            {
                { "MATH", 0, true },
                { "PROG", 0, true },
            }
        }
    },
    {
        "CompSci", 
        {
            //Year 1
            {
                { "LA", 0, true },
                { "DIS1", 0, true },
                { "DS", 0, true },
                { "UP", 0, true },
                { "DIS2", 0, true },
                { "AE1", 0, true },
                { "AG", 0, true },
                { "EAI", 0, true },
                { "OOP", 0, true },
                { "OOP_PRACT", 0, false }
            },
            //Year 2
            {
                { "AE2", 0, true },
                { "KARH", 0, true },
                { "OCG", 0, true },
                { "SDP", 0, true },
                { "FP", 0, true },
                { "VA", 0, true },
                { "DAA", 0, true },
                { "IO", 0, true },
                { "LP", 0, true },
                { "KM", 0, true },
                { "OS", 0, true }
            },
            //Year 3
            {
                { "MATH", 0, true },
                { "PROG", 0, true },
            },
            //Year 4
            {
                { "MATH", 0, true },
                { "PROG", 0, true },
            }
        }
    }
    
};

#endif //__MAJORS__HPP