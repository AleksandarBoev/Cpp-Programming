#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

/*
Write a program which checks if the lines of two text files are the same
(same number of lines and each line from the first file should be equal
to the line of the second file).
*/

std::string getFileContent(const std::string& filePath);

int main()
{
	const std::string textFile1Path = "text-file1.txt", textFile2Path = "text-file2.txt";

	std::string file1Content, file2Content;

	file1Content = getFileContent(textFile1Path);
	file2Content = getFileContent(textFile2Path);

	file1Content == file2Content
		? std::cout << "The two files are identical."
		: std::cout << "The two files are different.";

	return 0;
}

std::string getFileContent(const std::string& filePath)
{
	std::ifstream stream;
	stream.open(filePath, std::ios::in);

	std::string currentLine, result;
	while (std::getline(stream, currentLine))
		result.append(currentLine).append("\r\n");

	stream.close();
	return result;
}