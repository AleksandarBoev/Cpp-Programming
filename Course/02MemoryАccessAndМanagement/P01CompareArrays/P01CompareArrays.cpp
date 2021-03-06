#include "pch.h"
#include <iostream>
#include "CompareArrays.h"
#include <string>
#include <sstream>

/*
Write a program that reads two integer arrays from the console and compares them 
element by element. For better code reusability, you could do the comparison in 
abool compArr(int arr1[], int length1, int arr2[], int length2) function, 
which returns true if they are equal and false if not
*/

//bool compareArrays(int array1[], int length1, int array2[], int length2);

int main()
{
	int length1, length2;
	std::cin >> length1 >> length2;
	
	int* array1 = new int[length1];
	int* array2 = new int[length2];

	for (int i = 0; i < length1; i++)
		std::cin >> array1[i];

	for (int i = 0; i < length2; i++)
		std::cin >> array2[i];

	compareArrays(array1, length1, array2, length2) 
		? std::cout << "Arrays are equal" 
		: std::cout << "Arrays are NOT equal";

	delete[] array1;
	delete[] array2;

	return 0;
}





