#include <iostream>
#include "class.h"

/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

int main()
{
    bike x("Giant", "M");
    std::cout << x << std::endl;
    return 0;
}