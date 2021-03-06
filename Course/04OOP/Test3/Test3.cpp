#include "pch.h"
#include <iostream>
#include "MyArray.h"

void printArray(MyArray myArray);

int main()
{
	//If this was a pointer then the destructor would be called when deleting the pointer.
	MyArray myArray(5); //creating it on the stack memory. Destructor will be called when it is out of scope
	for (int i = 0; i < myArray.getSize(); i++)
	{
		std::cout << myArray.getElement(i) << std::endl; //initial values are random numbers
		myArray.setValue(i, i + 1);
	}

	MyArray myArray2(myArray);
	myArray.setValue(0, 9999);
	std::cout << "Array 2 values: " << std::endl; //the last change to "myArray" has no effect on myArray2
	printArray(myArray2);

	MyArray myArray3(3);
	myArray3.setValue(0, 11);
	myArray3.setValue(1, 99);
	myArray3.setValue(2, 123);

	myArray2 = myArray3;
	myArray3.setValue(0, 9999);

	std::cout << "Array 2 again: " << std::endl; //the last change to myArray3 has no effect on myArray2
	printArray(myArray2);

	return 0;
}

void printArray(MyArray myArray)
{
	for (int i = 0; i < myArray.getSize(); i++)
	{
		std::cout << myArray.getElement(i) << std::endl;
	}
}

