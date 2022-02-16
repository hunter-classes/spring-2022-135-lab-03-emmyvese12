#include <iostream>
#include "reservoir.h"

int main(){
  //task A
  std::cout << "Date: " << "02/22/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("02/22/2018") << " billion gallons" << std::endl;

  std::cout << "\nDate: " << "12/25/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("12/25/2018") << " billion gallons" << std::endl;

  //task B
  std::cout << "\nMinimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;

  std::cout << "Maximum storage in East basin: " << get_max_east() << " billion gallons" << std::endl;

  //task C
  std::cout << "\nWhich basin is higher on " << "04/27/2018" << "?: " << compare_basins("04/27/2018") << std::endl;
  std::cout << "Which basin is higher on " << "07/09/2018" << "?: " << compare_basins("07/09/2018") << std::endl;
  std::cout << "Which basin is higher on " << "08/05/2018" << "?: " << compare_basins("08/05/2018") << std::endl;
  std::cout << "Which basin is higher on " << "10/11/2018" << "?: " << compare_basins("10/11/2018") << std::endl;

  return 0;
}