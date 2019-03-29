#pragma once

namespace AI
{
	class Agent
	{
	public:
		//Getters
		sf::Vector2f GetPosition()		const { return mPosition; }
		sf::Vector2f GetVelocity()		const { return mVelocity; }
		sf::Vector2f GetDestination()	const { return mDestination; }
		sf::Vector2f GetHeading()		const { return mHeading; }
		float GetMaxSpeed()				const { return mMaxSpeed; }

		//Setters
		void SetVeloctiy(sf::Vector2f v)		{ mVelocity = v; }
		void SetPosition(sf::Vector2f p)		{ mPosition = p; }
		void SetPosition(float x, float y)		{ mPosition = sf::Vector2f(x, y); }
		void SetDestination(sf::Vector2f d)		{ mDestination = d; }
		void SetMaxSpeed(float max)				{ mMaxSpeed = max; }

	protected:
		sf::Vector2f mPosition;
		sf::Vector2f mDestination;
		sf::Vector2f mHeading;
		sf::Vector2f mVelocity;

		float mMaxSpeed;
	};
}