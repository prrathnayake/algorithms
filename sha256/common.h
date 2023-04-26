#pragma once
#include <iostream>
#include <string>
#include <bitset>

std::string toBinary(std::string const &str)
{
    std::string binary = "";
    for (char const &c : str)
    {
        binary += std::bitset<8>(c).to_string();
    }
    return binary;
}

void sizeValidate(std::string *binary1, std::string *binary2)
{
    std::string add;
    int bin1Len = binary1->size();
    int bin2Len = binary2->size();

    if (bin1Len < bin2Len)
    {
        for (int i = 0; i < (bin2Len - bin1Len); i++)
        {
            add += "0";
        }
        *binary1 = add + *binary1;
    }
    else if (bin2Len < bin1Len)
    {
        for (int i = 0; i < (bin1Len - bin2Len); i++)
        {
            add += "0";
        }
        *binary2 = add + *binary2;
    }
}

std::string AND(std::string binary1, std::string binary2)
{
    sizeValidate(&binary1, &binary2);

    std::string result;

    for (int i = 1; i <= binary1.size(); i++)
    {
        if (binary1[i] == '1' & binary2[i] == '1')
        {
            result += '1';
        }
        else
        {
            result += '0';
        }
    }

    return result;
}

std::string OR(std::string binary1, std::string binary2)
{
    sizeValidate(&binary1, &binary2);

    std::string result;

    for (int i = 1; i <= binary1.size(); i++)
    {
        if (binary1[i] == '1' || binary2[i] == '1')
        {
            result += '1';
        }
        else
        {
            result += '0';
        }
    }

    return result;
}