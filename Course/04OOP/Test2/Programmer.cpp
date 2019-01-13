#include "pch.h"
#include "Programmer.h"


Programmer::Programmer()
{
}

Programmer::Programmer(int age, std::string name, std::string profession) :
	Person(age, name),
	profession(profession)
{
}

std::string Programmer::getProfession() const
{
	return this->profession;
}


Programmer::~Programmer()
{
}
