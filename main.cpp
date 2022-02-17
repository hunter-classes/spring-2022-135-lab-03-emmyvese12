/*
Emmy Veselinov
CSCI 135 Lab-03

Task A: Get East Storage Value
Task B: Minimum and Maximum Storage in 2018
Task C: Comparing Elevations East and West
Task D: Reverse Chronological Order
*/

#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main(){
  //task A
  std::cout << "Date: " << "02/22/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("02/22/2018") << " billion gallons" << std::endl;

  std::cout << "\nDate: " << "05/20/2018" << std::endl;
  std::cout << "East basin storage: " << get_east_storage("05/20/2018") << " billion gallons" << std::endl;

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

  //task D
  std::cout << "\nWest basin elevation: " << std::endl;
  reverse_order("05/29/2018","06/02/2018");

  std::cout << "\nWest basin elevation: " << std::endl;
  reverse_order("01/05/2018","01/09/2018");

  return 0;
}