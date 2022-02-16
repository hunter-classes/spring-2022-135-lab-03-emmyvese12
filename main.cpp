#include <iostream>
#include "reservoir.h"

int main(){
  std::cout << "Date: " << "04/22/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("04/22/2018") << std::endl;

  std::cout << "\nDate: " << "12/25/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("12/25/2018") << std::endl;

  return 0;
}