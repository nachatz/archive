#pragma once
/*
 * Definition interface of the converter class. 
 * Achatz, Nikolas
 * 12/12/2020
 */

class Converter
{
private:
	int* binary_vals;
	void binary_to_hex(int*, int);
	int translation(int);
	void hex_value_converter(int);
	int* acquire_sums(int*, int*, int);

public:
	void decimal_to_binary();
};