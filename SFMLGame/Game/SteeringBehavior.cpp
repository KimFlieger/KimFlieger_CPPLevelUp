#include "Precompiled.h"
#include "SteeringBehavior.h"

//Move these
inline float Sqrt(float value) { return sqrtf(value); }
inline float MagnitudeSqr(const  sf::Vector2<float>& v) { return (v.x * v.x) + (v.y * v.y); }
inline float Magnitude(const sf::Vector2<float>& v) { return Sqrt(MagnitudeSqr(v)); }
inline sf::Vector2<float> Normalize(const sf::Vector2<float>& v) { return v / Magnitude(v); }

float RandomFloat()
{
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

float RandomFloat(float min, float max)
{
	return min + (max - min) * RandomFloat();
}

sf::Vector2<float>  AI::SteeringBehavior::CalculateSeek(Agent& agent)
{
	if (agent.GetDestination() == agent.GetPosition()) return sf::Vector2<float>();

	sf::Vector2<float>  desiredVelocity = Normalize(agent.GetDestination() - agent.GetPosition()) * agent.GetMaxSpeed();

	return (desiredVelocity - agent.GetVelocity());
}

sf::Vector2<float> AI::SteeringBehavior::CalculateWander(Agent& agent)
{
	sf::Vector2<float> target;
	if (agent.GetDestination() == agent.GetPosition()) return sf::Vector2<float>();

	float wanderDistance = 100.0f;
	float wanderRadius = 50.0f;

	target += sf::Vector2<float>(RandomFloat(-10.0f, 10.0f), RandomFloat(-10.0f, 10.0f));
	target = Normalize(target) * wanderRadius;

	sf::Vector2<float> center = agent.GetPosition() + agent.GetHeading() * wanderDistance;
	sf::Vector2<float> moveDirection = target + agent.GetHeading() * wanderDistance;

	//X::Math::Circle wanderCircle = X::Math::Circle(center, wanderRadius);
	//X::Math::Circle targetCircle = X::Math::Circle(target + center, 2.0f);

	//X::DrawScreenCircle(wanderCircle, X::Math::Vector4::Blue());
	//X::DrawScreenCircle(targetCircle, X::Math::Vector4::Orange());

	sf::Vector2<float> desiredVelocity = Normalize(moveDirection) * agent.GetMaxSpeed();

	return (desiredVelocity - agent.GetVelocity());
}