#pragma once
#include <string>
#include "Belt.h"
#include "Shoes.h"

class Human
{
public:
	Human(const char* name, int beltSize, const char* shoeColor);

	void SetName(const char* name)	{ mName = name; }
	void SetShoes(const Shoes shoe) { mShoes = shoe; }
	void SetBelt(const Belt belt)	{ mBelt = belt; }

	const char* GetName()	const { return mName.c_str(); }
	Shoes GetShoes()		const { return mShoes; }
	Belt GetBelt()			const { return mBelt; }

private:
	std::string mName;
	Shoes mShoes; 
	Belt mBelt;
};