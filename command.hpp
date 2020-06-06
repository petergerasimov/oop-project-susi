#ifndef __COMMAND_HPP
#define __COMMAND_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

/**
@brief Клас който превръща подаден на входа низ на отделни думи (параметри).
*/
class Command
{
    private:
        static const int MAX_CMD = 256;
        char cmd[ MAX_CMD ];
        std::vector< std::string > args;
        void extractArgs();
    public:
        friend std::istream &operator>>( std::istream  &input, Command &c );
        const char* arg( unsigned pos );
        int numberOfArgs();
};


#endif //__COMMAND_HPP