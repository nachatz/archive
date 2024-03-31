/*****************************************************
** Program: mergesortAlgorithm.cpp (implementation file for program) 
** Author: Nikolas Achatz
** Date: 1/12/2021
** Description: Algorithm for merge sort
******************************************************/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "math.h"


using namespace std;

/***********************************
 *Description: Merge sort call function, this is used to call and use merge sort.
 * It will return a sorted vector
 *Parameters: Vector container of type integer
 ************************************/
vector<int> mergeSort(vector<int>);
/***********************************
 *Description: Merge function which processes the divide and
 * conquer algorithm.
 * It will return a sorted vector subset
 *Parameters: 2 Vector container of type integer, the left side of the previous vector and the right side of the previous vector
 ************************************/
vector<int> merge(vector<int>, vector<int>);
/***********************************
 *Description: Generates and returns a random value from 0 to 10,000
 * It will return a sorted vector subset
 *Parameters: None
 ************************************/
int randomNumbers();


vector<int> merge(vector<int> l, vector<int> r){

	// Here I create all of my variables for clear editing
	int sizeRight = r.size();
	int sizeLeft = l.size();
	// We need to total size of the array to iterate through each value
	int total = sizeLeft + sizeRight;
	// This lets us check if the left side is less than the right side
	bool leftChecker;
	// A counter for the left side
    int lAmnt = 0;
	// A counter for the right side
    int rAmnt = 0;
	// The sort subsection of the array
	vector<int> sortedVector;

	// Ensure we use proper capacity
	sortedVector.reserve(total);

	// Loop for each index
	for (int i = 0; i < total; i++) {
		
		//We check to see if the left counter is less than our left vector size
		// If it is, we then need to check to see if the right counter is also less than its size
		// If this hapens then we need to compare values in the left array and the right array
		// If the left is less than the right, left checker becomes true
		if (lAmnt < sizeLeft) {
			if (rAmnt < sizeRight) 
				leftChecker = (l[lAmnt] < r[rAmnt]);
			else 
				leftChecker = true;
		}else 
			leftChecker = false;

		// This is where we "swap" values because if our left value is less than the right value
		// we want to import that value before the right value
		// Here we import left value and increment the counter
		// otherwise we do the same for the right side.
		if (leftChecker) {
			sortedVector.push_back(l[lAmnt]);
			if (lAmnt < sizeLeft) 
				lAmnt++;
		}
		else {
			sortedVector.push_back(r[rAmnt]);
			if (rAmnt < sizeRight) 
				rAmnt++;
		}
	}


	// return our sorted array
	return sortedVector;

}


vector<int> mergeSort(vector<int> vec){

	// Here we make sure our vector is even big enough to be sorted, if it isnt, we just return the vector.
    if (vec.size() <= 1) 
		return vec;
	
	// Here using the vector library we can deep copy our old vector into these new vectors
	// Here starting at the 0 index of vec we will copy up until the size of the vector divided by 2.
	vector<int> left(vec.begin(), vec.begin() + (vec.size() / 2));
	
	// Here we start at the 0 index and add the size / 2 to get our new starting point. From here we deep copy the vector
	// until the end of the vec vector.
	vector<int> right(vec.begin() + (vec.size() / 2), vec.end());

	// Send it through the merge sort function to get our new sorted vector.
	return merge(mergeSort(left), mergeSort(right));
    
}

int randomNumbers(){

	// Random value from 0 to 10,000
    int x = rand() % 10001;

    return x;

}