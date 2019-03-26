#include "Precompiled.h"
#include "Butterfly.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"

void Butterfly::Initialize(float screenWidth, float screenHeight)
{
	mSteeringModule = new SteeringModule(*this);
	mSteeringModule->AddBehavior(new SeekBehavior());
	mSteeringModule->AddBehavior(new WanderBehavior());

	mTextureIds->loadFromFile("Images/Butterfly.jpg");

	//mSteeringModule->GetBehavior("Seek")->SetActive(true);
	mSteeringModule->GetBehavior("Wander")->SetActive(true);

	mScreenHeight = screenHeight;
	mScreenWidth = screenWidth;

	maxSpeed = 100.0f;
}

void Butterfly::Update(sf::Time deltaTime)
{
	mDestination.x = (float)sf::Mouse::getPosition().x;
	mDestination.y = (float)sf::Mouse::getPosition().y;

	sf::Vector2<float> force = mSteeringModule->Calculate();
	
	mVelocity.x += force.x * deltaTime.asSeconds();
	mVelocity.y += force.y * deltaTime.asSeconds();

	mPosition.x += mVelocity.x * deltaTime.asSeconds();
	mPosition.y += mVelocity.y * deltaTime.asSeconds();

	if (mPosition.x < 0) mPosition.x += mScreenWidth;
	if (mPosition.x > mScreenWidth) mPosition.x -= mScreenWidth;
	if (mPosition.y < 0) mPosition.y += mScreenHeight;
	if (mPosition.y > mScreenHeight) mPosition.y -= mScreenHeight;

	mHeading = MathUtilites::Normalize(mVelocity);
	mAngle = atan2(-mHeading.x, mHeading.y) + MathUtilites::kPi;

	mShape.setFillColor(mColor);
	mShape.setPosition(mPosition.x, mPosition.y);
}

void Butterfly::Render(sf::RenderWindow& window)
{
	window.draw(mShape);
}

void Butterfly::Kill()
{
	mColor = sf::Color::Red;
}