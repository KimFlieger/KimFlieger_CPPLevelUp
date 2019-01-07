#pragma once

class CustomArray
{
public:
	CustomArray()
		:mSize(0)
		, mCapacity(1)
	{
		mData = new float[mCapacity];
	}

	CustomArray(const int capacity)
		:mSize(0)
		, mCapacity(capacity)
	{
		mData = new float[capacity];
	}

	~CustomArray()
	{
		delete[] mData;
		mData = nullptr;
	}

	void Add(float value);
	void Remove(const unsigned int index);
	float Get(const unsigned int index) const;

private:
	float* mData;
	unsigned int mSize;
	unsigned int mCapacity;
};