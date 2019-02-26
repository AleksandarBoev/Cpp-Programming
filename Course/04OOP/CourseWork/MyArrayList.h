#ifndef _MYARRAYLIST_H_
#define _MYARRAYLIST_H_

#pragma once
#include <string>
#include "MyArrayList.cpp"


template<class T>
class MyArrayList
{
private:
	T* data;
	int size, realSize;

	MyArrayList(int size, int realSize, T* data);

	bool indexOutOfBounds(int index);
public:
	MyArrayList();

	MyArrayList(int size);

	~MyArrayList();

	MyArrayList(const MyArrayList& another);

	MyArrayList& operator=(const MyArrayList& other);

	bool operator==(const MyArrayList& other) const;

	MyArrayList operator+(const MyArrayList& other) const;

	MyArrayList operator+(std::vector<T> other) const;

	T operator[](int index) const;

	T* getData() const;

	int getSize() const;

	T getElement(int index) const;

	/*
	The normal ArrayList usually has an initial capacity of 8 (I think). And when the maximum is reached,
	that capacity is doubled and THEN a new array is created and all values are transfered.
	Creating and transfering every single time is not optimal.
	*/
	void addElement(T element);

	void addElement(int index, T value);

	void setElement(int index, T newElement);

	void removeElement(int index)


	std::string toString() const;

	void removeElement(int index);


};


#endif