#pragma once
#include <iostream>
#include <bitset>
#include <cmath>

#include "binaryOperators.h"
#include "common.h"
#include "conversions.h"

std::string ShaR(std::string binary, int value)
{
    std::string add = "";
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

std::string Σ0(std::string binary)
{
    return XOR(XOR(RotR(binary, 2), RotR(binary, 13)), ShaR(binary, 22));
}

std::string Σ1(std::string binary)
{
    return XOR(XOR(RotR(binary, 6), RotR(binary, 11)), ShaR(binary, 25));
}

std::string σ0(std::string binary)
{
    return XOR(XOR(RotR(binary, 7), RotR(binary, 18)), ShaR(binary, 3));
}

std::string σ1(std::string binary)
{
    return XOR(XOR(RotR(binary, 17), RotR(binary, 19)), ShaR(binary, 10));
}

std::string additionModulo(std::string x, std::string y)
{
    std::bitset<32> bits1(x);
    unsigned int xInt = bits1.to_ulong();

    std::bitset<32> bits2(y);
    unsigned int yInt = bits2.to_ulong();

    int result = (xInt + yInt) % int(pow(2, 32));

    std::string binary = decimalToBinary(result);
    size32Validate(&binary);
    return binary;
}
