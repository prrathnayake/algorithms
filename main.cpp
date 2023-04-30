#include <iostream>

#include "sha256/index.h"

int main()
{
    std::string hash = hashComputation(toBinary("abc"));
    std::cout << hash << "\n";
    // std::cout << additionModulo("01010100110110100101000011101010","01100001011000100110001110000000") << "\n";

    // std::cout << ShaR("01010100110110100101000011101010",1).size() << "\n";

}