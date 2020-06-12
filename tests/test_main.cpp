#include "unitLib_templates.h" // For debugging the base class
#include "unitLib.h"
#include <iostream>

int main(int argc, char* argv[]){
  Kg<float> w1(33.0);
  Kg<float> w2(34.0);
  Kg<float> f;
  std::cout << w1 << std::endl;
  w1 = w2;
  std::cout << w1 << std::endl;
  //w1 + w2;
  //std::cout << w1 << std::endl;

  return 0;
}
