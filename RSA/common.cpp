#include <iostream>

#include "common.h"

long long unsigned power(int base, int power)
{
    long long unsigned result = base;

    for (int i = 0; i < power - 1; i++)
    {
        result = result * base;
    }
    return result;
}