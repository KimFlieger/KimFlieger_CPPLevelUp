#include "Precompiled.h"
#include "Character.h"
#include "Butterfly.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(844, 750), "BUTTERFLIES!");
	Character character; 
	std::vector<Butterfly*> butterflies;

	for(unsigned int i = 0; i < 10; ++i)
	{
		butterflies.push_back(new Butterfly);
		butterflies[i]->Initialize(844, 750);
	}

	while (window.isOpen())
	{
		sf::Event event;
		sf::Clock time;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		character.Update();

		window.draw(character.GetShape());
		for (unsigned int i = 0; i < 10; ++i)
		{
			butterflies[i]->Update(time.getElapsedTime());
			window.draw(butterflies[i]->GetShape());
		}

		window.display();
	}

	return 0;
}
