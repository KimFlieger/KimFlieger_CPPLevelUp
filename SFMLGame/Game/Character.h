#pragma once

#include "Bullet.h"
#include "CollisionDetection.h"
#include "MathUtilites.h"

class Character
{
public:
	Character()
		:mBoundingCircle(30.0f)
		, mPosition(640.0f,480.0f)
	{
	}

	~Character() {}

	//TODO Implement Move/Copy
	void Initialize();
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	bool CheckBulletCollision(sf::CircleShape& circle);

	//Getters
	sf::CircleShape& GetBoundingCircle() { return mBoundingCircle; }

	//Setters

protected:
	void Fire();

	sf::CircleShape mBoundingCircle;
	sf::Texture mTexture;
	sf::Sprite mSprite;

	sf::Vector2<float> mPosition;
	sf::Vector2i mMousePosition;
	static constexpr float kSpeed = 0.3f;

	static constexpr float kBulletAngle = MathUtilites::kPi / 4;
	const unsigned int kBulletMax = 1000;
	int mBulletIndex = 0;
	Bullet *mBullets = new Bullet[kBulletMax];
	float mCurrentTime = 0.0f;
	static constexpr float mBulletWaitTime = 0.005f;
};

