#include <iostream>
#include "command.hpp"

int main()
{
    Command c;
    while( true )
    {
        std::cout << "Enter command:\n$ " ;
        std::cin >> c;
        for( int i = 0; i < c.numberOfArgs(); i++ )
        {
            std::cout << c.arg(i) << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}