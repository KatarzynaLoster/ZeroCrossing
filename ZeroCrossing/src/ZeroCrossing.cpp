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

void readNumbersFromFile(int sequence[98][98])
{
	string fileName;
	int i = 0;
	int k = 0;
	string str;
	ifstream infile;
	cout << "Enter the file name from Desktop: " << endl;
	cin >> fileName;
	infile.open(("C:\\Users\\kasia\\Desktop\\" + fileName + ".txt").c_str());
	while (!infile.is_open())
	{
		cout << "File doesn't exist!\n";
		cout << "Enter the file name from Desktop: " << endl;
		cin >> fileName;
		infile.open(
				("C:\\Users\\kasia\\Desktop\\" + fileName + ".txt").c_str());
	}
	getline(infile, str);
	while (infile)
	{
		stringstream ss(str);
		while (ss)
		{
			ss >> sequence[k][i];
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

int countExtremesInRestNumbers(int sequence[98][98], int i, int number_extremes,
		int k)
{
	if ((sequence[k][i] > 0) && (sequence[k][i + 1] < sequence[k][i])
			&& (sequence[k][i] > sequence[k][i - 1])
			&& (sequence[k][i + 1] != 99))
	{
		number_extremes++;
	}
	if ((sequence[k][i] < 0) && (sequence[k][i + 1] > sequence[k][i])
			&& (sequence[k][i] < sequence[k][i - 1])
			&& (sequence[k][i + 1] != 99))
	{
		number_extremes++;
	}
	if ((sequence[k][i] > 0) && (sequence[k][i - 1] < sequence[k][i])
			&& (sequence[k][i + 1] == 99))
	{
		number_extremes++;
	}
	if ((sequence[k][i] < 0) && (sequence[k][i - 1] > sequence[k][i])
			&& (sequence[k][i + 1] == 99))
	{
		number_extremes++;
	}
	return number_extremes;
}

int countExtremesInFirstNumber(int sequence[98][98], int number_extremes, int k)
{
	if (sequence[k][0] != 99)
	{
		if ((sequence[k][0] > 0) && (sequence[k][0] > sequence[k][1]))
		{
			number_extremes++;
		}
		if ((sequence[k][0] < 0) && (sequence[k][0] < sequence[k][1]))
		{
			number_extremes++;
		}
	}
	else
	{
		number_extremes = 0;
	}
	return number_extremes;
}

void searchingAllExtremes(int sequence[98][98], int k)
{
	int i = 1;
	int number_extremes = 0;
	number_extremes = countExtremesInFirstNumber(sequence, number_extremes, k);
	while ((sequence[k][0] != 99)
			&& (sequence[k][i] != 99))
	{
		number_extremes = countExtremesInRestNumbers(sequence, i,
				number_extremes, k);
		if ((sequence[k][i - 1] == 99) || (sequence[k][i + 1] == 99)
				|| (sequence[k][i] == 99)/* || (sequence[k][i + 2] == 99)*/)
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
				cout << "Line " << k << endl;
				searchingZeroCrossing(sequence2);
				k++;
			}
			break;
		}
		if (select == 2)
		{
			while (sequence[k][0] != 100)
			{
				cout << "Line " << k << endl;
				searchingAllExtremes(sequence, k);
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

void sourceChoice(int select, int sequence[98][98])
{
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			readNumbersFromFile(sequence);
			break;
		}
		if (select == 2)
		{
			int k = 0;
			readManualData(sequence, k);
			break;
		}
		if ((select != 1) && (select != 2))
		{
			cout << "Error: selection mistake.\n Write correct number:\n";
		}
	}
}

int main()
{
	int sequence[98][98];
	int select;
	definitionOfTheProgramAndSelectSource(select);
	sourceChoice(select, sequence);
	bool isNumbersValid = true;
	isNumbersValid = validateNumbers(sequence);
	if (isNumbersValid)
	{
		taskChoice(select, sequence);
	}
	return 0;
}
