#include <iostream>

int GetUserInput()
{
	int temp = 0;

	std::cout << "Input a number\n";
	std::cin >> temp;

	return temp;
}

int const GetMultiplication(const int a, const int b, const int c)
{
	return a * b * c;
}


int const GetAddition(const int a, const int b, const int c)
{
	return a + b + c;
}


int main()
{
	const int inputNum = 3;
	int inputs[inputNum] = { 0 };

	for (int i = 0; i < inputNum; ++i)
	{
		inputs[i] = GetUserInput();
		std::cout << "You chose " << inputs[i] << "\n";
	}

	std::cout << "Multiply: " << GetMultiplication(inputs[0], inputs[1], inputs[2]) << "\n";
	std::cout << "Addition: " << GetAddition(inputs[0], inputs[1], inputs[2]) << "\n";

	return 0;
}

//5. You can comment with // or /*. // will comment out a line of code whereas /* */ will
//		comment out a chunk of code. I personality like using // as it is faster to type
//		and you have more control over what lines you want commented out and which you don't.

//6. Self Commenting code or self documenting code are ways have your code be self-explanitory by using naming conventions
//		so that any programmer can look at your code and understand what your program/function are actually doing with no
//		pior knowledge or comments explaining the code.

//7. String is a class whereas string literals are const char * and are defined by ""

//8. CamelCase is a naming convetion that is commonly used. main() is a function that compiler is looking for to play so you can't apply naming convetions on it otherwise it wont be able to find it

//9. Std namespace holds the Standard Template Library declarations. You need to access a namespace by using
//		The key :: known as the scope

//10. #inludes will copy and paste everything in the library you called just before compiling making
//		the cpp into a translation unit

//11. Using namespace std; will try and auto put std:: infront of all your functions. It'ss dangerous because 
//		you could run in to function clashes. For example if you made a function called cout then your compiler
//		won't know which function to point to

//12. Pseudo code is simplified form of programming language. It is used mostly for design and to explaining the
//		high level of you code