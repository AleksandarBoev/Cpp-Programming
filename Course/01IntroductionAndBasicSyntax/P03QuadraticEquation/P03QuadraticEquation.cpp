

#include "pch.h"
#include <iostream>
#include <math.h>

/*
Write a program that enters the coefficients a, b and c of a 
quadratic equation a*x2 + b*x + c = 0 and calculates and prints its real roots. 
Note that quadratic equations may have 0, 1 or 2 real roots.

Steps to solving the equation:
1) Find the disctiminant. Formula: D = square root(b*2 − 4*a*c)
If result is positive => 2 roots. If it is 0 => 1 root. If negative => no real roots.
2) x1 =  (−b + D) / 2*a, x2 = (-b - D) / 2*a
*/

int main()
{
	double a, b, c;

	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	std::cout << "c = ";
	std::cin >> c;

	double discriminant = b * b - 4 * a * c;

	if (discriminant < 0)
	{
		std::cout << "Discriminant is negative. No real roots, only complex ones.";
		return 0;
	}

	double x1 = (-1 * b + sqrt(discriminant)) / (2 * a);

	if (discriminant < 0.00001)
	{
		std::cout << "Discriminant is zero. Only one real root: " << x1;
		return 0;
	}

	double x2 = (-1 * b - sqrt(discriminant)) / (2 * a);

	std::printf("Discriminant is a positive number. Two roots: \r\nx1 = %f, x2 = %f", x1, x2);

	return 0;
}

