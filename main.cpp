#include <iostream>

#include "sha256/index.h"
#include "RSA/index.h"

int main(int argc, char *argv[])
{
    // std::string hash = hashComputation(toBinary(argv[1]));

    // if(hash == argv[2]){
    //     std::cout << "test passed\n";
    // }else{
    //     std::cout << "test failed\n";
    // }

    generateKeys();

    return 0;
}