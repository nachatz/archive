#include "Converter.h"
#include <iostream>


using namespace std;

/*
 * Functionality for converting a decimal number to a binary number.
 * This function takes a integer value from the user and divides it down by
 * 2 taking the remainders to be the corresponding binary value. The last 
 * remainder is the most significant bit.
 *
 */

void Converter::decimal_to_binary() {
	// Decimal value from user
    int value;
	// Remainder value
    int rem;
	// Bit count
    int count = 0;

	// User input
    cout << "Enter a decimal system value (Unsigned Integer): ";
    cin >> value;

	// Determines how many bits will be needed by dividing the value down to 0
    for (int i = value; i > 0; i = i / 2)
        count++;
  
	// Instantiate new memory for binary value
    binary_vals = new int[count];

	// Take the remainder and store that into the binary array
    for (int i = 0; i < count; i++) {
        rem = value % 2;
		// Stores the remainder in the back of the array since the most significant bit is the last value yielded
        binary_vals[count - i - 1] = rem;
        value = value / 2;
    }

	// Value output
	cout << endl << endl << " Binary Values " << endl;

    for (int i = 0; i < count; i++)
        cout << binary_vals[i] << " ";


	binary_to_hex(binary_vals, count);


	// Free allocated memory
    delete[] binary_vals;
}


/*
 * Function takes a binary number in and converts it to a hexidecimal value.
 * To do this we need a 4-bit binary number or a array of 4-bit binary numbers.
 * This means we have to translate the old array of N-bits into a divisible by 
 * 4 N-bit value. 
 *
 * Params:
 *   binary_vals - Array of binary values to convert to hexidecimal
 *   count - Amount of bits in the value
 */

void Converter::binary_to_hex(int* binary_vals, int count) {

	// Binary vals translated to divisible by 4 count
	int* translated_vals;
	// Hexidecimal values after conversion
	int* hex_vals;
	// Yields a new count that is divisible by 4
	int translate_val = translation(count);
	// New count for translated values
	int trans_count = 0;

	// Takes the old count and adds the values needed to make it divisible by 4
	trans_count = count + translate_val;
	// Creates a new array of binary values with proper size
	translated_vals = new int[trans_count];

	// Sends all of the old binary values to the new array taking into account how many zeroes
	// are needed to be added to the front to make this divisible by 4 bits.
	for (int i = 0; i < count; i++) 
		translated_vals[i + translate_val] = binary_vals[i];
	
	// Sets the front values to 0 to buffer
	for (int i = 0; i < translate_val; i++)
		translated_vals[i] = 0;


	// Create our hexidecimal value array, should take 1 value per 4 bits of binary digits
	hex_vals = new int[trans_count / 4];
	// Acquires the hexidecimal values
	hex_vals = acquire_sums(hex_vals, translated_vals, trans_count);


	cout << endl << endl << " HEX VALUES " << endl;

	// Converts all values into corresponding hexidecimal values
	for (int i = 0; i < (trans_count / 4); i++)
		hex_value_converter(hex_vals[i]);

	// Free allocated memory
	delete[] translated_vals;
	delete[] hex_vals;

}


/*
 * This function takes in the binary values and multiples the MSB of each
 * 4-bit value by 8, then the 2nd bit by 4, the 3rd bit by 2, and the last bit by 1.
 * Adding all of these gives us the hexidecimal value for that 4-bit value.
 *
 * Params:
 *   hex_vals - The array of hexidecimal values to be filled.
 *	 binary_vals - The array of our binary values.
 *	 count - The number of bits in our binary number.
 */

int* Converter::acquire_sums(int* hex_vals, int* binary_vals, int count) {

	// Tracker of which binary value we are at
	int tracker = 0;
	// Sum of the conversion
	int sum = 0;

	// Take the amount of binary digits and split them into groups of 4
	for (int i = 0; i < (count / 4); i++) {

		// Each group of 4 need to be multiplied by the correct value and added to the sum
		for (int j = 0; j < 4; j++) {
			switch (j)
			{
			case 0:
				sum = sum + (binary_vals[tracker] * 8);
				break;
			case 1:
				sum = sum + (binary_vals[tracker] * 4);
				break;
			case 2:
				sum = sum + (binary_vals[tracker] * 2);
				break;
			case 3:
				sum = sum + (binary_vals[tracker] * 1);
				break;

			}
			// Move forward one value in the binary array
			tracker++;
		}
		// The sum of that 4-bit value is the hexidecimal value for this place
		hex_vals[i] = sum;
		// Reset sum
		sum = 0;
	}

	// Return our hexidecimal values to be converted
	return hex_vals;

}


/*
 * This function takes the current count and helps translate
 * that count to a divisible by 4 value.
 * Params:
 *   count - The amount of values in the current array.
 */

int Converter::translation(int count) {

	int translate_val = count % 4;

	if (translate_val == 1)
		translate_val = 3;
	else if (translate_val == 2)
		translate_val = 2;
	else if (translate_val == 3)
		translate_val = 1;

	return translate_val;

}


/*
 * This function converts every hexidecimal value to its
 * correct value.
 *
 * Params:
 *   x - The value of the hexidecimal to be converted
 */

void Converter::hex_value_converter(int x) {

	switch(x){
		case 10:
			cout << "A ";
			break;
		case 11:
			cout << "B ";
			break;
		case 12:
			cout << "C ";
			break;
		case 13:
			cout << "D ";
			break;
		case 14:
			cout << "E ";
			break;
		case 15:
			cout << "F ";
			break;
		default:
			cout << x << " ";
			break;
	
	}
}