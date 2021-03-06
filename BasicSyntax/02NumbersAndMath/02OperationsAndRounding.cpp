
#include "pch.h"
#include <iostream>

int main()
{
	double doubleValue = 2.775;
	float floatValue = 2.111;

	std::cout << 9.0 / 2 << std::endl; //4.5 - 9.0 is considered double
	std::cout << 9 / 2 << std::endl; //4 - everything after decimal point is discarded
	std::cout << 9 % 2 << std::endl; // 1 - takes the remainder of the division

	std::cout << ceil(floatValue) << std::endl; //3
	std::cout << floor(doubleValue) << std::endl; //2

	//two ways of rounding
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);

	std::cout << doubleValue << std::endl; //2.77, not proper rounding. if value was 2.785, it would print 2.90
	std::cout << floatValue << std::endl; //2.11

	std::printf("%.2f \r\n%.2f \n", doubleValue, floatValue); //2.77, 2.11, same way of incorrect rounding

	std::cout << round(doubleValue) << std::endl; //3.00
	
	return 0;
}
