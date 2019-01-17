#include "pch.h"
#include <iostream>
#include <string>

template<typename T>
class BadArrayList
{
private:
	BadArrayList(int size, int realSize, T* data) :
		size(size),
		realSize(realSize),
		data(new T[size])
	{
		for (int i = 0; i < realSize; i++)
			this->data[i] = data[i];
	}

	T* data;
	int size, realSize;

	bool indexOutOfBounds(int index)
	{
		return index < 0 || index >= realSize;
	}
public:
	BadArrayList() :
		size(8),
		data(new T[8]),
		realSize(0)
	{
		
	}

	BadArrayList(int size) :
		size(size),
		data(new T[size]),
		realSize(0)
		//Using the param instead of the this->size, because size(size) will be executed AFTER this->data, because
		//it is after "data" in the field declaration part. Meaning that it doesn't matter in what order 
		//these are defined here, what's important is the order of declaration.
		
	{
		
	}

	~BadArrayList()
	{
		delete[] this->data;
	}

	BadArrayList(const BadArrayList& another) : //copy constructor
		data(new T[another.size]),
		size(another.size),
		realSize(another.realSize)
	{
		for (int i = 0; i < another.realSize; i++)
			this->data[i] = another.data[i];
	}

	BadArrayList& operator=(const BadArrayList& other)
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

	bool operator==(const BadArrayList& other) const
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

	BadArrayList operator+(const BadArrayList& other) const
	{
		int newSize = this->size + other.size;
		T* newData = new T[newSize];

		BadArrayList result(newSize);

		for (int i = 0; i < this->realSize; i++)
			result.addElement(this->data[i]);

		for (int i = 0; i < other.realSize; i++)
			result.addElement(other.data[i]);

		return result;
	}

	

	T* getData() const
	{
		return this->data;
	}

	T getElement(int index) const
	{
		if (this->indexOutOfBounds(index))
			return NULL;

		return this->data[index];
	}

	/*
	The normal ArrayList usually has an initial capacity of 8 (I think). And when the maximum is reached,
	that capacity is doubled and THEN a new array is created and all values are transfered.
	Creating and transfering every single time is not optimal.
	*/
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

	void setElement(int index, T newElement)
	{
		if (this->indexOutOfBounds(index))
			return;

		this->data[index] = newElement;
	}

	std::string getAllElements() const
	{
		std::string result = "";

		for (int i = 0; i < this->realSize; i++)
			result.append(std::to_string(this->data[i])).append(" | ");

		return result;
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
	
	/*
	template <>
	std::string <int> getString(T wat);
	{
		std::to_str();
	};
	*/

};

template<typename T>
void testIfEqual(BadArrayList<T> object1, BadArrayList<T> object2);

int main()
{
	/*
    TODO test the stuff if it works 
	TODO split it into .h and .cpp files. To look like i put in more work for it.
	TODO addElement(index, value). See if the resizing and copying works
	*/
	BadArrayList<int> badArrayList(5);
	badArrayList.addElement(1);
	badArrayList.addElement(2);
	badArrayList.addElement(3);
	badArrayList.addElement(4);
	badArrayList.addElement(5);
	std::cout << badArrayList.getAllElements().c_str() << std::endl;
	
	BadArrayList<int> badArrayList2(badArrayList);
	
	std::cout << "Testing the copy constructor and if the first object and second one are equal. They should be:" << std::endl;
	testIfEqual(badArrayList, badArrayList2);

	badArrayList2.setElement(0, 11);
	badArrayList2.setElement(1, 22);
	badArrayList2.setElement(2, 33);
	badArrayList2.setElement(3, 44);
	badArrayList2.setElement(4, 55);

	std::cout << "Testing if the first object and second one are equal after some changes. They should NOT be:" << std::endl;
	testIfEqual(badArrayList, badArrayList2);

	badArrayList2.addElement(66);
	badArrayList = badArrayList2;
	std::cout << "Testing if the all elements are copied via object1 = object2. Also testing addElement with resizing and copying:" << std::endl << "Result should be 11 | 22 | 33 | 44 | 55 | 66 :" << std::endl;
	std::cout <<  badArrayList.getAllElements() << std::endl;

	//test the add operator
	BadArrayList<int> badArrayList3 = badArrayList + badArrayList2;
	std::cout << "Testing the add operator. Result should be 2 identical arrays appended: " << std::endl;
	std::cout << badArrayList3.getAllElements().c_str() << std::endl;

	//test remove method
	badArrayList.removeElement(2);
	std::cout << "Testing remove method. '33' should not be there:\n";
	std::cout << badArrayList.getAllElements().c_str() << std::endl;

	//test add to index element.
	badArrayList.addElement(2, 333);
	
	std::cout << "Testing add method. '333' should be there on index 2 and all values pushed back:\n";
	std::cout << badArrayList.getAllElements().c_str() << std::endl;

	std::cout << "Testing add method again multiple times to see if resizing and copying is working properly.\n";
	badArrayList.addElement(2, 333);
	badArrayList.addElement(2, 333);
	badArrayList.addElement(2, 333);
	badArrayList.addElement(2, 333);
	badArrayList.addElement(2, 333);
	badArrayList.addElement(2, 333);
	badArrayList.addElement(2, 333);
	badArrayList.addElement(2, 333);
	badArrayList.addElement(2, 333);
	badArrayList.addElement(2, 333);
	std::cout << badArrayList.getAllElements().c_str() << std::endl;

	//Doing stuff with pointers
	//BadArrayList<int>* badArrayList2 = new BadArrayList<int>(5);
	//std::cout << badArrayList2->getAllElements().c_str() << std::endl;
	return 0;
}

template<typename T>
void testIfEqual(BadArrayList<T> object1, BadArrayList<T> object2)
{
	bool equalObjects = object1 == object2;
	equalObjects
		? std::cout << "These objects are equal" << std::endl
		: std::cout << "These objects are NOT equal" << std::endl;
}

