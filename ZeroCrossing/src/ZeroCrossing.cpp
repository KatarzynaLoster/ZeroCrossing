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

void readNumbersIntoTable(int sequence[98][98], const int k)
{
	int i = 0;
	sequence[k][0] = 0;
	while (sequence[k][i] != 99)
	{
		cin >> sequence[k][i];
		if (sequence[k][i] == 100)
		{
			break;
		}
		if (sequence[k][i] != 99)
		{
			i++;
		}
	}
}

bool validateNumbers(int sequence[98][98])
{
	bool isNumbersValid = true;
	int i = 0;
	int k = 0;
	while (sequence[k][i] != 100)
	{
		while (sequence[k][i] != 99)
		{
			if ((sequence[k][i] > -10) && (sequence[k][i] < 10))
			{
				i++;
			}
			else
			{
				cout << "There is error in number of the sequence!\n ";
				isNumbersValid = false;
				break;
			}
		}
		if (sequence[k][0] == 100)
		{
			break;
		}
		k++;
		i = 0;
	}
	return isNumbersValid;
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
				cout << "Error: Number of the zero crossing is incorrect!"
						<< endl;
			}
			break;
		}
		i++;
	}
}

void rewritingNumbersFromSequenceToSequence2(int sequence2[98],
		int sequence[98][98], const int k)
{
	int i = 0;
	int j = 0;
	sequence2[0] = 0;
	while (sequence2[j] != 99)
	{
		if (sequence[k][i] != 0)
		{
			sequence2[j] = sequence[k][i];
			if (sequence2[j] != 99)
			{
				j++;
				i++;
			}
		}
		if (sequence[k][i] == 0)
		{
			i++;
		}
	}
}

bool readNumbersFromFile(int sequence[98][98])
{
	bool isSequenceValid = false;
	string fileName;
	int i = 0;
	int k = 0;
	cout << "Enter the file name from Desktop: " << endl;
	cin >> fileName;
	string str;
	ifstream infile;
	infile.open(("C:\\Users\\kasia\\Desktop\\" + fileName + ".txt").c_str());
	if (infile.is_open())
	{
		getline(infile, str);
		while (infile)
		{
			stringstream ss(str);
			while (ss)
			{
				int tmp;
				ss >> tmp;
				sequence[k][i] = tmp;
				if (sequence[k][i] != 99)
				{
					i++;
				}
				if ((sequence[k][0] == 100))
				{
					break;
				}
			}
			if (sequence[k][0] == 100)
			{
				break;
			}
			k++;
			i = 0;
			getline(infile, str);
		}
		isSequenceValid = true;
	}
	else
	{
		cout << "File doesn't exist!\n";
	}
	return isSequenceValid;
}

void readManualData(int sequence[98][98], int k)
{
	cout << "Enter numbers manual:\n";
	while (sequence[k][0] != 100)
	{
		readNumbersIntoTable(sequence, k);
		if (sequence[k][0] == 100)
		{
			break;
		}
		k++;
	}
}

void definitionOfTheProgramAndSelectSource(int & select)
{
	cout
			<< "This is the program which is counting the zero crossings or extremes in sequence of numbers in the range from -10 to 10\n"
			<< "Enter numbers between -10 and 10 less than 100. End sequence of the numbers '99'.\n"
				"There is possibility enter many sequences. To end entry sequences write '100' in next line.\n"
			<< "Number of the zero crossing should be range of from 5 to 8 "
			<< endl;
	cout << "Select the data source:\n" << "file txt - write '1';\n"
			<< "manual data entry - write '2'.\n";
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

void taskChoice(int select, int sequence[98][98])
{
	int sequence2[98];
	int k = 0;
	cout
			<< "What you want to do?\nCounting zero crossing - write 1\nCounting extremes - write 2\n";
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			while (sequence[k][0] != 100)
			{
				rewritingNumbersFromSequenceToSequence2(sequence2, sequence, k);
				cout << "Line" << k << endl;
				searchingZeroCrossing(sequence2);
				k++;
			}
			break;
		}
		if (select == 2)
		{
			while (sequence[k][0] != 100)
			{
				rewritingNumbersFromSequenceToSequence2(sequence2, sequence, k);
				cout << "Line" << k << endl;
				searchingAllExtremes(sequence2);
				k++;
			}
			break;
		}
		if ((select != 1) && (select != 2))
		{
			cout << "Error: selection mistake!\n Write correct number:\n";
		}
	}
}

bool sourceChoice(int select, int sequence[98][98])
{
	bool isSequenceValid = false;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			isSequenceValid = readNumbersFromFile(sequence);
			break;
		}
		if (select == 2)
		{
			int k = 0;
			readManualData(sequence, k);
			isSequenceValid = true;
			break;
		}
		if ((select != 1) && (select != 2))
		{
			cout << "Error: selection mistake.\n Write correct number:\n";
		}
	}
	return isSequenceValid;
}

int main()
{
	bool isSequenceValid = false;
	int sequence[98][98];
	int select;
	definitionOfTheProgramAndSelectSource(select);
	isSequenceValid = sourceChoice(select, sequence);
	if (isSequenceValid)
	{
		bool isNumbersValid = true;
		isNumbersValid = validateNumbers(sequence);
		if (isNumbersValid)
		{
			taskChoice(select, sequence);
		}
	}
	return 0;
}
