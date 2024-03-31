/*****************************************************
** Program: insertsortAlgorithm.cpp (implementation file for program) 
** Author: Nikolas Achatz
** Date: 1/12/2021
** Description: Algorithm for merge sort
******************************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "math.h"
#include <stdlib.h>

using namespace std;

/***********************************
 *Description: Insert sort call function, this is used to call and use Insert sort.
 * It will return a sorted vector
 *Parameters: Vector container of type integer
 ************************************/
vector<int> insertSort(vector<int>);
/***********************************
 *Description: Generates and returns a random value from 0 to 10,000
 * It will return a sorted vector subset
 *Parameters: None
 ************************************/
int randomNumbers();

vector<int> insertSort(vector<int> vec){
    // For insert sort we know we just continuously check to see if the element
    // to the left is less than us. If it is, we simply swap the values and continue
    // forth. So we need to start at index 1 so we can compare that to index 0 and swap if needed


    int holdingValue, compareIndex;

    // Starting at the current index being 1, because we want to compare to
    // the index 0.
    for(int curIndex = 1; curIndex < vec.size(); curIndex++)
    {
        // We start by capturing the value at this index.
        holdingValue = vec[curIndex];  
        // We also need to grab the index we are comparing to, this is always one less, one to the left.
        compareIndex = curIndex - 1;  
  
        // Now all we need to do here is compare the index to the left of our value. If the index to the left is less than 0, 
        // we have to be done because there is no more values to sort. 
        // If we are comparing an index that is 0 or higher, we have to check to see if the value at the index to the left is less than the 
        // value we started at.
        while (compareIndex >= 0 && vec[compareIndex] > holdingValue) 
        {  
            // If the value to the left is greater than our starting value we need to set the compare index one to the right equal to its current value.
            vec[compareIndex + 1] = vec[compareIndex];
            // Now we send the comparing index to the left again to compare once more.  
            compareIndex = compareIndex - 1;  
        }  
        // If we have no more values or are done comparing greater than, we know we need to fill the compare index + 1 with our original value.
        // We fill compare index + 1 because the compare index is the index we are currently comparing our original number with and if it isn't greater
        // we do not swap.
        vec[compareIndex + 1] = holdingValue;  

    }

    return vec;
	

}

int randomNumbers(){
    // Return a number from 0 to 10,000 randomly
    int x = rand() % 10001;

    return x;

}