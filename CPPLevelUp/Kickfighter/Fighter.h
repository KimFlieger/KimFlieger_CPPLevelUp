#pragma once

class Fighter
{
public:
	virtual ~Fighter() {}
	virtual void Attack() = 0;
	unsigned int GetHealth() { return mHealth; }

protected:
	unsigned int mHealth;
};