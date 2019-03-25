#include "Precompiled.h"
#include "Character.h"
#include "SFML/Window/Keyboard.hpp"

void Character::Initialize()
{
	mShape.setFillColor(sf::Color::Red);

	for (unsigned int i = 0; i < kBulletMax; ++i)
	{
		mBullets[i].Load();
	}
}

void Character::Render(sf::RenderWindow& window)
{
	window.draw(mShape);

	for (unsigned int i = 0; i < kBulletMax; ++i)
	{
		mBullets[i].Render(window);
	}
}

void Character::Update(sf::Time deltaTime)
{
	for (unsigned int i = 0; i < kBulletMax; ++i)
	{
		mBullets[i].Update(deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mPosition.x += mSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mPosition.x -= mSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		mPosition.y -= mSpeed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		mPosition.y += mSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Fire();
	}

	mShape.setPosition(mPosition);
}

void Character::Fire()
{
	sf::Vector2<float> velocity(10.0f, -5000.0f);

	//Middle shot
	mBullets[mBulletIndex].Fire(mPosition, velocity);
	mBulletIndex = (mBulletIndex + 1) % kBulletMax;

	////Right Shot
	//velocity.x = EnVelx;

	//mBullets[mBulletIndex].Fire(mPosition, velocity);
	//mBulletIndex = (mBulletIndex + 1) % kMax;

	////Left Shot
	//velocity.x = -EnVelx;

	//mBullets[mBulletIndex].Fire(mPosition, velocity);
	//mBulletIndex = (mBulletIndex + 1) % kMax;

	////BACK ONES

	////Right shot
	//velocity.y = 500;
	//velocity.x = EnVelx;

	//mBullets[mBulletIndex].Fire(mPosition, velocity);
	//mBulletIndex = (mBulletIndex + 1) % kMax;

	////Left shot
	//velocity.x = -EnVelx;

	//mBullets[mBulletIndex].Fire(mPosition, velocity);
	//mBulletIndex = (mBulletIndex + 1) % kMax;


	////Middle shot
	//velocity.x = 0;

	//mBullets[mBulletIndex].Fire(mPosition, velocity);
	//mBulletIndex = (mBulletIndex + 1) % kMax;

}