/*****************************************************
** Program: euclideanMst.cpp (implementation file for program)
** Author: Nikolas Achatz
** Date: 2/22/2021
** Description: Calculates the weight of the MST from given x and y points in a plane
******************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <stack>


using namespace std;

// Structure built to hold positions
struct Position
{
    double x, y;
    bool visited;
};


// THIS IS THE ALGORITHM USED IN THE SOLUTION
/***********************************
 *  Description: Calculates the weight of the MST of given x and y points in a plane
 *  Outputs total to terminal. Utilizes prims algorithm ideals.
 *  Parameters: vector of positions
 ************************************/
void calculateWeights(vector<Position> pos);


// THIS FUNCTION IS NOT USED AND WAS KEPT FOR STUDY PURPOSES. IT DOES NOT UTILIZE PRIMS ALGORITHM IT IS PURELY A GREEDY ALGORITHM
/***********************************
 *  Description: Calculates the weight of the MST of given x and y points in a plane
 *  Outputs total to terminal. This function utilizes non-transferring vectors, but iterating over the entire
 *  node set twice. Worse complexity and doesn't hold true to all of Prims ideals. It only follows one node and
 *  does not take into account distances from any visited node. Only checks from current node.
 *  Parameters: vector of positions
 ************************************/
 // IGNORE THIS FUNCTION
void calculateMSTNonPrim(vector<Position> pos, int run);

int main()
{

    fstream input;
    int inp, testCases, posX, posY;
    vector<Position> positions;
    input.open("graph.txt");

    if (input.is_open())
        cout << "file opened" << endl;
    else
    {
        cout << "file failed opening, closing program ensure you have a graph.txt file" << endl;
        return -1;
    }

    // Reading in the test cases
    input >> testCases;
    // Reading in our point count
    input >> inp;

    for (int k = 0; k < testCases; k++)
    {
        // Adding our points to a position vector
        for (int i = 0; i < inp; i++)
        {
            input >> posX;
            input >> posY;
            Position hold = { posX,posY, false };
            positions.push_back(hold);
        }

        // Calling the prim algorithm
        calculateWeights(positions);
        positions.clear();

        // Reading in the new point count
        input >> inp;

    }

    return 0;

}

// This is the function utilized with Prims and is used in the program and final solution
void calculateWeights(vector<Position> pos)
{
    // Static count so we can keep track of our test cases
    static int count = 1;
    cout << endl << endl;
    double mst = 0, min = -1;
    vector<Position> visited;
    bool allVisited = true;

    visited.push_back(pos[0]);
    pos.erase(pos.begin());

    int nX, nY;

    cout << "Test case: " << count << endl;
    cout << "---------------------------" << endl;

    // Until the positions vector is empty run
    while (!pos.empty())
    {
        // For each visited node we need to see which has then next sortest path
        for (int i = 0; i < visited.size(); i++)
            // We need to check each visited node against unvisited nodes to see where to travel
            for (int j = 0; j < pos.size(); j++)
                // if the distance to this unvisited node from this visited node is smaller than the current min, set it to our next destination
                if ((sqrt(pow((visited[i].x - pos[j].x), 2) + pow((visited[i].y - pos[j].y), 2))) < min || min == -1)
                {
                    min = sqrt(pow((visited[i].x - pos[j].x), 2) + pow((visited[i].y - pos[j].y), 2));
                    nX = pos[j].x;
                    nY = pos[j].y;
                }

        // Find where our next position is and erase it and add it to the visited nodes
        for (int i = 0; i < pos.size(); i++)
        {
            if (pos[i].x == nX && pos[i].y == nY)
            {
                visited.push_back(pos[i]);
                pos.erase(pos.begin() + i);
                //cout << "Min added: " << round(min) << endl;
                mst += round(min);
                min = -1;

            }
        }
    }

    // Output and increase static count
    cout << "MST: " << mst << endl;
    count++;
}

// This function is not used. Please ignore.
void calculateMSTNonPrim(vector<Position> pos, int run)
{
    static int count = 1;
    cout << endl << endl;
    double mst = 0, min = 50000000;
    vector<Position> transfer;
    bool allVisited = true;
    Position cur = pos[0];
    pos[0].visited = true;

    int nX, nY;

    cout << "Test case: " << count << endl;
    cout << "---------------------------" << endl;
    while (true) {
        for (int i = 0; i < pos.size(); i++)
        {
            if (pos[i].visited != true) {
                if ((sqrt(pow((cur.x - pos[i].x), 2) + pow((cur.y - pos[i].y), 2))) < min)
                {
                    min = sqrt(pow((cur.x - pos[i].x), 2) + pow((cur.y - pos[i].y), 2));
                    nX = pos[i].x;
                    nY = pos[i].y;
                }
            }
        }

        for (int i = 0; i < pos.size(); i++)
        {
            if (pos[i].x == nX && pos[i].y == nY)
            {
                pos[i].visited = true;
                cur = pos[i];
                cout << "Min added: " << round(min) << endl;
                mst += round(min);
                min = 5000000;
            }
        }

        for (int i = 0; i < pos.size(); i++)
            if (pos[i].visited == false)
                allVisited = false;

        if (allVisited)
            break;

        allVisited = true;
    }

    cout << "MST: " << mst << endl;
    count++;
}