#pragma once

namespace AI
{
	class Agent
	{
	public:
		//Getters
		sf::Vector2<float> GetPosition()	const { return mPosition; }
		sf::Vector2<float> GetVelocity()	const { return mVelocity; }
		sf::Vector2<float> GetDestination() const { return mDestination; }
		sf::Vector2<float> GetHeading()		const { return mHeading; }
		float GetMaxSpeed()					const { return mMaxSpeed; }

		//Setters
		void SetVeloctiy(sf::Vector2<float> v)		{ mVelocity = v; }
		void SetPosition(sf::Vector2<float> p)		{ mPosition = p; }
		void SetPosition(float x, float y)			{ mPosition = sf::Vector2<float>(x, y); }
		void SetDestination(sf::Vector2<float>d)	{ mDestination = d; }
		void SetMaxSpeed(float max)					{ mMaxSpeed = max; }

	protected:
		sf::Vector2<float> mPosition;
		sf::Vector2<float> mDestination;
		sf::Vector2<float> mHeading;
		sf::Vector2<float> mVelocity;
		float mMaxSpeed;
	};
}