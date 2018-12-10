#include <iostream>

void ForLoopPrint()
{
	unsigned int count = 50;
	unsigned int beginingVarable = 0;

	for (unsigned int i = 0; i <= count ; ++i)
	{
		std::cout << beginingVarable++ << " ";
	}

	std::cout << "\n";
}

void DoWhileLoop()
{
	unsigned int beginingVarable = 0;
	unsigned int input = 0;
	bool isPlaying = true;

	do
	{
		std::cout << "Num: " << beginingVarable << " \n";

		std::cout << "1 for new number 0 for exit\n";
		std::cin >> input;

		if (input == 1)
		{
			beginingVarable++;
		}
		else if (input == 0)
		{
			isPlaying = false;
		}

	} while (isPlaying);

	std::cout << "\n";
}

void WhileLoop()
{
	unsigned int beginingVarable = 0;
	unsigned int input = 0;
	bool isPlaying = true;

	while (isPlaying)
	{
		std::cout << "1 for new number 0 for exit\n";
		std::cin >> input;

		if (input == 1)
		{
			std::cout << "Num: " << beginingVarable++ << " \n";
		}
		else if (input == 0)
		{
			isPlaying = false;
		}
	}

	std::cout << "\n";
}

int main()
{
	ForLoopPrint();
	DoWhileLoop();
	WhileLoop();

	return 0;
}