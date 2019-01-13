#include "pch.h"
#include "MyArray.h"


MyArray::MyArray() :
	data(new int[0])
{
	
}

MyArray::MyArray(int size):
	size(size),
	data(new int[size])
{
	
}


MyArray::~MyArray()
{
	delete[] data;
}

MyArray::MyArray(const MyArray& another) : //copy constructor
	data(new int[another.size]),
	size(another.size)
{
	for (int i = 0; i < another.size; i++)
	{
		this->data[i] = another.data[i];
	}
}

MyArray& MyArray::operator=(const MyArray& other)
{
	if (this != &other) { //if they are different by address
		delete[] this->data;

		this->size = other.size;
		this->data = new int[other.size];

		for (int i = 0; i < this->size; i++)
			this->data[i] = other.data[i];
	}

	return *this;
}

int MyArray::getSize() const
{
	return this->size;
}

int MyArray::getElement(int index) const
{
	return this->data[index];
}

void MyArray::setValue(int index, int value)
{
	this->data[index] = value;
}


