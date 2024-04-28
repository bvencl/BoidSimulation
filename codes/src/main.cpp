#include <iostream>
#include <ostream>
#include "vector.h"
#include "point.h"

#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif





int main(int argc, char* argv[])
{
    if(DEBUG_IS_ON)
    {
        std::cout << "debug mode is on" << std::endl;
    }


    return 0;
}