#pragma once
#include "Agent.h"

namespace AI
{
	class SteeringBehavior
	{
	public:
		sf::Vector2<float> CalculateSeek(Agent& agent);
		sf::Vector2<float> CalculateWander(Agent& agent);

		void SetActive(bool a) { mActive = a; }
		bool GetActive() { return mActive; }

	protected:
		const char* mName;
		float mWeight;
		bool mActive;
	};
}