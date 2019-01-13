#include "pch.h"
#include <string>
class NewClass
{
private:
	int num;
	double num2;
	std::string name;
public:
	NewClass(int num, double num2) :
		num(num),
		num2(num2)
	{
	}

	NewClass(int num, double num2, std::string name) :
		num(num),
		num2(num2),
		name(name)
	{
	}

	int getNum() const
	{
		return this->num;
	}

	double getNum2() const
	{
		return this->num2;
	}
};