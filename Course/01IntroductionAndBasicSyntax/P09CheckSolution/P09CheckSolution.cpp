#include "pch.h"
#include <iostream>

#include "CheckReverseNumbers.h"

/*
Write a bool function that tests the function from task 8 with different values.
It should call the function from 8 for a value and check the result against the
expected answer. Make the function check at least 10 numbers of different length
and return true if all were correct or false if any of them was wrong. 
Call that this checking function from main() and print it’s result
*/


int main()
{
	checkReverseNumbers() ? std::cout << "Function works fine." : std::cout << "Function does NOT work!";

	return 0;
}



