#pragma once
#include "Agent.h"
#include "SteeringBehavior.h"

class Butterfly : public AI::Agent
{
public:
	void Initialize();
	void Update(float deltaTime);
	void Render();

private:
	AI::SteeringBehavior* mSteeringBehavior;

	//int mTextureIds[16];
	float mScreenHeight;
	float mScreenWidth;
	float mAngle;

	sf::Vector2<float> mPosition;
	sf::Vector2<float> mDestination;
};