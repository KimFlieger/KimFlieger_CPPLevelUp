#include "CustomArray.h"
#include <iostream>

void CustomArray::Add(float value)
{
	if (mSize == mCapacity)
	{
		mCapacity = mSize * 2;
		float* temp = new float[mCapacity];

		std::memcpy(temp, mData, mSize);

		delete[] mData;

		mData = temp;
	}

	mData[mSize] = value;
	mSize++;
}

void CustomArray::Remove(const unsigned int index)
{
	if (index >= mSize)
	{
		return;
	}

	mData[index] = mData[mSize];
	mSize--;
}

float CustomArray::Get(const unsigned int index) const
{
	if (index >= mSize)
	{
		return 0.0f;
	}

	return mData[index];
}