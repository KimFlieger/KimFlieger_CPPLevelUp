#pragma once
#include <string>
#include "Laces.h"

class Shoes
{
public:
	Shoes() {}
	Shoes(const char* color);

	void SetColor(const char* color) { mColor = color; }
	void SetLaces(const Laces laces) { mLaces = laces; }

	const char* GetColor()	const { return mColor.c_str(); }
	Laces GetLaces()		const { return mLaces; }

private:
	std::string mColor;
	Laces mLaces;
};