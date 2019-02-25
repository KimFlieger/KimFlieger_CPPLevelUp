#pragma once

class Platyporse
{
public:
	bool operator<(const Platyporse& rhs) const
	{
		return (mBillLength < rhs.mBillLength);
	}

	bool operator>(const Platyporse& rhs) const
	{
		return (mBillLength > rhs.mBillLength);
	}

	int GetBillLength() const { return mBillLength; }
	void SetBillLength(int length) { mBillLength = length; }

private:
	int mBillLength;
};