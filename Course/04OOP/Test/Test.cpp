// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include <string>

#include "NewClass2.cpp"

class Person
{
private:
	int EGN;
public:
	Person(int age, std::string name) :
		age(age),
		name(name)
	{
	}

	int age;
	std::string name;
	int passportNum;

	std::string getInfo() const
	{
		std::string result = "";
		result.append("This is ")
			.append(this->name)
			.append(" and he/she is ")
			.append(std::to_string(this->age))
			.append(" years old");
		

		return result;
	}
};

void changeName(Person* person);


int main() 
{
	NewClass* wat = new NewClass(12, 36.6);
	std::cout << wat->getNum() << " and the other one: " << wat->getNum2();
	NewClass2 wat2(10, 100.1);
	return 0;
}

void changeName(Person* person)
{
	person->name = "Gosho";
}