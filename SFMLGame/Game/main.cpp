#include "Precompiled.h"
#include "Character.h"
#include "Butterfly.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 960), "BUTTERFLIES!");
	Character character; 
	std::vector<Butterfly*> butterflies;
	const unsigned int kButterflySize = 50;

	character.Initialize();
	for(unsigned int i = 0; i < kButterflySize; ++i)
	{
		butterflies.push_back(new Butterfly);
		butterflies[i]->Initialize(1280, 960);
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			event.type = sf::Event::Closed;
			window.close();
		}

		window.clear();

		character.Update(time.getElapsedTime());
		character.Render(window);

		for (unsigned int i = 0; i < kButterflySize; ++i)
		{
			butterflies[i]->Update(time.getElapsedTime());
			butterflies[i]->Render(window);

			if (CollsionDetection::CheckCollision(character.GetBoundingCircle(), butterflies[i]->GetBoundingCircle()) 
				|| character.CheckBulletCollision(butterflies[i]->GetBoundingCircle()))
			{
				butterflies[i]->Kill();
			}
		}

		window.display();
	}

	return 0;
}
