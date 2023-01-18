#include <iostream>
#include "bitVector.h"

int main()
{
    bitVector obj;
    obj.set(36, true);
    std::cout << obj[12] << std::endl;
    std::cout << obj[40] << std::endl;

}