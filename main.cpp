#include <iostream>

#include "sha256/index.h"

int main() {
  std::cout << AND("1001" , "1111")<< "\n";
  std::cout << OR("1001" , "1111")<< "\n";
  std::cout << ShaR("101011", 6)<< "\n";
  std::cout << RotR("101011", 7)<< "\n";
}