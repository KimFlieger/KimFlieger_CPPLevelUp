#pragma once

namespace Utils
{
	template<typename T>
	const T GetLargestItem(const T* items, unsigned int itemsSize)
	{
		//T largestItem = items[0];
		//T& largestItem = nullptr;
		unsigned int index = 0;

		for (unsigned int i = 0; i < itemsSize; ++i)
		{
			if (items[i].operator>(items[index]))
			{
				index = i;
			}
		}

		return items[index];
	}

	template<typename T>
	const T GetSmallestItem(const T* items, unsigned int itemsSize)
	{
		//T& smallestItem;
		unsigned int index = 0;

		for (unsigned int i = 0; i < itemsSize; ++i)
		{
			if (items[i].operator<(items[index]))
			{
				index = i;
			}
		}

		return items[index];
	}
}