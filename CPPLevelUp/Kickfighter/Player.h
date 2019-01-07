#pragma once
#include "Fighter.h"

class Player : public Fighter
{
public:
	virtual ~Player() {}
	virtual void Attack() override;

protected:

};