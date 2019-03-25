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
		, mShape(10.0f)
	{
		mDestination = sf::Vector2<float>(10.0f, 10.0f);
	}

	void Initialize(float screenWidth, float screenHeight);
	void Update(sf::Time deltaTime);
	void Render(sf::RenderWindow& window);

	void ChangeSteering(const char* name, bool active) { mSteeringModule->GetBehavior(name)->SetActive(active); }

	sf::CircleShape& GetShape() { return mShape; }
	sf::Texture& GetTextures() { return mTextureIds[0]; }

private:
	AI::SteeringModule* mSteeringModule;
	sf::CircleShape mShape;

	sf::Texture mTextureIds[1];
	float mScreenHeight;
	float mScreenWidth;
	float mAngle;
};