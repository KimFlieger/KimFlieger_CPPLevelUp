#include "Precompiled.h"
#include "Character.h"
#include "SFML/Window/Keyboard.hpp"

void Character::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mXPosition += mSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mXPosition -= mSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mYPosition -= mSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mYPosition += mSpeed;
	}

	mShape.setPosition(mXPosition, mYPosition);
}
