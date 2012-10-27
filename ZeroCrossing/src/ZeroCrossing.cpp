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
#include "Databox.h"
#include "Sequence.h"
using namespace std;





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

void taskChoice(int select, int sequence[98][98], Sequence task)
{
	int sequence2[98];
	int k = 0;
	cout
			<< "What you want to do?\nCounting zero crossing - write 1\nCounting extremes - write 2\n";
	while (true)
	{
		try
		{
			cin.exceptions(istream::badbit | istream::failbit);
			cin >> select;
		} catch (istream::failure &)
		{
			cin.clear();
			string wrongSelection;
			cin >> wrongSelection;
			cout << "Wrong selection! Write correct number: \n" << endl;
			continue;
		}

		if (select == 1)
		{
			while (sequence[k][0] != 100)
			{
				rewritingNumbersFromSequenceToSequence2(sequence2, sequence, k);
				cout << "Line " << k + 1 << endl;
				task.searchingZeroCrossing(sequence2);
				k++;
			}
			break;
		}
		if (select == 2)
		{
			while (sequence[k][0] != 100)
			{
				cout << "Line " << k + 1 << endl;
				task.searchingAllExtremes(sequence, k);
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



int main()
{
	Databox container;
	Sequence task;
	int sequence[98][98];
	int select;
	definitionOfTheProgramAndSelectSource(select);
	bool datatest = container.sourceChoice(select, sequence);
	if (datatest)
	{
		bool isNumbersValid = true;
		isNumbersValid = task.validateNumbers(sequence);
		if (isNumbersValid)
		{
			taskChoice(select, sequence, task);
		}
	}
	return 0;
}
