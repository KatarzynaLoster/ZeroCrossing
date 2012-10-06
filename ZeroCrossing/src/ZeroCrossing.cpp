//============================================================================
// Name        : ZeroCrossing.cpp
// Author      : Katarzyna Loster
// Version     :
// Copyright   : Apache Commons
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void readNumbersIntoTable(int sequence[98])
{
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
		if ((sequence[i] > -10) && (sequence[i] < 10))
		{
			i++;
		}
		else
		{
			cout << "There is error in number of the sequence!\n ";
			break;
		}
	}
}

int countingZeroCrossing(int sequence2[98], int i, int number_zero)
{
	if ((sequence2[i] > 0) && (sequence2[i + 1] < 0))
	{
		number_zero++;
	}
	if ((sequence2[i] < 0) && (sequence2[i + 1] > 0))
	{
		number_zero++;
	}
	return number_zero;
}

void searchingZeroCrossing(int sequence2[98])
{
	int i = 0;
	int number_zero = 0;
	while (sequence2[i + 1] != 99)
	{

		number_zero = countingZeroCrossing(sequence2, i, number_zero);
		if ((sequence2[i + 2] == 99) || (sequence2[i + 1] == 99)
				|| (sequence2[i] == 99))
		{
			cout << "number of the zero crossing is: " << number_zero << endl;
			if ((number_zero < 5) || (number_zero > 8))
			{
				cout << "Error: Number of the zero crossing is incorrect!";
			}
			break;
		}
		i++;
	}
}

void rewritingNumbersFromSequenceToSequence2(int sequence2[98],
		int sequence[98])
{
	int i = 0;
	int j = 0;
	sequence2[0] = 0;
	while (sequence2[j] != 99)
	{
		if (sequence[i] != 0)
		{
			sequence2[j] = sequence[i];
			if (sequence2[j] != 99)
			{
				j++;
				i++;
			}
		}
		if (sequence[i] == 0)
		{
			i++;
		}
	}
}

bool readNumbersFromFile(int select, int sequence[98], bool isSequenceValid)
{
	if (select == 1)
	{
		string fileName;
		int i = 0;
		cout << "Enter the file name from Desktop: " << endl;
		cin >> fileName;
		string str;
		ifstream infile;
		infile.open(
				("C:\\Users\\kasia\\Desktop\\" + fileName + ".txt").c_str());
		if (infile.is_open())
		{
			getline(infile, str);
			stringstream ss(str);
			while (ss)
			{
				ss >> sequence[i];
				if (sequence[i] != 99)
				{
					i++;
				}
			}
			isSequenceValid = true;
		}
		else
		{
			cout << "File doesn't exist!\n";
		}
	}
	return isSequenceValid;
}

bool readManualData(int select, int sequence[98], bool isSequenceValid)
{
	if (select == 2)
	{
		cout << "Enter numbers manual:\n";
		readNumbersIntoTable(sequence);
		isSequenceValid = true;
	}
	return isSequenceValid;
}

void definitionOfTheProgramAndSelectSource(int & select)
{
	cout
				<< "This is the program which is counting the zero crossings or extremes in sequence of numbers in the range from -10 to 10\n"
				<< "Enter numbers between -10 and 10 less than 100. End sequence  of the number '99'.\n"
				<< "Number of the zero crossing should be range of from 5 to 8 "
				<< endl;
	cout << "Select the data source:\n" << "file txt - write '1';\n"
			<< "manual data entry - write '2'.\n";
	cin >> select;
}

int main()
{
	bool isSequenceValid = false;
	int sequence[98];
	int sequence2[98];
	int select;
	definitionOfTheProgramAndSelectSource(select);
	isSequenceValid = readNumbersFromFile(select, sequence, isSequenceValid);
	isSequenceValid = readManualData(select, sequence, isSequenceValid);
	if (isSequenceValid)
	{
		validateNumbers(sequence);
		rewritingNumbersFromSequenceToSequence2(sequence2, sequence);
		searchingZeroCrossing(sequence2);
		return 0;
	}
}
