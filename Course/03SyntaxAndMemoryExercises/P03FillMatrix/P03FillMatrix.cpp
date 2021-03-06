#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

char** createMatrix(int rows, int cols);

void readMatrix(char** charMatrix, int rows, int cols);

void printMatrix(char** charMatrix, int rows, int cols);

void spread(char** charMatrix, int rows, int cols, int row, int col, char& character);

int main()
{
	int rows, cols;
	std::cin >> rows >> cols;
	std::cin.ignore();

	char** charMatrix = createMatrix(rows, cols);
	readMatrix(charMatrix, rows, cols);
	
	char characterToBeReplaced = 'z';
	spread(charMatrix, rows, cols, 0, 1, characterToBeReplaced);

	std::cout << std::endl;
	printMatrix(charMatrix, rows, cols);
	
	//Release memory
	for (int i = 0; i < rows; i++)
		delete[] charMatrix[i];

	delete[] charMatrix;

	return 0;
}

char** createMatrix(int rows, int cols)
{
	char** charMatrix = new char*[rows];
	for (int i = 0; i < rows; i++)
		charMatrix[i] = new char[cols];

	return charMatrix;
}

void readMatrix(char** charMatrix, int rows, int cols)
{
	std::string line;
	std::stringstream stringStream;
	for (int i = 0; i < rows; i++)
	{
		std::getline(std::cin, line);
		stringStream << line;

		for (int j = 0; j < cols; j++)
		{
			stringStream >> charMatrix[i][j];
		}
	}
}

void printMatrix(char** charMatrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			std::cout << charMatrix[i][j] << " ";
		
		std::cout << std::endl;
	}
}

void spread(char** charMatrix, int rows, int cols, int row, int col, char& newCharacter)
{
	char characterToBeReplaced = charMatrix[row][col];
	charMatrix[row][col] = newCharacter;

	for (int i = row; i >= 1; i--)
	{
		if (charMatrix[i - 1][col] == characterToBeReplaced)
			charMatrix[i - 1][col] = newCharacter;
		else
			break;
	}

	for (int i = row; i < rows - 1; i++)
	{
		if (charMatrix[i + 1][col] == characterToBeReplaced)
			charMatrix[i + 1][col] = newCharacter;
		else
			break;
	}

	for (int i = col; i >= 1; i--)
	{
		if (charMatrix[row][i - 1] == characterToBeReplaced)
			charMatrix[row][i - 1] = newCharacter;
		else
			break;
	}

	for (int i = col; i < cols - 1; i++)
	{
		if (charMatrix[row][i + 1] == characterToBeReplaced)
			charMatrix[row][i + 1] = newCharacter;
		else
			break;
	}
}
