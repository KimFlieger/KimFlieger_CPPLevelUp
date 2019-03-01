#pragma once
#include "SFML/Graphics.hpp"

class Character
{
public:
	Character()
		:mShape(10.0f)
	{
		mShape.setFillColor(sf::Color::Red);
	}

	~Character() {}

	//TODO Implement Move/Copy

	void Update();

	//Getters
	sf::CircleShape& GetShape() { return mShape; }

	//Setters

public:
	sf::CircleShape mShape;
	double mSpeed = 0.01f;
	double mXPosition = 5.0f;
	double mYPosition = 5.0f;
};

