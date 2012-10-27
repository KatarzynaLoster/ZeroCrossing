/*
 * Databox.cpp
 *
 *  Created on: 24-10-2012
 *      Author: kasia
 */

#include "Databox.h"

Databox::Databox() : continueReadingData(false)
{
	// TODO Auto-generated constructor stub

}

Databox::~Databox()
{
	// TODO Auto-generated destructor stub
}
bool Databox::sourceChoice(int select, int sequence[98][98])
{
	bool datatest = true;
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
			datatest = readNumbersFromFile(sequence);
			break;
		}
		if (select == 2)
		{
			datatest = readManualData();
			break;
		}
		if ((select != 1) && (select != 2))
		{
			cout << "Error: selection mistake.\n Write correct number:\n";
		}
	}
	return datatest;
}
bool Databox::readManualData()
{
	continueReadingData = true;
	bool datatest = true;
	cout << "Enter numbers manual:\n";
	while (continueReadingData)
	{
		datatest = readNumbersIntoTable();
		if (datatest == false)
			break;
	}
	return datatest;
}

string Databox::readNameAndOpenFile(ifstream & infile)
{
	string fileName;
	cout << "Enter the file name from Desktop: " << endl;
	cin >> fileName;
	infile.open(("C:\\Users\\kasia\\Desktop\\" + fileName + ".txt").c_str());
	return fileName;
}

bool Databox::readNumbersFromFile(int sequence[98][98])
{
	bool datatest = true;
	string fileName;
	int i = 0;
	int k = 0;
	string str;
	ifstream infile;
	fileName = readNameAndOpenFile(infile);
	while (!infile.is_open())
	{
		cout << "File doesn't exist!\n";
		fileName = readNameAndOpenFile(infile);
	}
	getline(infile, str);
	while (infile)
	{
		stringstream ss(str);
		while (ss)
		{
			try
			{
				ss.exceptions(istream::badbit | istream::failbit);
				ss >> sequence[k][i];
			} catch (istream::failure &)
			{
				if (ss.eof())
					break;
				ss.clear();
				cout << "Wrong data in line: " << k + 1 << " position: "
						<< i + 1 << endl;
				datatest = false;
				break;
			}

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
	return datatest;
}
bool Databox::readNumbersIntoTable()
{
	bool datatest = true;
	Sequence series;
	while (true)
	{
		int singleNumber;
		try
		{
			cin.exceptions(istream::badbit | istream::failbit);
			cin >> singleNumber;
			if (singleNumber == 99) break;
			if (singleNumber == 100)
				{
				continueReadingData = false;
				break;
				}
			series.addNumber(singleNumber);
		} catch (istream::failure &)
		{
			cin.clear();
			cout << "There is incorrect data in line: " << sequences.size() + 1
					<< ", position: " << series.countNumbers() + 1 << endl;
			datatest = false;
			break;
		}

	}
	sequences.push_back(series);
	return datatest;
}

