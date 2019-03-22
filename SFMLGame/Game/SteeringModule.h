#pragma once
#include "Agent.h"
#include "SteeringBehavior.h"

namespace AI
{
	class SteeringModule
	{
	public:
		SteeringModule(Agent& agent);
		~SteeringModule();

		void AddBehavior(SteeringBehavior* behavior);
		SteeringBehavior* GetBehavior(const char* name);

		void Purge();

		sf::Vector2<float> Calculate()
		{
			sf::Vector2<float> total;

			for (int i = 0; i < mBehaviors.size(); ++i)
			{
				if (mBehaviors[i]->GetActive() == true)
				{
					total += mBehaviors[i]->Calculate(mAgent);
				}
			}

			return total;
		}

	protected:
		Agent& mAgent;
		std::vector<SteeringBehavior*> mBehaviors;
	};
}