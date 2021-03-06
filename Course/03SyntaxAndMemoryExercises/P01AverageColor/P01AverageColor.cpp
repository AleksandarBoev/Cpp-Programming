#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/*
Sources used: 
	www.cplusplus.com/reference/ios/dec/
	techspirited.com/how-to-convert-hexadecimal-to-decimal-vice-versa
	stackoverflow.com/questions/11031159/converting-hexadecimal-to-decimal
*/

void getRgbValues(const std::string& hexValue, int& red, int& green, int& blue);

std::string getHexValue(int red, int green, int blue);

void addZerosToFront(std::string& hex, int wantedLength);

int main()
{
	//int rgbValue1, rgbValue2;
	//std::cin >> std::hex >> rgbValue1 >> rgbValue2;
	int red1, green1, blue1, red2, green2, blue2;

	std::string hexRgbValue1, hexRgbValue2;
	std::cin >> hexRgbValue1 >> hexRgbValue2;

	getRgbValues(hexRgbValue1, red1, green1, blue1);
	getRgbValues(hexRgbValue2, red2, green2, blue2);
	
	int averageRed = (red1 + red2) / 2;
	int averageGreen = (green1 + green2) / 2;
	int averageBlue = (blue1 + blue2) / 2;

	std::cout << getHexValue(averageRed, averageGreen, averageBlue);

	//std::cout << rgbValue1 << std::endl << rgbValue2;



	return 0;
}

void getRgbValues(const std::string& hexValue, int& red, int& green, int& blue)
{
	std::string redHexValue = "aa", greenHexValue = "aa", blueHexValue = "aa";
	
	redHexValue[0] = hexValue[1];
	redHexValue[1] = hexValue[2];
	greenHexValue[0] = hexValue[3];
	greenHexValue[1] = hexValue[4];
	blueHexValue[0] = hexValue[5];
	blueHexValue[1] = hexValue[6];

	std::stringstream stringStream;
	stringStream << redHexValue << " " << greenHexValue << " " << blueHexValue;

	stringStream >> std::hex >> red;
	stringStream >> std::hex >> green;
	stringStream >> std::hex >> blue;
}

std::string getHexValue(int red, int green, int blue)
{
	std::string result = "#";
	
	std::stringstream stringStream;

	std::string redHex, greenHex, blueHex;

	stringStream << std::hex << red << " " << green << " " << blue;
	stringStream >> redHex;

	stringStream >> greenHex;

	stringStream >> blueHex;

	addZerosToFront(redHex, 2);
	addZerosToFront(greenHex, 2);
	addZerosToFront(blueHex, 2);

	result.append(redHex).append(greenHex).append(blueHex);
	return result;
}

void addZerosToFront(std::string& hex, int wantedLength)
{
	int numberOfZerosToBeAdded = wantedLength - hex.length();
	if (numberOfZerosToBeAdded == 0)
		return;

	std::string zeros(numberOfZerosToBeAdded, '0');

	hex = zeros + hex;
}

