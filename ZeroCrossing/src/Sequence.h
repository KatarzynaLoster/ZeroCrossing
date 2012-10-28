/*
 * Sequence.h
 *
 *  Created on: 27-10-2012
 *      Author: kasia
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Sequence
{
public:
	vector<int> singleSequence;
	Sequence();
	void addNumber (int number);
	int countNumbers ();
	void searchingAllExtremes();
	int countExtremesInFirstNumber(int number_extremes);
	int countExtremesInRestNumbers(int number_extremes, vector<int>::iterator it);
	void searchingZeroCrossing();
	int countingZeroCrossing(int number_zero, vector<int>::iterator it);
	void removingZero();
	bool validateNumbers();

	virtual ~Sequence();

private:
	void removingZero(vector<int>::iterator& it);
};

#endif /* SEQUENCE_H_ */
