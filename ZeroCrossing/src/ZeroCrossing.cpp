//============================================================================
// Name        : ZeroCrossing.cpp
// Author      : Katarzyna Loster
// Version     :
// Copyright   : Apache Commons
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void readNumbersIntoTable(int sequence[98])
{
	cout
			<< "This is the program which is counting the zero crossings in sequence of numbers in the range from -10 to 10\nEnter numbers between -10 and 10 less than 100. End sequence  of the number '99'. "
			<< endl;
	int i = 0;
	sequence[0] = 0;
	while (sequence[i] != 99)
	{
		cin >> sequence[i];
		if (sequence[i] != 99)
		{
			i++;
		}
	}
}

void validateNumbers(int sequence[98])
{
	int i = 0;
	while (sequence[i] != 99)
	{
		if (sequence[i] == 99 || (sequence[i] > -10 && sequence[i] < 10))
		{
			i++;
		}
		else
		{
			cout << "There is error in number of the sequence\n ";
			break;
		}
	}
}

void searchingZeroCrossing(int sequence[98])
{
	int i = 0;
	int number_zero = 0;
	while (sequence[i + 1] != 99)
	{
		if ((sequence[i] > 0) && (sequence[i + 1] < 0))
		{
			number_zero++;
		}
		if ((sequence[i] < 0) && (sequence[i + 1] > 0))
		{
			number_zero++;
		}
		if (sequence[i + 2] == 99)
		{
			cout << "number of the zero crossing is: " << number_zero;
			break;
		}
		i++;
	}
}

int main()
{
	int sequence[98];
	readNumbersIntoTable(sequence);
	validateNumbers(sequence);
	searchingZeroCrossing(sequence);
	return 0;
}
