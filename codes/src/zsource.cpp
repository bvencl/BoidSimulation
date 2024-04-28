#include <iostream>
#include <ostream>
#include "vector.h"
#include "point.h"

#ifdef DEBUG
#define DEBUG_IS_ON 1
#else
#define DEBUG_IS_ON 0
#endif

using std::endl;
using std::cout;



int main(int argc, char* argv[])
{
    if(DEBUG_IS_ON)
    {
        cout << "debug mode is on" << endl;
    }

    Vector v1(11, 123);
    cout << v1 << endl;

    Vector v2 (4 , 3);

    cout << v2 << endl;

    return 0;
}