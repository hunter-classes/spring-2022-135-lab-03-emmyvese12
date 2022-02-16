// add your code
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string user_date){
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

    double eastSt, eastEl, westSt, westEl, user_eastSt;
    std::string date;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
        //extracts 5 values on each iteration
        fin.ignore(INT_MAX, '\n'); //skips to the end of the line & ignores the other columns
        if (date == user_date){
            user_eastSt = eastSt;
            fin.close(); //close the stream after finishing reading the file
        }
    }
    return user_eastSt;
    
}

