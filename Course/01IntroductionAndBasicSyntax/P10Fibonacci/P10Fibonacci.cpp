#include "pch.h"
#include <iostream>

/*
For this task, you are NOT allowed to use any type of loop. 
Write a function that calculates the Nth Fibonacci number.
*/

int getFibonacciRecursive(int n);

int main()
{
	int number;
	std::cin >> number;
    std::cout << "Fibonacci(" << number << ") = " << getFibonacciRecursive(number);
}

int getFibonacciRecursive(int n)
{
	//F1 = F2 = 1, F3 = 2, F4 = 3, F5 = 5, F6 = 8, F7 = 13, F8 = 21...
	if (n < 0)
		return 0;

	if (n == 1 || n == 2) //always have a bottom for a recursive function
		return 1;

	return getFibonacciRecursive(n - 1) + getFibonacciRecursive(n - 2);
}



