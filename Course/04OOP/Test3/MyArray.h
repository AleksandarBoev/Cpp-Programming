#pragma once
class MyArray
{
private:
	int* data;
	int size;
public:
	MyArray();
	MyArray(int size);
	~MyArray();

	MyArray(const MyArray& another);

	MyArray& operator=(const MyArray& other);

	int getSize() const;

	int getElement(int index) const;

	void setValue(int index, int value);
};

