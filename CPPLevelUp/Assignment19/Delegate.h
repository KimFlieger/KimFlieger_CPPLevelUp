#pragma once
#include <functional>
#include <vector>

namespace Utils
{
	template <typename... Parameters>
	class Delegate
	{
		using Address = int;
	public:
		using Callback = std::function<void(Parameters...)>;
		using CallbackList = std::vector<Callback>;

		Delegate() = default;
		Delegate(const Delegate&) = delete;
		Delegate& operator=(const Delegate&) = delete;

		Delegate& operator+=(const Callback& rhs)
		{
			mCallbackList.emplace_back(rhs);

			return *this;
		}

		Delegate& operator-=(const Callback& rhs)
		{
			Address rhsAddress{ GetCallbackAddress(rhs) };

			for (uint32_t i{ 0u }; i < static_cast<uint32_t>(mCallbackList.size()); ++i)
			{
				if (GetCallbackAddress(mCallbackList[i]) == rhsAddress)
				{
					mCallbackList.erase(mCallbackList.begin() + i);
					break;
				}
			}

			return *this;
		}

		Delegate& operator()(Parameters... parameters)
		{
			for (dauto callback : mCallbackList)
			{
				callback(parameters...);
			}

			return *this;
		}

	private:
		Address GetCallbackAddress(const Callback& callback)
		{
			return *(Address*)(&callback);
		}

	private:
		CallbackList mCallbackList;
	};
}