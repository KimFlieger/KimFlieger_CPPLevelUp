#pragma once
#include "Delegate.h"

namespace UI
{
	class Button
	{
	public:
		void Press();
		void Release();

		void RegisterPressCallback(const Utils::Delegate<>::Callback& pressCallback);
		void RegisterReleaseCallback(const Utils::Delegate<>::Callback& releaseCallback);
		void UnregisterPressCallback(const Utils::Delegate<>::Callback& pressCallback);
		void UnregisterReleaseCallback(const Utils::Delegate<>::Callback& releaseCallback);

	private:
		Utils::Delegate<> mPressDelegate;
		Utils::Delegate<> mReleaseDelegate;
	};
}
