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
using namespace std;

class Databox
{
public:
	vector<int> sequence;
	Databox();
	bool sourceChoice(int select, int sequence[98][98]);
	bool readNumbersFromFile(int sequence[98][98]);
	bool readManualData(int sequence[98][98], int k);
	bool readNumbersIntoTable(int sequence[98][98], const int k);


	virtual ~Databox();
};

#endif /* DATABOX_H_ */
