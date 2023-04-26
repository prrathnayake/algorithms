#pragma once
#include <iostream>

std::string ShaR(std::string binary, int value)
{
    std::string add;
    if (binary.size() > value)
    {
        binary.erase(binary.size() - (value + 1), value);
        for (int i = 0; i < value; i++)
        {
            add += "0";
        }
        return add + binary;
    }
    else
    {
        for (int i = 0; i < value; i++)
        {
            add += "0";
        }
        return add;
    }
}

std::string RotR(std::string binary, int value)
{
    char buffer[value];
    if (binary.size() < value)
    {
        value = value % binary.size();
    }
    else if (binary.size() == value)
    {
        return binary;
    }
    binary.copy(buffer, value, binary.size() - (value));
    binary.erase(binary.size() - (value), value);
    binary = std::string(buffer, value) + binary;

    return binary;
}