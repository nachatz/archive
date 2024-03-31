/*
 * Number System Conversion program. Created to convert decimal values to binary
 * and binary to hexidecimal. 
 * Achatz, Nikolas
 * 12/12/2020
 */

#include <iostream>
#include "Converter.h"

using namespace std;

int main()
{
	// Converter class
	Converter b;
	string s;


	cout << "Decimal system to binary system to hexidecimal system converter." << endl;

	while (true) {
		// Function to begin conversions
		b.decimal_to_binary();

		cout << endl << "-----------------------------------------" << endl;
		cout << endl << "Press 1 to run again." << endl;
		cout << "-----------------------------------------" << endl;

		cin >> s;

		if (s != "1")
			break;

	}
	
}

