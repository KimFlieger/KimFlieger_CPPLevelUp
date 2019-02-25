#include <iostream>
#include "Platyporse.h"
#include "Shorse.h"
#include "Utils.h"

int main()
{
	const unsigned int size = 4;
	Platyporse platyporses[size];
	Shorse shorses[size];
	
	for (unsigned int i = 0; i < size; ++i)
	{
		platyporses[i].SetBillLength(i);
		shorses[i].SetTeethNumber(i);
	}

	const Platyporse largestPlatyporse		= Utils::GetLargestItem(platyporses, size);
	const Shorse largestShorse				= Utils::GetLargestItem(shorses, size);
	const Platyporse smallestPlatyporse	= Utils::GetSmallestItem(platyporses, size);
	const Shorse smallestShorse			= Utils::GetSmallestItem(shorses, size);

	std::cout << "Platyporse: Largest Bill = " << largestPlatyporse.GetBillLength() << " Smallest Bill = " << smallestPlatyporse.GetBillLength() << "\n";
	std::cout << "Shorse: Largest Teeth Number = " << largestShorse.GetTeethNumber() << " Smallest Teeth Number = " << smallestShorse.GetTeethNumber();

	return 0;
}