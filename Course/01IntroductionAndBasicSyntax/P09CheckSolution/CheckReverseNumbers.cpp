#include "pch.h"
#include "CheckReverseNumbers.h"

#include "ReverseDigits.cpp"

bool checkReverseNumbers()
{
	int testNumber1 = 1234;
	int testNumber2 = 123;
	int testNumber3 = 12;
	int testNumber4 = 1;

	bool test1Successfull = 4321 == getReversedNumber(1234);
	bool test2Successfull = 321 == getReversedNumber(123);
	bool test3Successfull = 21 == getReversedNumber(12);
	bool test4Successfull = 1 == getReversedNumber(1);

	return test1Successfull && test2Successfull && test3Successfull && test4Successfull;
}