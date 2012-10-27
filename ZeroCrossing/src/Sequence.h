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
using namespace std;

class Sequence
{
public:
	vector<int> singleSequence;
	Sequence();
	void searchingAllExtremes(int sequence[98][98], int k);
	int countExtremesInFirstNumber(int sequence[98][98], int number_extremes, int k);
	int countExtremesInRestNumbers(int sequence[98][98], int i, int number_extremes, int k);
			void searchingZeroCrossing(int sequence2[98]);
	int countingZeroCrossing(int sequence2[98], int i, int number_zero);
	bool validateNumbers(int sequence[98][98]);

	virtual ~Sequence();
};

#endif /* SEQUENCE_H_ */
