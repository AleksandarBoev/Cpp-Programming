#pragma once
#include <string>
#include <vector>
template<typename T>
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

	//MyArrayList operator+(std::vector<T> other) const;

	T operator[](int index) const;

	T* getData() const;

	int getSize() const;

	T getElement(int index) const;

	void addElement(T element);

	void addElement(int index, T value);

	void setElement(int index, T newElement);

	void removeElement(int index);

	std::string toString() const;
};

