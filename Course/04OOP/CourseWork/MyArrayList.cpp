#include "pch.h"
#include "MyArrayList.h"

	template<class T>
	MyArrayList<T>::MyArrayList(int size, int realSize, T* data) :
		size(size),
		realSize(realSize),
		data(new T[size])
	{
		for (int i = 0; i < realSize; i++)
			this->data[i] = data[i];
	}


	template<class T>
	bool MyArrayList<T>::indexOutOfBounds(int index)
	{
		return index < 0 || index >= realSize;
	}

	template<class T>
	MyArrayList<T>::MyArrayList() :
		size(8),
		data(new T[8]),
		realSize(0)
	{

	}

	template<class T>
	MyArrayList<T>::MyArrayList(int size) :
		size(size),
		data(new T[size]),
		realSize(0)
		//Using the param instead of the this->size, because size(size) will be executed AFTER this->data, because
		//it is after "data" in the field declaration part. Meaning that it doesn't matter in what order 
		//these are defined here, what's important is the order of declaration.

	{

	}

	template<class T>
	MyArrayList<T>::~MyArrayList()
	{
		delete[] this->data;
	}

	template<class T>
	MyArrayList<T>::MyArrayList(const MyArrayList& another) : //copy constructor
		data(new T[another.size]),
		size(another.size),
		realSize(another.realSize)
	{
		for (int i = 0; i < another.realSize; i++)
			this->data[i] = another.data[i];
	}

	template<class T>
	MyArrayList<T>& MyArrayList<T>::operator=(const MyArrayList& other)
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

	template<class T>
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

	template<class T>
	MyArrayList<T> MyArrayList<T>::operator+(const MyArrayList& other) const
	{
		int newSize = this->size + other.size;
		T* newData = new T[newSize];

		MyArrayList result(newSize);

		for (int i = 0; i < this->realSize; i++)
			result.addElement(this->data[i]);

		for (int i = 0; i < other.realSize; i++)
			result.addElement(other.data[i]);

		return result;
	}


	template<class T>
	T* MyArrayList<T>::getData() const
	{
		return this->data;
	}

	template<class T>
	T MyArrayList<T>::getElement(int index) const
	{
		if (this->indexOutOfBounds(index))
			return NULL;

		return this->data[index];
	}

	template<class T>
	void MyArrayList<T>::addElement (T element)
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

	template<class T>
	void MyArrayList<T>::setElement(int index, T newElement)
	{
		if (this->indexOutOfBounds(index))
			return;

		this->data[index] = newElement;
	}

	template<class T>
	std::string MyArrayList<T>::toString() const
	{
		std::string result = "";

		for (int i = 0; i < this->realSize; i++)
			result.append(std::to_string(this->data[i])).append(" | ");

		return result;
	}

	template<class T>
	void MyArrayList<T>::removeElement(int index)
	{
		if (this->indexOutOfBounds(index))
			return;

		for (int i = index; i < this->realSize - 1; i++)
			this->data[i] = this->data[i + 1];

		this->data[realSize - 1] = 0;
		this->realSize--;
	}

	template<class T>
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

	
