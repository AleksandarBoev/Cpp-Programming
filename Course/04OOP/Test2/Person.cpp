#include "pch.h"
#include "Person.h"


Person::Person()
{
}

Person::Person(int age, std::string name):
	age(age),
	name(name)
{
}


Person::~Person()
{
}

int Person::getAge() const
{
	return this->age;
}

std::string Person:: getName() const
{
	return this->name;
}
