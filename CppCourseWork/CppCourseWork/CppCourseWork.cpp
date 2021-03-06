#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

template<typename T>
class MyArrayList
{
private:
	T* data;
	int size, realSize;

	MyArrayList(int size, int realSize, T* data) :
		size(size),
		realSize(realSize),
		data(new T[size])
	{
		for (int i = 0; i < realSize; i++)
			this->data[i] = data[i];
	}


	bool indexOutOfBounds(int index)
	{
		return index < 0 || index >= realSize;
	}
public:
	MyArrayList() :
		size(8),
		data(new T[8]),
		realSize(0)
	{

	}

	MyArrayList(int size) :
		size(size),
		data(new T[size]),
		realSize(0)
		//Using the param instead of the this->size, because size(size) will be executed AFTER this->data, because
		//it is after "data" in the field declaration part. Meaning that it doesn't matter in what order 
		//these are defined here, what's important is the order of declaration.
	{
	}

	~MyArrayList() //destructor, rule of 3
	{
		delete[] this->data;
	}

	MyArrayList(const MyArrayList& another) : //copy constructor, rule of 3
		data(new T[another.size]),
		size(another.size),
		realSize(another.realSize)
	{
		for (int i = 0; i < another.realSize; i++)
			this->data[i] = another.data[i];
	}

	MyArrayList& operator=(const MyArrayList& other) //copy assignment operator, rule of 3
	{
		if (this != &other) { //if they are different by address
			delete[] this->data;

			this->size = other.size;
			this->realSize = other.realSize;
			this->data = new T[other.size];

			for (int i = 0; i < this->realSize; i++)
				this->data[i] = other.data[i];
		}

		return *this;
	}

	bool operator==(const MyArrayList& other) const
	{
		if (this->realSize != other.realSize)
			return false;

		for (int i = 0; i < this->realSize; i++)
		{
			if (this->data[i] != other.data[i])
				return false;
		}

		return true;
	}

	MyArrayList operator+(const MyArrayList& other) const
	{
		int newSize = this->size + other.size;

		MyArrayList result(newSize);

		for (int i = 0; i < this->realSize; i++)
			result.addElement(this->data[i]);

		for (int i = 0; i < other.realSize; i++)
			result.addElement(other.data[i]);

		return result;
	}

	MyArrayList operator+(std::vector<T> other) const
	{
		int newSize = this->size + other.size();

		MyArrayList result(newSize);

		for (int i = 0; i < this->realSize; i++)
			result.addElement(this->data[i]);

		for (int i = 0; i < other.size(); i++)
			result.addElement(other[i]);

		return result;
	}

	T operator[](int index) const
	{
		if (this->realSize == 0 || index >= this->realSize)
			return NULL;

		return this->data[index];
	}


	T* getData() const
	{
		return this->data;
	}

	int getSize() const
	{
		return this->realSize;
	}

	T getElement(int index) const
	{
		if (this->indexOutOfBounds(index))
			return NULL;

		return this->data[index];
	}

	void addElement(T element)
	{
		this->realSize++;

		if (this->realSize > size)
		{
			this->size *= 2;
			T* newData = new T[this->size];

			for (int i = 0; i < this->realSize - 1; i++)
				newData[i] = this->data[i];

			delete[] this->data;
			this->data = newData;
		}
		this->data[this->realSize - 1] = element;
	}

	void addElement(int index, T value)
	{
		if (this->indexOutOfBounds(index))
			return;

		this->realSize++;
		if (this->realSize > size)
		{
			this->size *= 2;
			T* newData = new T[this->size];

			for (int i = 0; i < this->realSize - 1; i++)
				newData[i] = this->data[i];

			delete[] this->data;
			this->data = newData;
		}

		for (int i = realSize - 1; i > index; i--)
			this->data[i] = this->data[i - 1];

		this->data[index] = value;
	}

	void setElement(int index, T newElement)
	{
		if (this->indexOutOfBounds(index))
			return;

		this->data[index] = newElement;
	}

	void removeElement(int index)
	{
		if (this->indexOutOfBounds(index))
			return;

		for (int i = index; i < this->realSize - 1; i++)
			this->data[i] = this->data[i + 1];

		this->data[realSize - 1] = 0;
		this->realSize--;
	}

	std::string toString() const
	{
		std::string result = "";

		for (int i = 0; i < this->realSize; i++)
			result.append(std::to_string(this->data[i])).append(" | ");

		return result;
	}
};

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

	//test adding a vector
	std::vector<int> intVector;
	intVector.push_back(0);
	intVector.push_back(1);
	intVector.push_back(2);

	myArrayList = myArrayList + intVector;
	std::cout << "Testing adding a vector to an object. Expected result is the above array with '0', '1' and '2' added\n";
	std::cout << myArrayList.toString() << std::endl;

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

