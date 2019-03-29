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

	const unsigned int kBulletMax = 1000;
	Bullet *mBullets = new Bullet[kBulletMax];

	sf::CircleShape mBoundingCircle;
	sf::Texture mTexture;
	sf::Sprite mSprite;
	sf::Vector2<float> mPosition;
	sf::Vector2i mMousePosition;

	static constexpr float kSpeed = 0.3f;
	static constexpr float kBulletAngle = MathUtilites::kPi / 4;
	static constexpr float mBulletWaitTime = 0.005f;

	int mBulletIndex = 0;
	float mCurrentTime = 0.0f;
	const sf::Vector2f mScale = sf::Vector2f(0.2f, 0.2f);
	const sf::Vector2f mOrigin = sf::Vector2f(100.0f, 100.0f);
};

