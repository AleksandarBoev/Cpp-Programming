#include "pch.h"
#include <iostream>

/*
Write a program that prints all the numbers from 1 to N
*/

int main()
{
	int n; 
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cout << i << std::endl;

	return 0;
}


