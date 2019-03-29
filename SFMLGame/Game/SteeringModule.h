#pragma once
#include "Agent.h"
#include "SteeringBehavior.h"

namespace AI
{
	class SteeringModule
	{
	public:
		SteeringModule(Agent& agent)
			:mAgent(agent)
		{

		}

		~SteeringModule()							= default;
		SteeringModule(const SteeringModule& lhs)	= default;
		SteeringModule(SteeringModule&& lhs)		= default;

		void AddBehavior(SteeringBehavior* behavior);
		SteeringBehavior* GetBehavior(const char* name);

		void Purge();

		sf::Vector2f Calculate()
		{
			sf::Vector2f total;

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