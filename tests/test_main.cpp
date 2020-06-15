#include "unitLib.h"
#include <iostream>
#include <vector> // TODO test using vector value

int main(int argc, char* argv[]){

  // TODO copy constructor and assignment operator
  // TODO operation values (+ - * / )
  std::vector<double> data;
  for(int i=0; i<100; i++)
    data.push_back(i *0.223);


  // How the API should work
  kg<float> empty;
  kg<float> single(1.1); // The data type defines
  kg<std::vector<double>> vect(data);


  std::cout << "empty= " << empty  << " size " << empty.size() << std::endl;
  std::cout << "single= " << single  << " size " << single.size() << std::endl;
  std::cout << "vect= " << vect  << " size " << vect.size() << std::endl;
  std::cout << "single as mg " << single.as_mg() << std::endl;



  return 0;
}
