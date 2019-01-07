#include "CustomClass.h"
#include <iostream>
#include <stdio.h>

void PrintArray(const char* pointer)
{
	int i = 0;
	char c =  '0';

	while (c != '/0')
	{
		c = pointer[i];
		std::cout << c;

		++i;
	}
}

void ReverseArray(const char* pointer, int sizeOfArray)
{
	int newI = 0;
	char c = '0';
	char* newPointer = new char('/0');

	for (unsigned int i = sizeOfArray - 1; i > 0; --i, ++newI)
	{
		newPointer[newI] = pointer[i];
	}

	newI = 0;
	while (c != '/0')
	{
		c = pointer[newI];
		std::cout << c;

		++newI;
	}
}

void main()
{
	const int characterArraySize = 5;
	const int integerArraySize = 1000;
	char characters[characterArraySize] = { '0' };
	characters[characterArraySize - 1] = '/0';

	int integers[integerArraySize] = { 0 };

	for (unsigned int i = 0; i < integerArraySize; ++i)
	{
		integers[i] = i;
	}

	CustomClass customClass;
	PrintArray(characters);
	ReverseArray(characters, characterArraySize);

}