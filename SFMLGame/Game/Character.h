#pragma once

#include "Bullet.h"
#include "CollisionDetection.h"

class Character
{
public:
	Character()
		:mShape(10.0f)
		, mPosition(640.0f,480.0f)
	{
	}

	~Character() {}

	//TODO Implement Move/Copy
	void Initialize();
	void Update(sf::Time deltaTime);
	void Render(sf::RenderWindow& window);
	bool CheckBulletCollision(sf::CircleShape& circle);

	//Getters
	sf::CircleShape& GetBoundingCircle() { return mShape; }

	//Setters

protected:
	void Fire();

	sf::CircleShape mShape;
	sf::Vector2<float> mPosition;
	const double mSpeed = 0.2f;

	const unsigned int kBulletMax = 1000;
	int mBulletIndex = 0;
	Bullet *mBullets = new Bullet[kBulletMax];
};

