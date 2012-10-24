/*
 * Databox.cpp
 *
 *  Created on: 24-10-2012
 *      Author: kasia
 */

#include "Databox.h"

Databox::Databox()
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
		}
		if (select == 1)
		{
			datatest = readNumbersFromFile(sequence);
			break;
		}
		if (select == 2)
		{
			int k = 0;
			datatest = readManualData(sequence, k);
			break;
		}
		if ((select != 1) && (select != 2))
		{
			cout << "Error: selection mistake.\n Write correct number:\n";
		}
	}
	return datatest;
}
bool Databox::readManualData(int sequence[98][98], int k)
{
	bool datatest = true;
	cout << "Enter numbers manual:\n";
	while (sequence[k][0] != 100)
	{
		datatest = readNumbersIntoTable(sequence, k);
		if (datatest == false)
			break;
		if (sequence[k][0] == 100)
		{
			break;
		}
		k++;
	}
	return datatest;
}
bool Databox::readNumbersFromFile(int sequence[98][98])
{
	bool datatest = true;
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
bool Databox::readNumbersIntoTable(int sequence[98][98], const int k)
{
	bool datatest = true;
	int i = 0;
	sequence[k][0] = 0;
	while (sequence[k][i] != 99)
	{
		try
		{
			cin.exceptions(istream::badbit | istream::failbit);
			cin >> sequence[k][i];
		} catch (istream::failure &)
		{
			cin.clear();
			cout << "There is incorrect data in line: " << k + 1
					<< ", position: " << i + 1 << endl;
			datatest = false;
			break;
		}
		if (sequence[k][i] == 100)
		{
			break;
		}
		if (sequence[k][i] != 99)
		{
			i++;
		}
	}
	return datatest;
}

