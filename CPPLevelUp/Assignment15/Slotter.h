#pragma once
#include <string>

class Slotter
{
public:
	//Getters
	const char* GetName() const;
	unsigned int GetLegsNum() const;
	float GetLength() const;

	//Setters
	void SetName(const char* name);
	void SetLegsNum(const unsigned int legsNum);
	void SetLength(const float length);

private:
	std::string mName;
	unsigned int mLegsNum;
	float mLength;
};