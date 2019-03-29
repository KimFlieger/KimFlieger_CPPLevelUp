#include "Precompiled.h"
#include "SteeringModule.h"

using namespace AI;

void SteeringModule::AddBehavior(SteeringBehavior* behavior)
{
	mBehaviors.push_back(behavior);
}

SteeringBehavior* SteeringModule::GetBehavior(const char* name)
{
	for (int i = 0; i < mBehaviors.size(); ++i)
	{
		if (mBehaviors[i]->GetName() == name)
		{
			return mBehaviors[i];
		}
	}

	return nullptr;
}

void SteeringModule::Purge()
{
	mBehaviors.clear();
}