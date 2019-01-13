#pragma once
#include <string>
class Person
{
private:
	int age;
	std::string name;

public:
	Person();

	Person(int age, std::string name);
	~Person();

	int getAge() const;
	std::string getName() const;
};

