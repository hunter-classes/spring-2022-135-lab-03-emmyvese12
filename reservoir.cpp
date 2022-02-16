/*
Emmy Veselinov
CSCI 135 Lab-03

Task A: The get_east_storage function should accept a std::string 
specifying a date and should return the East Basin storage for that day. 

Task B: Write two functions that should return the minimum storage and the 
maximum storage in the East basin in the 2018.

Task C: Add a function std::string compare_basins(std::string date) that will 
return East if the East basin was higher on the specified date and West if the 
West was higher. It should return Equal if the values were the same. 
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date){
    //obtain date in the format MM/DD//YYYY and return the East Basin storage

    /* open and read the data file
    ifstream --> input file stream (open a file to read)
    fin --> stream variable name (input will be coming in from the file)
    */

    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }

    //first line are column names that need to be skipped
    std::string junk;
    getline(fin, junk); // read one line from the file

    //now we can read line by line

    double eastSt, user_eastSt;
    std::string date_fromfile;

    while(fin >> date_fromfile >> eastSt){ // only need 2 values b/c we're getting eastSt
        //extracts 5 values on each iteration when we use this as the condition (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
        fin.ignore(INT_MAX, '\n'); //skips to the end of the line & ignores the other columns
        if (date == date_fromfile){ //date is the hard coded date in main
            user_eastSt = eastSt;
            fin.close(); //close the stream after finding the date that was entered
        }

    }
    return user_eastSt;
    
}

///////////////////////////////////////////////////////////////////////////

double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
    }
    std::string junk;
    getline(fin, junk);

    double eastSt, minVal;
    std::string date;

    minVal = INT_MAX; //INT_MAX is the largest value that can be stored (cannot go above this limit)
    while(fin >> date >> eastSt){
        fin.ignore(INT_MAX, '\n');
        if (eastSt < minVal){
            minVal = eastSt;
        }

    }
    fin.close(); //close the stream after finishing reading the file
    return minVal;

}

///////////////////////////////////////////////////////////////////////////

double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
    }
    std::string junk;
    getline(fin, junk);

    double eastSt, eastEl, westSt, westEl, maxVal;
    std::string date;

    maxVal = INT_MIN; //INT_MIN is the lowest value that can be stored (cannot go below this limit)
    while (fin >> date >> eastSt){
        fin.ignore(INT_MAX, '\n');
        if (eastSt > maxVal){
            maxVal = eastSt;
        }

    }
    fin.close();
    return maxVal;
}

///////////////////////////////////////////////////////////////////////////

std::string compare_basins(std::string date){
    // comparing which basin was higher (elevation --> eastEl and westEl
    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if (fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
    }
    std::string junk;
    getline(fin, junk);

    double eastSt, eastEl, westSt, westEl;
    double storeEast, storeWest;
    std::string date_fromfile, output;

    while(fin >> date_fromfile >> eastSt >> eastEl >> westSt >> westEl){
        fin.ignore(INT_MAX, '\n');
        if (date == date_fromfile){
            storeEast = eastEl;
            storeWest = westEl;
            if (storeEast > storeWest){
                output = "East";
            }
            else if (storeWest > storeEast){
                output = "West";
            }
            else if (storeWest == storeEast){
                output = "Equal";
            }
        }
    }
    fin.close();
    return output;

}
