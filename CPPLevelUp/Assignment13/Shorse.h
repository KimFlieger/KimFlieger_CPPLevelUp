#pragma once

class Shorse
{
public:
	bool operator<(const Shorse& rhs) const
	{
		return (mNumOfTeeth < rhs.mNumOfTeeth);
	}

	bool operator>(const Shorse& rhs) const
	{
		return (mNumOfTeeth > rhs.mNumOfTeeth);
	}

	int GetTeethNumber() const { return mNumOfTeeth; }
	void SetTeethNumber(int num ) { mNumOfTeeth = num; }

private:
	int mNumOfTeeth = 0;
};