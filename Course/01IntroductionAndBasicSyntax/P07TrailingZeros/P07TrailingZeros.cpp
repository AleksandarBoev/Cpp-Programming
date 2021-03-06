#include "pch.h"
#include <iostream>
#include "BigInteger.h"
#include <string>

/*
Write a program that calculates for given N how many trailing
zeros present at the end of the number N!. 
Examples N = 10, N! = 3628800, answer 2; N! = 2432902008176640000, answer: 4.
Make sure your program works for N up to 50 000
*/

/*
Finds the factorial of n. n!
*/
//long long unsigned int factorial(int n); 

BigInteger factorial(int n); 
//for some reason long int passes to, but long int and just int are equal
//and since they are equal, that means there are two functions with the same signature
//yet the IDE does not see a problem

short unsigned int getNumberOfTrailingZeros(long long unsigned int number);
short unsigned int getNumberOfTrailingZeros(BigInteger number);

int main()
{
	std::cout << "Enter a number: ";
	int n;
	std::cin >> n;

	BigInteger factorialResult = factorial(n);
	std::cout << n << "! = " << factorialResult << std::endl;

	std::cout << "Number of trailing zeros: " << getNumberOfTrailingZeros(factorialResult);

	return 0;
}

/*
long long unsigned int factorial(int n)
{
	if (n < 0)
		return 0;

	if (n == 0 || n == 1)
		return 1;

	long long unsigned int result = 1;
	for (int i = n; i > 1; i--)
		result *= i;

	return result;
}
*/

short unsigned int getNumberOfTrailingZeros(long long unsigned int number)
{
	short unsigned int count = 0;

	while (number % 10 == 0)
	{
		count++;
		number /= 10;
	}
	return count;
}

BigInteger factorial(int n)
{
	if (n < 0)
		return BigInteger("0");

	BigInteger result("1");

	if (n == 0 || n == 1)
		return result;

	for (int i = n; i > 1; i--)
		result = result.multiplyInteger(i);
	
	return result;
}

short unsigned int getNumberOfTrailingZeros(BigInteger number)
{
	std::string numberString = number.toString();
	short unsigned int zeroCounter = 0;

	for (int i = numberString.length() - 1; i >= 0; i--)
	{
		if (numberString[i] == '0')
			zeroCounter++;
		else
			break;
	}

	return zeroCounter;
}




