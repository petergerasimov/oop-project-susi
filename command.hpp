#ifndef __COMMAND_HPP
#define __COMMAND_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

/**
* Клас за въвеждане и обработка на команди.
*/
class Command
{
    private:
        /**
        * Константа за максималната дължина на една команда.
        */
        static const int MAX_CMD = 256;
        /**
        * Низ на командата.
        */
        char cmd[ MAX_CMD ];
        /**
        * Масив от аргументи на командата.
        */
        std::vector< std::string > args;
        /**
        * Метод за извличане на аргументи.
        * Разделя низа на всяко деление.
        */
        void extractArgs();
    public:
        /**
        * Предефинирана операция за вход.
        * Тя извиква и exctractArgs().
        */
        friend std::istream &operator>>( std::istream  &input, Command &c );
        /**
        * Метод за достъпване на елементи от масива за аргументи.
        * @param pos позиция в масива
        * @return символен низ - аргумент на командата
        */
        const char* arg( unsigned pos );
        /**
        * Метод за намиране на броя на аргумените.
        * @return броя на елементите в масива от аргументи
        */
        int numberOfArgs();
};


#endif //__COMMAND_HPP