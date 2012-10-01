//============================================================================
// Name        : ZeroCrossing.cpp
// Author      : Katarzyna Loster
// Version     :
// Copyright   : Apache Commons
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int sequence[98];
	cout
			<< "This is the program which is counting the zero crossings in sequence of numbers in the range from -10 to 10\n"
					"Enter numbers between -10 and 10 less than 100. End sequence  of the number '99'. "
			<< endl;
	int i = 0;
	sequence[0] = 0;
	while (sequence[i] != 99) {
		cin >> sequence[i];
		if (sequence[i] != 99) {
			i++;
		}
	}

	return 0;
}
