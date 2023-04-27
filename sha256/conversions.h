#pragma once
#include <iostream>

std::string decimalToBinary(int n)
{
    std::string binary = "";
    std::string tem = "";

    while (n > 0)
    {
        tem += std::to_string(n % 2);
        n = n / 2;
    }

    for(int i = (tem.size() - 1); i >= 0; i--)
    {
        binary += tem[i];
    }

    return binary;
}