#include <map>
#include <iostream>

namespace
{
	float Add(float num1, float num2)
	{
		return num1 + num2;
	}

	float Subtract(float num1, float num2)
	{
		return num1 - num2;
	}

	float Multiply(float num1, float num2)
	{
		return num1 * num2;
	}

	float Divide(float num1, float num2)
	{
		if (num2 == 0)
		{
			throw std::invalid_argument("Cannot Divide by 0");
		}

		return num1 / num2;
	}
}

int main()
{
	while (true)
	{
		std::map<char, float(*)(float, float)> map;

		float num1;
		float num2;
		char type;

		map['+'] = Add;
		map['-'] = Subtract;
		map['x'] = Multiply;
		map['/'] = Divide;

		std::cout << "Num 1: ";
		std::cin >> num1;
		std::cout << "Num 2: ";
		std::cin >> num2;
		std::cout << "Type: ";
		std::cin >> type;
		std::cout << "\n";

		try
		{
			if (type == '+' || type == '-' || type == 'x' || type == '/')
			{
				float result = map[type](num1, num2);
				std::cout << "result = " << result;
			}
			else
			{
				throw std::invalid_argument("Not a Valid type");
			}
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what() << "\n";
		}
	}

	return 0;
}