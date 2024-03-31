/*****************************************************
** Program: knapsack.cpp (implementation file for program) 
** Author: Nikolas Achatz
** Date: 1/28/2021
** Description: Randomly generates values for the knapsack problem.
** Solves the knapsack using normal recursion and then dynamic programming and 
** measures run times.
******************************************************/
 #include <iostream>
 #include <time.h>
 #include <vector>
 #include <stdio.h>      
 #include <stdlib.h>    
 #include <chrono>

using namespace std; 

 /***********************************
 *Description: Dynamic programming solution to the knapsack.
 * Utilizes the bottom up method to solve it in a faster time.
 *Parameters: weight limit, vector of weights, and vector of values
 ************************************/

int dpknapsack (int, vector<int> &, vector<int> &);

/***********************************
 *Description: Does all of the displaying of 
 * data as well as captures run times.
 *Parameters: amount of values, weight limit, vector of the weights, and vector of the values
 ************************************/
void display(int, int, vector<int>, vector<int>);

/***********************************
 *Description: Function that solves knapsack problem using basic
 * recursion.
 *Parameters: amount of values, weight limit, vector of weights, and vector of values.
 ************************************/
int knapsack (int, int, vector<int> & , vector<int> &) ;

 
int main() {

    srand(time(NULL));
    vector<int> weights, values;

    // Setting my array of n sizes to run through
    int n[7] = {20, 30, 40, 50, 60, 80, 100};

    // Setting my array of weight limits to run through
    int Warry[7] = {20, 30, 40, 50, 60, 80, 100};

    // Creating the holding size value
    int nHold = 100;

    // Creating the holding weight limit value
    int W = 100;  

    cout << endl << "Program start" << endl;
    cout << "Time is measured in microseconds" << endl;

    // Holding W size constant at 100 while varying n
    cout << endl << "-------------------------------------" << endl;
    cout << "Holding weight limit at: " << W << endl;

    // For each value of n in our array, create randomly generated values
    for(int i = 0; i < 7; i ++)
    {
        // Randomly generates values for that size of n
        for(int j = 0; j < n[i]; j++)
        {
            weights.push_back(rand() % 101 + 1);
            values.push_back(rand() % 101 + 1);
        }
        
        // Runs the algorithms and outputs run times
        display(n[i], W, weights,values);
        
        // Clears our vectors
        weights.clear();
        values.clear();
    }
    
    // Holding n size constant at 100
    cout << endl << "-------------------------------------" << endl;
    cout << "Holding size at: " << nHold << endl;
    
    // For each value of w in our array, create randomly generated values
    for(int i = 0; i < 7; i++)
    {
        // Randomly generates values for size 100
        for(int j = 0; j < nHold; j++)
        {
            weights.push_back((rand() % 101) + 1);
            values.push_back((rand() % 101) + 1);
        }

        // Runs the algorithms and outputs run times
        display(nHold, Warry[i], weights, values);

        // Clears our vectors
        weights.clear();
        values.clear();
    }

    return 0;
}


int dpknapsack (int W, vector<int> &weights, vector<int> &values) 
{

    // Our n size is just the size of the vector
    int n = weights.size();
    int new_item = 0, hold1 = 0, hold2 = 0;

    // This is our bottom up vector, every value is 0 by default
    // This means if our capacity is 0, we yield 0 and if our items is 0 then we yield 0
    vector<vector<int>> bottom_up (n + 1, vector<int> (W+1));

    // For every item starting at index 1
    // We start at index 1 because we are looking at the previous item as our new item
    for (int i = 1; i <= n; i++) 
        for (int capacity = 1; capacity <= W; capacity++) 
        {
            // Looking at our item to the left
            new_item = i - 1;
           
           // We will check to see if the weight of that item is less than or equal to the capacity
            if (capacity >= weights[new_item]) 
            {
                // Here we start the bottom up approach
                // We say a value is equal to that new item at our capacity.
                // In essence, we are creating a table of available weights x capacity
                hold1 = bottom_up[new_item][capacity];

                // Here we acquire another value by looking at the bottom up 
                // This starts our algorithm because at the start, all of these values are 0
                // Here we basically say add the value of the first item of our values
                hold2 = bottom_up[new_item][capacity-weights[new_item]] + values[new_item];

                // Now we compare the two, depending on which is larger we fill that into our table
                if (hold1 > hold2)
                    bottom_up[i][capacity] = hold1;
                else
                    bottom_up[i][capacity] = hold2;

            // If the weight is larger than our capacity, we just fill it into the table
            } else 
                bottom_up[i][capacity] = bottom_up[new_item][capacity];
        }

    return bottom_up[n][W];
}
  



int knapsack (int n, int W, vector<int> & weights, vector<int> & values) 
{

    int hold1, hold2;
    int new_item = n - 1;
    // No item can be put in the sack of capacity 0 so maximum value for sack of capcacity 0 is 0
    if (W != 0 && n != 0)
    {

        /* Note : Here the number of item is limited (unlike coin change / integer partition problem) 
        hence the numitems -> (numitems - 1) when the item is included in the knapsack */

        if (W >= weights[new_item])
        {
            hold1 = knapsack(new_item, W, weights, values);
            hold2 = knapsack(new_item, W - weights[new_item], weights, values) + values[new_item];
            if (hold1 > hold2)
                return hold1;
            else
                return hold2;
        }
        else
            return knapsack(new_item, W, weights, values);
    } else
        return 0;
}
  
void display(int n, int W, vector<int> weights, vector<int> values){

    // Uses chrono to get high resolution timings of the algorithms in microseconds.
    auto begin_r = chrono::high_resolution_clock::now();
    int max_r = knapsack(weights.size(), W, weights, values);
    auto end_r = chrono::high_resolution_clock::now();
    auto time_taken_r = chrono::duration_cast<chrono::microseconds>(end_r - begin_r);

    auto begin_dp = chrono::high_resolution_clock::now();
    int max_dp = dpknapsack(W, weights, values); 
    auto end_dp = chrono::high_resolution_clock::now();
    auto time_taken_dp = chrono::duration_cast<chrono::microseconds>(end_dp - begin_dp);


    cout << "N=" << n << " W=" << W << " Rec time = " << time_taken_r.count() << " DP time = " << time_taken_dp.count() << " max Rec = " << max_r << " max dp = " << max_dp << endl;

}