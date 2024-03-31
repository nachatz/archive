/* Nikolas Achatz
*
* Simple program that will find the shortest path on a diagonal of a nxn matrix
*
*
* 2/2/2021
* <3
*/
#include <iostream>

using namespace std;
// Function displays our path in a grid
void Display(bool**, int, int, int);

// Algorithm that finds the shortest path from the (0,0) position
void FindShortest(bool**, int, int, int);

int main()
{
    int size, colToFind, rowToFind;
    cout << "Enter the size of your grid: ";
    cin >> size;

    // Create our grid
    bool** path = new bool* [size];
    for (int i = 0; i < size; i++)
        path[i] = new bool[size];

    // Make sure all equal false
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            path[i][j] = false;

    // Take in the target from user
    cout << "Enter the row and column to move to (1 - size)" << endl << "Row: ";
    cin >> rowToFind;
    cout << "Column: ";
    cin >> colToFind;

    // Ensure we aren't searching for origin
    if (rowToFind == 0 && colToFind == 0) {
        cout << "Can't select origin" << endl;
        return 0;
    }

    // Output where we are looking for
    cout << "BEFORE PATHFIND" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i + 1 == rowToFind && j + 1 == colToFind)
                cout << "| x ";
            else
                cout << "|   ";
        }

        cout << "| " << endl;
    }
    
    cout << endl << endl;
    cout << "AFTER PATHFIND" << endl;

    // Run the algorithm and output the path
    FindShortest(path, size, rowToFind, colToFind);
}



void FindShortest(bool** path, int size, int trow, int tcol) {

    int col = 0, row = 0;
    int i = 0, j = 0;

    trow = trow - 1;
    tcol = tcol - 1;

    // Check if we are at the right row and column
    // If row and col arent matching, we increase both and add to our path
    // if row isn't matching, but column is, the path needs to go down so we add to our path and increase row
    // likewise if col doesn't match, but row does, we increase col as our path needs to go to the right
    while (true) {
        if (i != trow && j != tcol)
            path[i++][j++] = true;
        else if (j != tcol)
            path[i][j++] = true;
        else if (i != trow)
            path[i++][j] = true;

        if (i == trow && j == tcol) {
            path[i][j] = true;
            break;
        }
    }

    // Simple display function
    Display(path, trow, tcol, size);


}

void Display(bool** path, int trow, int tcol, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) 
            if (path[i][j] == true)
                cout << "| X ";
            else
                cout << "|   ";
     
        cout << "| " << endl;
    }

}