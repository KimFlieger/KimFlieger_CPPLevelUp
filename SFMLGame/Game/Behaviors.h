#pragma once
#include "Precompiled.h"
#include "SteeringBehavior.h"
#include "MathUtilites.h"

using namespace AI;

namespace
{
	float RandomFloat()
	{
		return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	}

	float RandomFloat(float min, float max)
	{
		return min + (max - min) * (static_cast<float>(rand()) / static_cast<float>(RAND_MAX));
	}


	float maxSpeed = 500.0f;
	float distanceRad = 100.0f;
}

class SeekBehavior : public SteeringBehavior
{
public:
	SeekBehavior()
		:SteeringBehavior("Seek")
	{

	}

	~SeekBehavior() {}

	const char* GetName() { return "Seek"; }

	virtual sf::Vector2<float> Calculate(Agent& agent) override
	{
		if (agent.GetDestination() == agent.GetPosition()) return sf::Vector2<float>();

		sf::Vector2<float> desiredVelocity = MathUtilites::Normalize(agent.GetDestination() - agent.GetPosition()) * maxSpeed;

		return (desiredVelocity - agent.GetVelocity());
	}
};


class WanderBehavior : public SteeringBehavior
{
public:
	WanderBehavior()
		:SteeringBehavior("Wander")
	{

	}

	const char* GetName() { return "Wander"; }

	~WanderBehavior() {}

	virtual sf::Vector2<float> Calculate(Agent& agent) override
	{
		if (agent.GetDestination() == agent.GetPosition()) return sf::Vector2<float>();

		float wanderDistance = 100.0f;
		float wanderRadius = 50.0f;

		target += sf::Vector2<float>(RandomFloat(-10.0f, 10.0f), RandomFloat(-10.0f, 10.0f));
		target = MathUtilites::Normalize(target) * wanderRadius;

		sf::Vector2<float> center = agent.GetPosition() + agent.GetHeading() * wanderDistance;
		sf::Vector2<float> moveDirection = target + agent.GetHeading() * wanderDistance;

		//X::Math::Circle wanderCircle = X::Math::Circle(center, wanderRadius);
		//X::Math::Circle targetCircle = X::Math::Circle(target + center, 2.0f);

		//X::DrawScreenCircle(wanderCircle, X::Math::Vector4::Blue());
		//X::DrawScreenCircle(targetCircle, X::Math::Vector4::Orange());

		sf::Vector2<float> desiredVelocity = MathUtilites::Normalize(moveDirection) * maxSpeed;

		return (desiredVelocity - agent.GetVelocity());
	}

public:
	sf::Vector2<float> target;
};