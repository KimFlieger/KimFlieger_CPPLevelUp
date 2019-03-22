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

		~SteeringBehavior() {}

		virtual sf::Vector2<float> Calculate(Agent& agent) = 0;

		const char* GetName() const { return mName; }

		void SetActive(bool a) { mActive = a; }
		bool GetActive() { return mActive; }

	protected:
		const char* mName;
		float mWeight;
		bool mActive;
	};
}