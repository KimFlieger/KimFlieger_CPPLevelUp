#pragma once

class Belt
{
public:
	Belt() {}
	Belt(int size);

	void SetSize(int size)	{ mSize = size; }
	int GetSize() const		{ return mSize; }

private:
	int mSize;
};