#include "pch.h"
#include "ReverseDigits.h"

int getReversedNumber(int number)
{
	int result = 0;
	int counter = 0;
	while (number > 0)
	{
		result *= 10;
		result += number % 10;
		number /= 10;
	}

	return result;
}
