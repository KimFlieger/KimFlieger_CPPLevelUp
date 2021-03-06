#include "Precompiled.h"
#include "Bullet.h"

void Bullet::Load()
{
	mCircle.setFillColor(sf::Color::Black);
}

void Bullet::Update(float deltaTime)
{
	if (mActive)
	{
		mPosition += mVelocity * deltaTime;
	}
}

void Bullet::Render(sf::RenderWindow& window)
{
	if (mActive)
	{
		mCircle.setPosition(mPosition);
		window.draw(mCircle);
	}
}

void Bullet::Fire(sf::Vector2f pos, sf::Vector2f vel)
{
	mPosition = pos;
	mVelocity = vel;
	mActive = true;
}

void Bullet::Kill()
{
	mActive = false;
}