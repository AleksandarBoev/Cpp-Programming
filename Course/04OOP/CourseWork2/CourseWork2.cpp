#include "pch.h"
#include <iostream>
#include "MyArrayList.h"
#include <vector>
#include <string>

template<typename T>
void testIfEqual(MyArrayList<T> object1, MyArrayList<T> object2);

int main()
{
	MyArrayList<int> myArrayList(5);
	myArrayList.addElement(1);
	myArrayList.addElement(2);
	myArrayList.addElement(3);
	myArrayList.addElement(4);
	myArrayList.addElement(5);
	std::cout << myArrayList.toString().c_str() << std::endl;

	MyArrayList<int> myArrayList2(myArrayList);

	std::cout << "Testing the copy constructor and if the first object and second one are equal. They should be:" << std::endl;
	testIfEqual(myArrayList, myArrayList2);

	myArrayList2.setElement(0, 11);
	myArrayList2.setElement(1, 22);
	myArrayList2.setElement(2, 33);
	myArrayList2.setElement(3, 44);
	myArrayList2.setElement(4, 55);

	std::cout << "Testing if the first object and second one are equal after some changes. They should NOT be:" << std::endl;
	testIfEqual(myArrayList, myArrayList2);

	myArrayList2.addElement(66);
	myArrayList = myArrayList2;
	std::cout << "Testing if the all elements are copied via object1 = object2. Also testing addElement with resizing and copying:" << std::endl << "Result should be 11 | 22 | 33 | 44 | 55 | 66 :" << std::endl;
	std::cout << myArrayList.toString() << std::endl;

	//test the add operator
	MyArrayList<int> myArrayList3 = myArrayList + myArrayList2;
	std::cout << "Testing the add operator. Result should be 2 identical arrays appended: " << std::endl;
	std::cout << myArrayList3.toString().c_str() << std::endl;

	//test remove method
	myArrayList.removeElement(2);
	std::cout << "Testing remove method. '33' should not be there:\n";
	std::cout << myArrayList.toString().c_str() << std::endl;

	//test add to index element.
	myArrayList.addElement(2, 333);

	std::cout << "Testing add method. '333' should be there on index 2 and all values pushed back:\n";
	std::cout << myArrayList.toString().c_str() << std::endl;

	std::cout << "Testing add method again multiple times to see if resizing and copying is working properly.\n";
	myArrayList.addElement(2, 333);
	myArrayList.addElement(2, 333);
	myArrayList.addElement(2, 333);
	myArrayList.addElement(2, 333);
	myArrayList.addElement(2, 333);
	myArrayList.addElement(2, 333);
	myArrayList.addElement(2, 333);
	myArrayList.addElement(2, 333);
	myArrayList.addElement(2, 333);
	myArrayList.addElement(2, 333);
	std::cout << myArrayList.toString().c_str() << std::endl;
	/*
	//test adding a vector
	std::vector<int> intVector;
	intVector.push_back(0);
	intVector.push_back(1);
	intVector.push_back(2);

	
	myArrayList = myArrayList + intVector;
	std::cout << "Testing adding a vector to an object. Expected result is the above array with '0', '1' and '2' added\n";
	std::cout << myArrayList.toString() << std::endl;
	*/
	//test the [] operator
	std::cout << "Testing getting the first two and last two members from the above array with just '[]'" << std::endl;
	std::cout << myArrayList[0] << " | " << myArrayList[1] << " | "
		<< myArrayList[myArrayList.getSize() - 2] << " | "
		<< myArrayList[myArrayList.getSize() - 1] << " | " << std::endl;

	return 0;
}

template<typename T>
void testIfEqual(MyArrayList<T> object1, MyArrayList<T> object2)
{
	bool equalObjects = object1 == object2;
	equalObjects
		? std::cout << "These objects are equal" << std::endl
		: std::cout << "These objects are NOT equal" << std::endl;
}

