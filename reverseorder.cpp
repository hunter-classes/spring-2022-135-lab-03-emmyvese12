/*
Emmy Veselinov
CSCI 135 Lab-03

Task D: In these files create a function 
void reverse_oreder(std::string date1, std::string date2). 
This function should print out the West basin elevation for 
all days in the interval in reverse chronological order.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <climits>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2){
    //for the west basin elevation

    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk);

    double eastSt, eastEl, westSt, westEl;
    std::string date_fromfile;
    bool targetDate = false;
    double west_elevations[365]; //because we only have 365 days of data to use
    std::string dates[365];
    int store = 0; //so later on when we print the array and do dates[i] and west_elevations[i], the date and ft will match (stores it in the same number cell in both arrays)
    // store is also the number of days in the interval
    
    while(fin >> date_fromfile >> eastSt >> eastEl >> westSt >> westEl){
        fin.ignore(INT_MAX, '\n');

        if (date_fromfile == date1){
            targetDate = true; // once we reach the first date do the next if statement
        }
        if (targetDate == true){ //keep doing this until we reach the 2nd date
            west_elevations[store] = westEl;
            dates[store] = date_fromfile;
            store = store + 1; // to store it in the next cell of the array
        }
        if (date_fromfile == date2) //this is where we will stop since the data for date2 was stored above
            break;
        }     

        fin.close();
        store = store - 1; // There are 5 cells stored and the index starts from 0 --> 0,1,2,3,4 so store should be equal to 4
        // print both arrays
        for (int i = store; i >= 0; i--){ // going from index 4 to 0
            std::cout << dates[i] << "  " << west_elevations[i] << " ft" << "\n";
        }
}
