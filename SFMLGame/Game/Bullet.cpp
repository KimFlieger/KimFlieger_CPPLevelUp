#include "Precompiled.h"
#include "Bullet.h"

void Bullet::Load()
{
	//mSprite.setTexture(texturename);
	mCircle.setFillColor(sf::Color::Blue);
}

void Bullet::Update(sf::Time deltaTime)
{
	if (mActive)
	{
		mPosition += mVelocity * deltaTime.asSeconds();
	}
}

void Bullet::Render(sf::RenderWindow& window)
{
	if (mActive)
	{
		sf::Vector2<float> renderPosition;

		renderPosition.x = mPosition.x - (10.0f);
		renderPosition.y = mPosition.y - (10.0f);

		mCircle.setPosition(renderPosition);
		window.draw(mCircle);
	}
}

void Bullet::Fire(sf::Vector2<float> pos, sf::Vector2<float> vel)
{
	mPosition = pos;
	mVelocity = vel;
	mActive = true;
}

void Bullet::Kill()
{
	mActive = false;
}