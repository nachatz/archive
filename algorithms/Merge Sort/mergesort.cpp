/*****************************************************
** Program: mergesort.cpp (implementation file for program) 
** Author: Nikolas Achatz
** Date: 1/12/2021
** Description: File inputs data from a file named data.txt and sorts using merge sort.
** data.txt must have the first number of each line denote how many numbers follow to be sorted.
** EXAMPLE
** 4 5 6 4 3 -> it will sort 3 4 5 6
******************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "math.h"
#include <stdlib.h>
#include "mergeAlgorithm.cpp"

using namespace std;

int main(){

    cout << "MERGE SORT " << endl;

    // Instantiate read file and open it.
    ifstream file;

    int create, hold;

    file.open("data.txt");

    // Makes sure our file is found
    if(file.is_open())
        cout << "data.txt detected and opened" << endl;
    else    
        cout << "Error opening data.txt, it is not found in the directory." << endl;



    // Loop through each value in the data.txt file checking for spaces.
    while(file >> hold){

        // Create variable takes in the first value in each line to reserve perfect memory for vectors.
        create = hold;

        // Instantiate our vector as well as reserve correct space.
        vector<int> arr;
        arr.reserve(create);

        // Once we take in our first value, we can loop through the rest for this line and push to the vector.
        for(int i = 0; i < create; i++){
            file >> hold;
            arr.push_back(hold);
        }
        
        // Send our vector through our merge sort.
       arr = mergeSort(arr);

        // Output our sorted values
        for(int i = 0; i < create; i++)
            cout << arr.at(i) << " ";

        // Clear the vector so we can sort the other lines.
        arr.clear();
        cout << endl;
    }

    return 0;

}

