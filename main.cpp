#include <iostream>

#include "sha256/index.h"

int main()
{
    std::string hash = hashComputation(toBinary("abc"));
    std::cout << hash << "\n";
}