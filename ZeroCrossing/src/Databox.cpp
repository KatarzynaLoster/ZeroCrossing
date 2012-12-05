/*
 * Databox.cpp
 *
 *  Created on: 24-10-2012
 *      Author: kasia
 */

#include "Databox.h"

Databox::Databox() :
		continueReadingData(false)
{
	// TODO Auto-generated constructor stub

}

Databox::~Databox()
{
	// TODO Auto-generated destructor stub
}
bool Databox::validateDataSingleSequence(Sequence series)
{
	return series.validateNumbers();
}
bool Databox::validateAllData()
{
	bool isNumbersValid = true;
	vector<Sequence>::iterator it = sequences.begin();
	for (; it != sequences.end(); it++)
	{
		Sequence series = *it;
		isNumbersValid = validateDataSingleSequence(series);
		if (!isNumbersValid) break;
	}
	return isNumbersValid;
}

void Databox::zeroCrossingFunction()
{
	int i = 1;
	vector<Sequence>::iterator it = sequences.begin();
	for (; it != sequences.end(); it++)
	{
		Sequence series = *it;
		cout << "Line:" << i << endl;
		series.searchingZeroCrossing();
		i++;
	}
}
void Databox::extremesFunction()
{
	int i = 1;
	vector<Sequence>::iterator it = sequences.begin();
	for (; it != sequences.end(); it++)
	{
		Sequence series = *it;
		cout << "Line:" << i << endl;
		series.searchingAllExtremes();
		i++;
	}
}
bool Databox::sourceChoice(int select)
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
			datatest = readNumbersFromFile();
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

Sequence Databox::writeNumbersIntoSeries(bool& datatest, stringstream& ss)
{
	Sequence series;
	while (ss)
	{
		int singleNumber;
		try
		{
			ss.exceptions(istream::badbit | istream::failbit);
			ss >> singleNumber;
			if (singleNumber == 99)
				break;

			if (singleNumber == 100)
			{
				break;
			}
			series.addNumber(singleNumber);
		} catch (istream::failure&)
		{
			if (ss.eof())
				break;

			ss.clear();
			cout << "There is incorrect data in line: " << sequences.size() + 1
					<< ", position: " << series.countNumbers() + 1 << endl;
			datatest = false;
			break;
		}
	}
	return series;
}

bool Databox::readNumbersFromFile()
{
	bool datatest = true;
	Sequence series;
	string fileName;
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
		series = writeNumbersIntoSeries(datatest, ss);
		if (series.countNumbers() == 0)
		{
			break;
		}
		sequences.push_back(series);
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
			if (singleNumber == 99)
				break;
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

