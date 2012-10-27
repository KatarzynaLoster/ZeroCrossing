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

bool Sequence::validateNumbers(int sequence[98][98])
{
	bool isNumbersValid = true;
	int i = 0;
	int k = 0;
	while (sequence[k][i] != 100)
	{
		while (sequence[k][i] != 99)
		{
			if ((sequence[k][i] > -10) && (sequence[k][i] < 10))
			{
				i++;
			}
			else
			{
				cout << "There is error in number of the sequence!\n ";
				isNumbersValid = false;
				break;
			}
		}
		if (sequence[k][0] == 100)
		{
			break;
		}
		k++;
		i = 0;
	}
	return isNumbersValid;
}

int Sequence::countingZeroCrossing(int sequence2[98], int i, int number_zero)
{
	if ((sequence2[i] > 0) && (sequence2[i + 1] < 0))
	{
		number_zero++;
	}
	if ((sequence2[i] < 0) && (sequence2[i + 1] > 0))
	{
		number_zero++;
	}
	return number_zero;
}

void Sequence::searchingZeroCrossing(int sequence2[98])
{
	int i = 0;
	int number_zero = 0;
	while (sequence2[i + 1] != 99)
	{

		number_zero = countingZeroCrossing(sequence2, i, number_zero);
		if ((sequence2[i + 2] == 99) || (sequence2[i + 1] == 99)
				|| (sequence2[i] == 99))
		{
			cout << "number of the zero crossing is: " << number_zero << endl;
			if ((number_zero < 5) || (number_zero > 8))
			{
				cout << "Error: Number of the zero crossing is incorrect!"
						<< endl;
			}
			break;
		}
		i++;
	}
}

int Sequence::countExtremesInRestNumbers(int sequence[98][98], int i, int number_extremes,
		int k)
{
	if ((sequence[k][i] > 0) && (sequence[k][i + 1] < sequence[k][i])
			&& (sequence[k][i] > sequence[k][i - 1])
			&& (sequence[k][i + 1] != 99))
	{
		number_extremes++;
	}
	if ((sequence[k][i] < 0) && (sequence[k][i + 1] > sequence[k][i])
			&& (sequence[k][i] < sequence[k][i - 1])
			&& (sequence[k][i + 1] != 99))
	{
		number_extremes++;
	}
	if ((sequence[k][i] > 0) && (sequence[k][i - 1] < sequence[k][i])
			&& (sequence[k][i + 1] == 99))
	{
		number_extremes++;
	}
	if ((sequence[k][i] < 0) && (sequence[k][i - 1] > sequence[k][i])
			&& (sequence[k][i + 1] == 99))
	{
		number_extremes++;
	}
	return number_extremes;
}

int Sequence::countExtremesInFirstNumber(int sequence[98][98], int number_extremes, int k)
{
	if (sequence[k][0] != 99)
	{
		if ((sequence[k][0] > 0) && (sequence[k][0] > sequence[k][1]))
		{
			number_extremes++;
		}
		if ((sequence[k][0] < 0) && (sequence[k][0] < sequence[k][1]))
		{
			number_extremes++;
		}
	}
	else
	{
		number_extremes = 0;
	}
	return number_extremes;
}

void Sequence::searchingAllExtremes(int sequence[98][98], int k)
{
	int i = 1;
	int number_extremes = 0;
	number_extremes = countExtremesInFirstNumber(sequence, number_extremes, k);
	while ((sequence[k][0] != 99) && (sequence[k][i] != 99))
	{
		number_extremes = countExtremesInRestNumbers(sequence, i,
				number_extremes, k);
		if ((sequence[k][i - 1] == 99) || (sequence[k][i + 1] == 99)
				|| (sequence[k][i] == 99)/* || (sequence[k][i + 2] == 99)*/)
		{
			cout << "number of the extremes is: " << number_extremes << endl;
			break;
		}
		i++;
	}
}
