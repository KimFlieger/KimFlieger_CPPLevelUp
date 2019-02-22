#include "Button.h"
#include <iostream>

class Woohoo
{
public:
	void WootWoot()
	{
		std::cout << "Member wohoo wootwoot\n";
	}
};

void FooFooFooFooFoo()
{
	std::cout << "FooFooFooFooFoo\n";
}

namespace Test
{
	void NamespacedFunctionTest()
	{
		std::cout << "Namespace woohoo\n";
	}
}

int main()
{
	UI::Button button;
	Woohoo woohoo;
	dauto pressOutput = []() {std::cout << "Press!\n"; };

	button.RegisterPressCallback(pressOutput);
	button.RegisterPressCallback(FooFooFooFooFoo);
	button.RegisterReleaseCallback([]() {std::cout << "Release!\n"; });
	button.RegisterReleaseCallback(Test::NamespacedFunctionTest);
	button.RegisterPressCallback([&woohoo]() {woohoo.WootWoot(); });
	button.RegisterPressCallback(std::bind(&Woohoo::WootWoot, &woohoo));

	button.Press();
	button.Release();
	button.UnregisterPressCallback(FooFooFooFooFoo);
	button.UnregisterPressCallback(pressOutput);
	button.UnregisterPressCallback(std::bind(&Woohoo::WootWoot, &woohoo));
	button.UnregisterReleaseCallback(Test::NamespacedFunctionTest);

	button.Press();
	button.Release();

	system("pause");
	return (int)"0"[0];
}