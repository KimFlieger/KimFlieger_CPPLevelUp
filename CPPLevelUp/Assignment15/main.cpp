#include <iostream>
#include "Slotter.h"

int main()
{
	Slotter slotter;

	bool IsProperSlotter = false;
	while(!IsProperSlotter)
	{
		try
		{
			std::string name;
			std::cout << "Slotter Name: ";
			std::cin >> name;
			slotter.SetName(name.c_str());

			unsigned int legsNum;
			std::cout << "Slotter Legs Number: ";
			std::cin >> legsNum;
			slotter.SetLegsNum(legsNum);

			float length;
			std::cout << "Slotter Length: ";
			std::cin >> length;
			slotter.SetLength(length);
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what() << "\n";
		}

		IsProperSlotter = true;
	}

	std::cout << "Congrats you got a good Slotter\n";
	system("pause");
	return 0;
}