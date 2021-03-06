/*
 * Databox.h
 *
 *  Created on: 24-10-2012
 *      Author: kasia
 */

#ifndef DATABOX_H_
#define DATABOX_H_
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include  "Sequence.h"
using namespace std;

class Databox
{
	bool continueReadingData;

	bool writingNumberIntoSeries(bool datatest, stringstream& ss);
	Sequence writeNumbersIntoSeries(bool& datatest, stringstream& ss);

public:
	vector<Sequence> sequences;
	Databox();
	bool sourceChoice(int select);
	bool readNumbersFromFile();
	bool readManualData();
	bool readNumbersIntoTable();
	bool validateDataSingleSequence(Sequence series);
	void zeroCrossingFunction();
	void extremesFunction();
	string readNameAndOpenFile(ifstream & infile);
	bool validateAllData();


	virtual ~Databox();
};

#endif /* DATABOX_H_ */
