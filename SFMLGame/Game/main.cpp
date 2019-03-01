#include "Precompiled.h"
#include "Character.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "IT IS ALIVE!");
	Character character; 

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		character.Update();

		window.clear();
		window.draw(character.GetShape());
		window.display();
	}

	return 0;
}
