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
				cout << "Error: Number of the zero crossing is incorrect!" << endl;
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

bool readNumbersFromFile(int sequence[98])
{
	bool isSequenceValid = false;
	string fileName;
	int i = 0;
	cout << "Enter the file name from Desktop: " << endl;
	cin >> fileName;
	string str;
	ifstream infile;
	infile.open(("C:\\Users\\kasia\\Desktop\\" + fileName + ".txt").c_str());
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
	return isSequenceValid;
}

void readManualData(int sequence[98])
{
	cout << "Enter numbers manual:\n";
	readNumbersIntoTable(sequence);
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

int countExtremesInRestNumbers(int sequence2[98], int i, int number_extremes)
{
	if ((sequence2[i] > 0) && (sequence2[i + 1] < sequence2[i])
			&& (sequence2[i] > sequence2[i - 1]))
	{
		number_extremes++;
	}
	if ((sequence2[i] < 0) && (sequence2[i + 1] > sequence2[i])
			&& (sequence2[i] < sequence2[i - 1]))
	{
		number_extremes++;
	}
	return number_extremes;
}

int countExtremesInFirstNumber(int sequence2[98], int number_extremes)
{
	if ((sequence2[0] > 0) && (sequence2[0]) > sequence2[1])
	{
		number_extremes++;
	}
	if ((sequence2[0] < 0) && (sequence2[0]) < sequence2[1])
	{
		number_extremes++;
	}
	return number_extremes;
}

void searchingAllExtremes(int sequence2[98])
{
	int i = 1;
	int number_extremes = 0;
	number_extremes = countExtremesInFirstNumber(sequence2, number_extremes);
	while (sequence2[i + 1] != 99)
	{
		number_extremes = countExtremesInRestNumbers(sequence2, i,
				number_extremes);
		if ((sequence2[i + 2] == 99) || (sequence2[i + 1] == 99)
				|| (sequence2[i] == 99))
		{
			cout << "number of the extremes is: " << number_extremes << endl;
			break;
		}
		i++;
	}
}

int main()
{
	bool isSequenceValid = false;
	int sequence[98];
	int sequence2[98];
	int select;
	definitionOfTheProgramAndSelectSource(select);
	if (select == 1)
	{
		isSequenceValid = readNumbersFromFile(sequence);
	}
	if (select == 2)
	{
		readManualData(sequence);
		isSequenceValid = true;
	}
	if (isSequenceValid)
	{
		validateNumbers(sequence);
		rewritingNumbersFromSequenceToSequence2(sequence2, sequence);

		searchingZeroCrossing(sequence2);

		searchingAllExtremes(sequence2);
	}
return 0;
}
