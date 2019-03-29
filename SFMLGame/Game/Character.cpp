#include "Precompiled.h"
#include "Character.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"

void Character::Initialize()
{
	for (unsigned int i = 0; i < kBulletMax; ++i)
	{
		mBullets[i].Load();
	}
	
	mTexture.loadFromFile("../Images/GhafurWithShotGunAndWings.png");
	mSprite.setTexture(mTexture);
	mSprite.setScale(mScale);
	mSprite.setOrigin(mOrigin);
}

void Character::Render(sf::RenderWindow& window)
{
	window.draw(mSprite);

	for (unsigned int i = 0; i < kBulletMax; ++i)
	{
		mBullets[i].Render(window);
	}

	mMousePosition = sf::Mouse::getPosition(window);
}

void Character::Update(float deltaTime)
{
	mCurrentTime += deltaTime;

	for (unsigned int i = 0; i < kBulletMax; ++i)
	{
		mBullets[i].Update(deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mPosition.x += kSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mPosition.x -= kSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mPosition.y -= kSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mPosition.y += kSpeed;
	}

	if (mCurrentTime > mBulletWaitTime && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		Fire();
		mCurrentTime = 0.0f;
	}

	mBoundingCircle.setPosition(mPosition);
	mSprite.setPosition(mPosition);

	//if (mPosition.x < mMousePosition.x)
	//{
	//	mSprite.setScale(sf::Vector2f(mScale.x, mScale.y));
	//	mSprite.setOrigin(sf::Vector2f(mOrigin.x, mOrigin.y));
	//}
	//else
	//{
	//	mSprite.setScale(sf::Vector2f(-mScale.x, mScale.y));
	//	mSprite.setOrigin(sf::Vector2f(-(mOrigin.x * 2), mOrigin.y));
	//}
}

void Character::Fire()
{
	auto bulletDirection = MathUtilites::Normalize(sf::Vector2<float>(static_cast<float>(mMousePosition.x), static_cast<float>(mMousePosition.y)) - mPosition);
	constexpr float magnitude = 5000.0f;
	
	sf::Vector2f rightBullet = MathUtilites::Rotate(bulletDirection, kBulletAngle);
	sf::Vector2f leftBullet = MathUtilites::Rotate(bulletDirection, -kBulletAngle);

	sf::Vector2f velocity = bulletDirection * magnitude;

	sf::Vector2f mOffset = mPosition + sf::Vector2f(55.0f, 50.0f); //For the gun

	//Middle shot
	mBullets[mBulletIndex].Fire(mOffset, velocity);
	mBulletIndex = (mBulletIndex++) % kBulletMax;

	//Right Shot
	velocity = rightBullet * magnitude;

	mBullets[mBulletIndex].Fire(mOffset, velocity);
	mBulletIndex = (mBulletIndex++) % kBulletMax;

	//Left Shot
	velocity = leftBullet * magnitude;

	mBullets[mBulletIndex].Fire(mOffset, velocity);
	mBulletIndex = (mBulletIndex++) % kBulletMax;
}

bool Character::CheckBulletCollision(sf::CircleShape& circle)
{
	for (unsigned int i = 0; i < kBulletMax; ++i)
	{
		if (mBullets[i].IsActive())
		{
			if (CollsionDetection::CheckCollision(mBullets[i].GetBoundingCircle(), circle))
			{
				mBullets[i].Kill();
				return true;
			}
		}
	}

	return false;
}