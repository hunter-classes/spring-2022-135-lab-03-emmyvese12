#include <iostream>
#include "reservoir.h"

int main(){
  //task A
  std::cout << "Date: " << "04/22/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("04/22/2018") <<  std::endl;

  std::cout << "\nDate: " << "12/25/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("12/25/2018") << std::endl;

  //task B
  std::cout << "\nMinimum storage in East basin: " << get_min_east() << std::endl;

  std::cout << "Maximum storage in East basin: " << get_max_east() << std::endl;
  return 0;
}