#include "pch.h"
#include "NewClass.cpp"
class NewClass2 : public NewClass
{
private:
	bool noTime;
public:
	NewClass2(int num, double num2) :
		NewClass(num, num2) 
	{
	}

	NewClass2(int num, double num2, std::string name) :
		NewClass(num, num2, name)
	{
	}

	NewClass2(int num, double num2, std::string name, bool noTime) :
		NewClass(num, num2, name),
		noTime(noTime)
	{
	}
};