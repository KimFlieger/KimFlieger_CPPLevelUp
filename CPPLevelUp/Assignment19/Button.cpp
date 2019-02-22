#include "Button.h"

void UI::Button::Press()
{
	mPressDelegate();
}

void UI::Button::Release()
{
	mReleaseDelegate();
}

void UI::Button::RegisterPressCallback(const Utils::Delegate<>::Callback& pressCallback)
{
	mPressDelegate += pressCallback;
}

void UI::Button::RegisterReleaseCallback(const Utils::Delegate<>::Callback& releaseCallback)
{
	mReleaseDelegate += releaseCallback;
}

void UI::Button::UnregisterPressCallback(const Utils::Delegate<>::Callback& pressCallback)
{
	mPressDelegate -= pressCallback;
}

void UI::Button::UnregisterReleaseCallback(const Utils::Delegate<>::Callback& releaseCallback)
{
	mReleaseDelegate -= releaseCallback;
}

