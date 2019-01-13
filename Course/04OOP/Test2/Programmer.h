#pragma once
#include "Person.h"
class Programmer :
	public Person
{
private:
	std::string profession;
public:

	Programmer();
	~Programmer();

	Programmer(int age, std::string name, std::string profession);

	std::string getProfession() const;
};

