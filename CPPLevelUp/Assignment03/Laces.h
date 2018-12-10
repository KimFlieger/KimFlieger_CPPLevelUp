#pragma once

class Laces
{
public:
	void SetTied(bool isTied)	{ mTied = isTied; }
	bool GetTied() const		{ return mTied; }

private:
	bool mTied = false;
};