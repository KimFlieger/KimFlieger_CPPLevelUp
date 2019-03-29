#pragma once
#include "Agent.h"
#include "SteeringModule.h"
#include "SteeringBehavior.h"
#include "Behaviors.h"

class Butterfly : public AI::Agent
{
public:
	Butterfly()
		:Agent(*this)
		, mBoundingCircle(25.0f)
	{
		mDestination = sf::Vector2f(10.0f, 10.0f);
	}

	~Butterfly()					= default;
	Butterfly(const Butterfly& lhs) = default;
	Butterfly(Butterfly&& lhs)		= default;

	void Initialize(float screenWidth, float screenHeight);
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	void Kill();

	void ChangeSteering(const char* name, bool active) { mSteeringModule->GetBehavior(name)->SetActive(active); }

	sf::CircleShape& GetBoundingCircle() { return mBoundingCircle; }

	bool GetActive() { return mIsActive; }

private:
	AI::SteeringModule* mSteeringModule;
	sf::CircleShape mBoundingCircle;
	sf::Texture mTexture;
	sf::Sprite mSprite;

	sf::Color mColor = sf::Color::Green;
	bool mIsActive = true;
	float mScreenHeight;
	float mScreenWidth;
	float mAngle;
};