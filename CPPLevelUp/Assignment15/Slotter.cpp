#include "Slotter.h"

const char* Slotter::GetName() const 
{ 
	return mName.c_str(); 
}

unsigned int Slotter::GetLegsNum() const 
{
	return mLegsNum;
}

float Slotter::GetLength() const 
{
	return mLength;
}

void Slotter::SetName(const char* name)
{
	if (name[0] == 'a' || name[0] == 'e' || name[0] == 'i' || name[0] == 'o' || name[0] == 'u')
	{
		throw std::invalid_argument("Get outta here with your VOWELS");
	}

	mName = name; 
}

void Slotter::SetLegsNum(const unsigned int legsNum) 
{
	if (legsNum % 2 == 0)
	{
		throw std::invalid_argument("Cannot have an even amount of legs ya'll crazy");
	}

	mLegsNum = legsNum; 
}

void Slotter::SetLength(const float length) 
{
	if (length > 0.1f || length < 0.001f)
	{
		throw std::invalid_argument("Thats a terrible length");
	}

	mLength = length;
}
