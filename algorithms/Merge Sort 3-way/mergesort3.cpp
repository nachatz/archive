/*****************************************************
** Program: mergesort3.cpp (implementation file for program) 
** Author: Nikolas Achatz
** Date: 1/18/2021
** Description: Reads in values from a file named "data.txt" and then puts them through merge sort with 3 way division.
** Outputs sorted values
** EXAMPLE
** 4 5 6 4 3 -> it will sort 3 4 5 6
******************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "math.h"
#include <stdlib.h>


using namespace std;

/***********************************
 *Description: Generates and returns a random value from 0 to 10,000
 * It will return a sorted vector subset
 *Parameters: None
 ************************************/

int randomNumbers();
/***********************************
 *Description: Actual merging function. This function takes in basically 3
 *sub vectors using index ranges and merges from there inside the live referenced vector that was passed.
 *this allows us to return nothing, but edit the value to get our sorted vector
 *Parameters: Vector reference of type integer, a minimum index, maximum index, size of the left vector, and size of the middle vector.

 ************************************/
void merge(vector<int> &, int, int, int, int);

/***********************************
 *Description: Merge function which processes the divide and
 * conquer algorithm.
 * It will edit the value at the address it is passed with the sorted array
 * This function does our recursion and demonstrates the DAC algorithm
 *Parameters: 1 Vector container of type integer passed by reference, minimum integer value and the maximum integer value of indices to merge through
 ************************************/
void mergesort3(vector<int> &, int, int);

int main(){

    cout << "MERGE SORT 3" << endl;

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

        mergesort3(arr, 0, arr.size());

        // Output our sorted values
        for(int i = 0; i < create; i++)
            cout << arr.at(i) << " ";

        // Clear the vector so we can sort the other lines.
        arr.clear();


        cout << endl;
    }

    return 0;

}




int randomNumbers(){

	// Random value from 0 to 10,000
    int x = rand() % 10001;

    return x;

}

void merge(vector<int> &vec, int min, int max, int leftsize, int midsize){

    int minHold = min;
    int leftsizeHold = leftsize;
    int middleSizeHold = midsize;

    vector<int> sortedVec;

    // I based this code off of the textbook, youtube video "https://www.youtube.com/watch?v=4VqmGXwpLqc", and geeks4geeks "https://www.geeksforgeeks.org/3-way-merge-sort/".
    // Similar to the first mergesort, I want to compare all values of the three until one of these vectors are empty
    // To explain this wee see minhold set to say 0 and left size is 5, this will go until we get to the size of 5
    // further leftsizehold is equal to left size say 5 and 10 and middle size will go until it hits max say 10 and 15.
    // Every time we make a comparison and see that one value is larger we push it into our sorted vector and increase its hold value so we know when that vector is in essence "empty"
    // If one vector is empty, we don't need to compare it any longer so we move to our next step
    // first compare the left with the middle vector 
    // now lets compare the left with our right vector
    // if larger than both we push that value in and increase its count
    // otherwise here we know its larger than the middle, but smaller than the right so push the right
    // else left is smaller than middle, check if middle is smaller than right

    while (minHold < leftsize && leftsizeHold < midsize && middleSizeHold < max)
		if (vec[minHold] < vec[leftsizeHold]) 
			if (vec[minHold] < vec[middleSizeHold]) 
				sortedVec.push_back(vec[minHold++]);
			else 
				sortedVec.push_back(vec[middleSizeHold++]);
        else 
			if (vec[leftsizeHold] < vec[middleSizeHold]) 
				sortedVec.push_back(vec[leftsizeHold++]);
			else 
				sortedVec.push_back(vec[middleSizeHold++]);
		

	// This case demonstrates that our left and mid vectors are still present
    // So we do the exact same steps here and we compare if the value in the left vector
    // is smaller than that of the mid vector.
    // if so, push the value in the mid vector to the merged vector
    // otherwise push value from left vector to merge vector

	while (minHold < leftsize && leftsizeHold < midsize) 
		if (vec[minHold] < vec[leftsizeHold]) 
			sortedVec.push_back(vec[minHold++]);
		else 
			sortedVec.push_back(vec[leftsizeHold++]);
	
    
    // This is the exact same as the above, but in this case the left vector
    // has been rendered as empty so we just need to compare the middle and right vectors for
    // merging

	while (leftsizeHold < midsize && middleSizeHold < max) 
		if (vec[leftsizeHold] < vec[middleSizeHold]) 
			sortedVec.push_back(vec[leftsizeHold++]);
		else 
			sortedVec.push_back(vec[middleSizeHold++]);
	

    // Our last case here is that our middle vector is rendered empty so
    // we just compare values of the left vector and the right vector.

	while (minHold < leftsize && middleSizeHold < max) 
		if (vec[minHold] < vec[middleSizeHold]) 
			sortedVec.push_back(vec[minHold++]);
		else
			sortedVec.push_back(vec[middleSizeHold++]);
		

	// if the left vector isnt empty, we need to just push all values into the merged vector

	while (minHold < leftsize) 
		sortedVec.push_back(vec[minHold++]);
	
	// if the middle vector isnt empty, we need to just push all values into the merged vector

	while (leftsizeHold < midsize) 
		sortedVec.push_back(vec[leftsizeHold++]);

	// if the right vector isnt empty, we need to just push all values into the merged vector
    
	while (middleSizeHold < max) 
		sortedVec.push_back(vec[middleSizeHold++]);
	
	
    // starting at our lowest index to our highest index we need to take values from the vector
    // we intake and set themp to our merged vector otherwise we won't get desirable results
    // since we are passing by reference and need to edit the values at our initial vectors address

    for (int i = min; i < max; i++) 
		vec[i] = sortedVec[i - min];
	
}


void mergesort3(vector<int> &vec, int min, int max){

	// Here we make sure our vector is even big enough to be sorted, if it isnt, we just return the vector

    if (max - min >= 2) 
    {

    // Here we divide our array into 3 parts and we recursively call this function until we get the sizes we want
    // geeks4geeks seen in the merge function helped me determine how to divide this into 3 sub vectors

    int leftmax = min + ((max - min) / 3);
	int midmax = min + 2 * ((max - min) / 3) + 1;

    mergesort3(vec, min, leftmax);
    mergesort3(vec, leftmax, midmax);
    mergesort3(vec, midmax, max);


    // Once we hit the desired size we can actually begin the merging

    return merge(vec, min, max, leftmax, midmax);

    }

}