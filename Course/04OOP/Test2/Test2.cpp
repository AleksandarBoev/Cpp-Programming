#include "pch.h"
#include <iostream>
#include "Person.h"
#include "Programmer.h"

int main()
{
	Person* person = new Person(23, "Aleksandar"); //for some reason I can't have only a constructor with 0 params
	std::cout << "Person name is " << person->getName() << " and he is " << person->getAge() << " years old";

	Programmer person2(33, "Ivan", "CTO");

	std::cout << std::endl << "Programmer name is " << person2.getName() << " and the age is " <<
		person2.getAge() << " and most importantly the profession: " << person2.getProfession();
	return 0;
}

