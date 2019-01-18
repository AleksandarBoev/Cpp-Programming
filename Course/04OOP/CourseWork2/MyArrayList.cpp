#include "pch.h"
#include "MyArrayList.h"
#include <string>
#include <vector>

template<typename T>
MyArrayList<T>::MyArrayList(int size, int realSize, T* data) :
	size(size),
	realSize(realSize),
	data(new T[size])
{
	for (int i = 0; i < realSize; i++)
		this->data[i] = data[i];
}

template<typename T>
bool MyArrayList<T>::indexOutOfBounds(int index)
{
	return index < 0 || index >= realSize;
}

template<typename T>
MyArrayList<T>::MyArrayList() :
	size(8),
	data(new T[8]),
	realSize(0)
{

}

template<typename T>
MyArrayList<T>::MyArrayList(int size) :
	size(size),
	data(new T[size]),
	realSize(0)
	//Using the param instead of the this->size, because size(size) will be executed AFTER this->data, because
	//it is after "data" in the field declaration part. Meaning that it doesn't matter in what order 
	//these are defined here, what's important is the order of declaration.
{
}

template<typename T>
MyArrayList<T>::~MyArrayList() //destructor, rule of 3
{
	delete[] this->data;
}

template<typename T>
MyArrayList<T>::MyArrayList(const MyArrayList& another) : //copy constructor, rule of 3
	data(new T[another.size]),
	size(another.size),
	realSize(another.realSize)
{
	for (int i = 0; i < another.realSize; i++)
		this->data[i] = another.data[i];
}

template<typename T>
MyArrayList<T>& MyArrayList<T>::operator=(const MyArrayList<T>& other) //copy assignment operator, rule of 3
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

template<typename T>
bool MyArrayList<T>::operator==(const MyArrayList& other) const
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

template<typename T>
MyArrayList<T> MyArrayList<T>::operator+(const MyArrayList& other) const
{
	int newSize = this->size + other.size;

	MyArrayList result(newSize);

	for (int i = 0; i < this->realSize; i++)
		result.addElement(this->data[i]);

	for (int i = 0; i < other.realSize; i++)
		result.addElement(other.data[i]);

	return result;
}

/*
template<typename T>
MyArrayList<T> MyArrayList<T>::operator+(std::vector<T> other) const
{
	int newSize = this->size + other.size();

	MyArrayList result(newSize);

	for (int i = 0; i < this->realSize; i++)
		result.addElement(this->data[i]);

	for (int i = 0; i < other.size(); i++)
		result.addElement(other[i]);

	return result;
}
*/

template<typename T>
T MyArrayList<T>::operator[](int index) const
{
	if (this->realSize == 0 || index >= this->realSize)
		return NULL;

	return this->data[index];
}


template<typename T>
T* MyArrayList<T>::getData() const
{
	return this->data;
}

template<typename T>
int MyArrayList<T>::getSize() const
{
	return this->realSize;
}

template<typename T>
T MyArrayList<T>::getElement(int index) const
{
	if (this->indexOutOfBounds(index))
		return NULL;

	return this->data[index];
}

template<typename T>
void MyArrayList<T>::addElement(T element)
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

template<typename T>
void MyArrayList<T>::addElement(int index, T value)
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

template<typename T>
void MyArrayList<T>::setElement(int index, T newElement)
{
	if (this->indexOutOfBounds(index))
		return;

	this->data[index] = newElement;
}

template<typename T>
void MyArrayList<T>::removeElement(int index)
{
	if (this->indexOutOfBounds(index))
		return;

	for (int i = index; i < this->realSize - 1; i++)
		this->data[i] = this->data[i + 1];

	this->data[realSize - 1] = 0;
	this->realSize--;
}

template<typename T>
std::string MyArrayList<T>::toString() const
{
	std::string result = "";

	for (int i = 0; i < this->realSize; i++)
		result.append(std::to_string(this->data[i])).append(" | ");

	return result;
}

