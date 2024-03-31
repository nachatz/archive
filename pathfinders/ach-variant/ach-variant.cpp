/*
Nikolas Achatz
February 15th, 2021

Achatz variant algorithm based off of DFS.

*/

// Outputting to screen, not needed for algorithm
#include <iostream>
// Stack needed for algorithm, but can utilize a array if you understand the concept
#include <stack>
// All of these are used for formatting
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;

// Structure that holds a postion
struct Position 
{

	int row;
	int col;

};


/*
* Display
*
* Displays the current grid
*
* PARAMS
*
* 	int** grid - 2D array of our grid
*/
void Display(int** grid)
{

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if(i == 0 && j == 0)
				cout << "| X ";
			else if (grid[i][j] == 0)
				cout << "|   ";
			else if (grid[i][j] == 1)
				cout << "| O ";
			else if (grid[i][j] == 2)
				cout << "| X ";
		}
		cout << endl;
	}

}


/*
* Achatz Variant algorithm
*
* Modifying BFS we can acquire a algorithm that is better in less complex
* situations. Works similarly to A star, but has DFS as a back up in the scenario something
* fails.
*
* PARAMS
*
* 	int** grid - 2D array of our grid
*   int trow  - target row
*   int tcol - target col
*/
void AchatzVariant(int** grid, int trow, int tcol) 
{

	// Creating our start and end positions
	Position start = { 0,0 };
	Position end = { trow, tcol };
	// Stack
	stack<Position> stack;

	// Push our starting position
	stack.push(start);

	// Until the stack is empty or until we find our position
	while (!stack.empty())
	{
		// Animating path
		system("CLS");
		Display(grid);
		chrono::milliseconds dura(200);
		this_thread::sleep_for(dura);

		// Our current node
		Position curNode = stack.top();

		// Go to the correct row
		if (curNode.row > end.row) 
			if (curNode.row - 1 >= 0 && curNode.row - 1 <= 10) {
				Position up = { curNode.row - 1, curNode.col };
				if (grid[up.row][up.col] == 2)
					break;
				if (!grid[up.row][up.col] == 1)
				{
					stack.push(up);
					grid[up.row][up.col] = 1;
					continue;
				}

			}

		// Go to the correct row
		if (curNode.row < end.row) 
			if (curNode.row + 1 >= 0 && curNode.row + 1 <= 10) {
				Position down = {curNode.row + 1, curNode.col };
				if (grid[down.row][down.col] == 2)
					break;
				if (!grid[down.row][down.col] == 1)
				{
					stack.push(down);
					grid[down.row][down.col] = 1;
					continue;

				}

			}
		
		// Go to the correct col
		if (curNode.col > end.col) 
			if (curNode.col - 1 >= 0 && curNode.col - 1 <= 10) {
				Position left = {curNode.row, curNode.col - 1 };
				if (grid[left.row][left.col] == 2)
					break;
				if (!grid[left.row][left.col] == 1)
				{
					stack.push(left);
					grid[left.row][left.col] = 1;
					continue;

				}

			}
		
		// Go to the correct col
		if (curNode.col < end.col) {
			if (curNode.col + 1 >= 0 && curNode.col + 1 <= 10) {
				Position right = { curNode.row, curNode.col + 1 };

				if (grid[right.row][right.col] == 2)
					break;

				if (!grid[right.row][right.col] == 1)
				{
					stack.push(right);
					grid[right.row][right.col] = 1;
					continue;

				}

			}
		}


		// Here you will implement standard DFS algorithm, but since there is no barricades,
		// this code will never be ran, but if whomever is reading this wanted to add barricades,
		// you would need a default algorithm in the case that the above fails

		// Make sure that the node above is valid, if it is let's check it by pushing it to the stack
		if (curNode.row - 1 >= 0 && curNode.row - 1 <= 10) 
		{
			Position up = {curNode.row - 1, curNode.col };
			if (grid[up.row][up.col]== 2)
				break;
			if (!grid[up.row][up.col] == 1)
			{
				stack.push(up);
				grid[up.row][up.col] = 1;
				continue;

			}

		}

		// Make sure that the right node is valid, if it is let's check it by pushing it to the stack
		if (curNode.col + 1 >= 0 && curNode.col + 1 <= 10) 
		{
			Position right = {  curNode.row, curNode.col + 1 };

			if (grid[right.row][right.col] == 2)
				break;

			if (!grid[right.row][right.col] == 1)
			{
				stack.push(right);
				grid[right.row][right.col] = 1;
				continue;

			}

		}

		// Make sure that the down node is valid, if it is let's check it by pushing it to the stack
		if (curNode.row + 1 >= 0 && curNode.row + 1 <= 10) 
		{
			Position down = {curNode.row + 1, curNode.col };
			if (grid[down.row][down.col] == 2)
				break;
			if (!grid[down.row][down.col] == 1)
			{
				stack.push(down);
				grid[down.row][down.col] = 1;
				continue;

			}

		}

		// Make sure that the left node is valid, if it is let's check it by pushing it to the stack
		if (curNode.col - 1 >= 0 && curNode.col - 1 <= 10) 
		{
			Position left = { curNode.row,  curNode.col - 1 };
			if (grid[left.row][left.col] == 2)
				break;
			if (!grid[left.row][left.col] == 1)
			{
				stack.push(left);
				grid[left.row][left.col] = 1;
				continue;

			}

		}

		// pop that node
		stack.pop();

	}

	system("CLS");

	if (stack.size() == 0)
		cout << "No path, which should never happen since we don't have barricades" << endl;

	cout << "Distance taken: " << stack.size() << endl;
	Display(grid);

}


int main()
{
	int trow, tcol, inp;
	int** grid = new int*[11];
	for (int i = 0; i < 11; i++)
		grid[i] = new int[11];


	while (true) 
	{
		system("CLS");
		cout << "Path finding algorithm, Achatz Variant" << endl;
		cout << "Enter target row (0 - 10)" << endl;
		cin >> trow;
		cout << "Enter target col (0 - 10)" << endl;
		cin >> tcol;

		if (trow > 10 || trow < 0 || tcol > 10 || tcol < 0)
			break;

		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				grid[i][j] = 0;

		grid[trow][tcol] = 2;

		AchatzVariant(grid, trow, tcol);

		cout << "Do you want to run again 1 - yes 2 - no: ";
		cin >> inp;

		if (inp == 1)
			continue;

		break;


	}

	for (int i = 0; i < 11; i++)
			delete[] grid[i];

	delete[] grid;

	return 0;
}

