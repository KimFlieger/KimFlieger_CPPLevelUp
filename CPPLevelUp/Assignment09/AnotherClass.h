#pragma once
#include "CustomClass.h"

class AnotherClass
{
	AnotherClass()
	{
		mCustomClass = new CustomClass();
	}

	~AnotherClass()
	{
		delete[] mCustomClass;
		mCustomClass = nullptr;
	}

private:
	CustomClass* mCustomClass;
};