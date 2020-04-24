#include <iostream>
#include "susi.hpp"

int main()
{
    Susi susi;
    while( susi.update() );
    return EXIT_SUCCESS;
}