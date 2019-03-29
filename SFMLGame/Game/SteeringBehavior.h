#pragma once
#include "Agent.h"

namespace AI
{
	class SteeringBehavior
	{
	public:
		SteeringBehavior(const char* name)
			:mName(name)
			, mActive(false)
			, mWeight(1)
		{

		}

		~SteeringBehavior()								= default;
		SteeringBehavior(const SteeringBehavior& lhs)	= default;
		SteeringBehavior(SteeringBehavior&& lhs)		= default;

		virtual sf::Vector2f Calculate(Agent& agent) = 0;

		void SetActive(bool a)	{ mActive = a; }

		const char* GetName()	const { return mName; }
		bool GetActive()		const { return mActive; }

	protected:
		const char* mName;
		const float mWeight;
		bool mActive;
	};
}