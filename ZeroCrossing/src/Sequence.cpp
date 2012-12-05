/*
 * Sequence.cpp
 *
 *  Created on: 27-10-2012
 *      Author: kasia
 */

#include "Sequence.h"

Sequence::Sequence()
{
	// TODO Auto-generated constructor stub

}

Sequence::~Sequence()
{
	// TODO Auto-generated destructor stub
}
void Sequence::addNumber(int &number)
{
	singleSequence.push_back(number);
}
int Sequence::countNumbers()
{
	return singleSequence.size();
}

bool Sequence::validateNumbers()
{
	bool isNumbersValid = true;

	vector<int>::iterator it = singleSequence.begin();

	for (; it != singleSequence.end(); it++)
	{
		if ((*it > -10) && (*it < 10))
		{
		}
		else
		{
			cout << "There is error in number of the sequence!\n ";
			isNumbersValid = false;
			break;
		}
	}
	return isNumbersValid;
}

int Sequence::countingZeroCrossing(int number_zero, vector<int>::iterator it)
{
	if ((it +1) != singleSequence.end())
	{
		if ((*it > 0) && (*(it + 1) < 0))
		{
			number_zero++;
		}
		if ((*it < 0) && (*(it + 1) > 0))
		{
			number_zero++;
		}
	}
	return number_zero;
}

void Sequence::removingZero()
{

	singleSequence.erase(
			remove(singleSequence.begin(), singleSequence.end(), 0),
			singleSequence.end());
}

void Sequence::searchingZeroCrossing()
{
	removingZero();
	int number_zero = 0;
	vector<int>::iterator it = singleSequence.begin();
	for (; it != singleSequence.end(); it++)
	{
		number_zero = countingZeroCrossing(number_zero, it);
	}
	cout << "Number of the zero crossing is: " << number_zero << endl;
}

int Sequence::countExtremesInRestNumbers(int number_extremes,
		vector<int>::iterator & it)
{
	bool itBiggerThan0 = ( (*it) > 0);
	bool itBiggerThanNextElement = (*(it + 1) < *it) ;
	bool itBiggerThanPreviousElement = (*it > *(it - 1));
	bool isLastElement = ((it + 1) != singleSequence.end());


	if (itBiggerThan0 && itBiggerThanNextElement && itBiggerThanPreviousElement	&& isLastElement )
	{
		number_extremes++;
	}
	if ((*it < 0) && (*(it + 1) > *it) && (*it < *(it - 1))
			&& ((it + 1) != singleSequence.end()))
	{
		number_extremes++;
	}
	if ((*it > 0) && (*(it - 1) < *it) && ((it + 1) == singleSequence.end()))
	{
		number_extremes++;
	}
	if ((*it < 0) && (*(it - 1) > *it) && ((it + 1) == singleSequence.end()))
	{
		number_extremes++;
	}
	return number_extremes;
}

int Sequence::countExtremesInFirstNumber(int number_extremes)
{
	vector<int>::iterator it = singleSequence.begin();
	if ((it != singleSequence.end()) && ((it +1) != singleSequence.end()))
	{
		if ((*it > 0) && (*it > *(it + 1)))
		{
			number_extremes++;
		}
		else if ((*it < 0) && (*it < *(it + 1)))
		{
			number_extremes++;
		}
		else
		{
			number_extremes = 0;
		}
	}
	return number_extremes;
}

void Sequence::searchingAllExtremes()
{
	int number_extremes = 0;
	number_extremes = countExtremesInFirstNumber(number_extremes);
	vector<int>::iterator it = singleSequence.begin() + 1;
	for (; it != singleSequence.end(); it++)
	{
		number_extremes = countExtremesInRestNumbers(number_extremes, it);
	}
	cout << "number of the extremes is: " << number_extremes << endl;
}
