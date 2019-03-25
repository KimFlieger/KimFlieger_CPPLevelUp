#pragma once

#include "Bullet.h"

class Character
{
public:
	Character()
		:mShape(10.0f)
		, mPosition(5.0f,5.0f)
	{
	}

	~Character() {}

	//TODO Implement Move/Copy
	void Initialize();
	void Update(sf::Time deltaTime);
	void Render(sf::RenderWindow& window);

	//Getters
	sf::CircleShape& GetShape() { return mShape; }

	//Setters

public:
	void Fire();

	sf::CircleShape mShape;

	const unsigned int kBulletMax = 1000;
	int mBulletIndex = 0;
	Bullet *mBullets = new Bullet[kBulletMax];

	double mSpeed = 0.1f;
	sf::Vector2<float> mPosition;
};

