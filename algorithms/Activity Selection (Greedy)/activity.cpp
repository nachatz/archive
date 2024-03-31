/*
 * Nikolas Achatz
 * 2/08/2021
 * 
 * Activity selection program
 * 
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Activity {

    int number;
    int start;
    int end;

};

/***********************************
 *Description: Merge function which processes the divide and
 * conquer algorithm.
 * It will return a sorted vector subset
 *Parameters: 2 Vector container of type integer, the left side of the previous vector and the right side of the previous vector
 ************************************/
 vector<Activity> merge(vector<Activity> l, vector<Activity> r){

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
	vector<Activity> sortedVector;

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
				leftChecker = (l[lAmnt].start > r[rAmnt].start);
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

/***********************************
 *Description: Merge sort call function, this is used to call and use merge sort.
 * It will return a sorted vector according to start times
 *Parameters: Vector container of type Activity
 ************************************/
vector<Activity> mergeSort(vector<Activity> vec){

	// Here we make sure our vector is even big enough to be sorted, if it isnt, we just return the vector.
    if (vec.size() <= 1) 
		return vec;
	
	// Here using the vector library we can deep copy our old vector into these new vectors
	// Here starting at the 0 index of vec we will copy up until the size of the vector divided by 2.
	vector<Activity> left(vec.begin(), vec.begin() + (vec.size() / 2));
	
	// Here we start at the 0 index and add the size / 2 to get our new starting point. From here we deep copy the vector
	// until the end of the vec vector.
	vector<Activity> right(vec.begin() + (vec.size() / 2), vec.end());

	// Send it through the merge sort function to get our new sorted vector.
	return merge(mergeSort(left), mergeSort(right));
    
}

int main(){

    ifstream file;
    vector<Activity> activities;
    vector<Activity> selected;
    int amount, k = 1, location = 0, hold = 0;
    file.open("act.txt");

    // Ensure our file is open
    if(file.is_open())
        cout << "File opened" << endl;
    else{
        cout << "No act.txt found, closing program" << endl;
        return 0;
    }

    cout << endl << endl;

    // Read in our file until we are at the end.
    while(file >> amount)
    {
        location = 0;
        // For each activity add it's start, end, and number
        for(int i = 0; i < amount; i++)
        {
            Activity currActivity;
            file >> hold;
            currActivity.number = hold;
            file >> hold;
            currActivity.start = hold;
            file >> hold;
            currActivity.end = hold;   
            activities.push_back(currActivity);     
        }

        cout << endl << "Set " << k;
        k++;
        // Sort our activities by largest start time
        activities = mergeSort(activities);

        // The first selection is always a selected one
        selected.push_back(activities[0]);

        // Check if the next activity ends when or before our last start, if so add.
        for(int i = 1; i < activities.size(); i++)
            if(activities[i].end <= selected[location].start){
                selected.push_back(activities[i]);
                location++;
            }

        // Output the selected schedule
        cout << endl << endl;
        cout << "Number of activities selected: " << selected.size() << endl;
        cout << "Activities: ";
        for(int i = selected.size() - 1; i >= 0; i--)
            cout << selected[i].number << " ";

        cout << endl;


        // Clear arrays
        selected.clear();
        activities.clear();
    }



}


