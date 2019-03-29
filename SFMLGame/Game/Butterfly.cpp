#include "Precompiled.h"
#include "Butterfly.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"

void Butterfly::Initialize(float screenWidth, float screenHeight)
{
	mSteeringModule = new SteeringModule(*this);
	mSteeringModule->AddBehavior(new SeekBehavior());
	mSteeringModule->AddBehavior(new WanderBehavior());


	//mSteeringModule->GetBehavior("Seek")->SetActive(true);
	mSteeringModule->GetBehavior("Wander")->SetActive(true);

	mScreenHeight = screenHeight;
	mScreenWidth = screenWidth;

	mPosition.x = RandomFloat(0, screenWidth);
	mPosition.y = RandomFloat(0, screenHeight);

	mBoundingCircle.setPosition(mPosition.x, mPosition.y);


	mTexture.loadFromFile("../Images/BlueButterfly.png");

	mSprite.setTexture(mTexture);
	mSprite.setScale(sf::Vector2f(0.1f, 0.1f));
	mSprite.setOrigin(sf::Vector2f(25.0f, 100.0f));
	mSprite.setColor(sf::Color(RandomFloat(0, 255), RandomFloat(0, 255), RandomFloat(0, 255)));
	//mColor = sf::Color(RandomFloat(0, 255), RandomFloat(0, 255), RandomFloat(0, 255));

	maxSpeed = 100.0f;
	mIsActive = true;
}

void Butterfly::Update(float deltaTime)
{
	if (!mIsActive)
	{
		return;
	}

	mDestination.x = (float)sf::Mouse::getPosition().x;
	mDestination.y = (float)sf::Mouse::getPosition().y;

	sf::Vector2<float> force = mSteeringModule->Calculate();
	
	mVelocity.x += force.x * deltaTime;
	mVelocity.y += force.y * deltaTime;

	mPosition.x += mVelocity.x * deltaTime;
	mPosition.y += mVelocity.y * deltaTime;

	if (mPosition.x < 0) mPosition.x += mScreenWidth;
	if (mPosition.x > mScreenWidth) mPosition.x -= mScreenWidth;
	if (mPosition.y < 0) mPosition.y += mScreenHeight;
	if (mPosition.y > mScreenHeight) mPosition.y -= mScreenHeight;

	mHeading = MathUtilites::Normalize(mVelocity);
	mAngle = atan2(-mHeading.x, mHeading.y) + MathUtilites::kPi;

	mBoundingCircle.setPosition(mPosition.x, mPosition.y);

	mSprite.setPosition(mPosition);
}

void Butterfly::Render(sf::RenderWindow& window)
{
	if (!mIsActive)
	{
		return;
	}
	window.draw(mSprite);
}

void Butterfly::Kill()
{
	mIsActive = false;
}