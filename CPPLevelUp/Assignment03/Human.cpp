#include "Human.h"

Human::Human(const char* name, int beltSize, const char* shoeColor)
	:mName(name)
{
	mBelt.SetSize(beltSize);
	mShoes.SetColor(shoeColor);
}