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
	constexpr float distanceRad = 100.0f;
}

class SeekBehavior : public SteeringBehavior
{
public:
	SeekBehavior()
		:SteeringBehavior("Seek")
	{

	}

	~SeekBehavior()							= default;
	SeekBehavior(const SeekBehavior& lhs)	= default;
	SeekBehavior(SeekBehavior&& lhs)		= default;

	const char* GetName() { return "Seek"; }

	virtual sf::Vector2f Calculate(Agent& agent) override
	{
		if (agent.GetDestination() == agent.GetPosition()) return sf::Vector2f();

		sf::Vector2f desiredVelocity = MathUtilites::Normalize(agent.GetDestination() - agent.GetPosition()) * maxSpeed;

		return (desiredVelocity - agent.GetVelocity());
	}
};


class WanderBehavior : public SteeringBehavior
{
public:
	WanderBehavior()
		:SteeringBehavior("Wander")
		, target(0.0f, 0.0f)
	{

	}

	~WanderBehavior()							= default;
	WanderBehavior(const WanderBehavior& lhs)	= default;
	WanderBehavior(WanderBehavior&& lhs)		= default;

	const char* GetName() { return "Wander"; }

	virtual sf::Vector2f Calculate(Agent& agent) override
	{
		if (agent.GetDestination() == agent.GetPosition()) return sf::Vector2f();


		target += sf::Vector2f(RandomFloat(-10.0f, 10.0f), RandomFloat(-10.0f, 10.0f));
		target = MathUtilites::Normalize(target) * mWanderRadius;

		sf::Vector2f moveDirection = target + agent.GetHeading() * mWanderRadius;

		sf::Vector2f desiredVelocity = MathUtilites::Normalize(moveDirection) * maxSpeed;

		return (desiredVelocity - agent.GetVelocity());
	}

public:
	sf::Vector2f target;
	static constexpr float mWanderRadius = 50.0f;
};