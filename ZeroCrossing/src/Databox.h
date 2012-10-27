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
public:
	vector<Sequence> sequences;
	Databox();
	bool sourceChoice(int select, int sequence[98][98]);
	bool readNumbersFromFile(int sequence[98][98]);
	bool readManualData();
	bool readNumbersIntoTable();
	string readNameAndOpenFile(ifstream & infile);


	virtual ~Databox();
};

#endif /* DATABOX_H_ */
