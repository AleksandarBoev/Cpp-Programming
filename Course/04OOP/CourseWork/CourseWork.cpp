#include "pch.h"
#include <iostream>
#include <string>
#include "MyArrayList.h"

template<typename T>
void testIfEqual(MyArrayList<T> object1, MyArrayList<T> object2);

int main()
{
	/*
	TODO test the stuff if it works
	TODO split it into .h and .cpp files. To look like i put in more work for it.
	TODO addElement(index, value). See if the resizing and copying works
	*/
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

	//Doing stuff with pointers
	//BadArrayList<int>* badArrayList2 = new BadArrayList<int>(5);
	//std::cout << badArrayList2->getAllElements().c_str() << std::endl;
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

