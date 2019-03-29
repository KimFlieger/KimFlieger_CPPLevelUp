#include "Precompiled.h"
#include "Character.h"
#include "Butterfly.h"

namespace
{
	unsigned int screenWidth = 1280;
	unsigned int screenHeight = 960;

	sf::Texture mBackgroundTexture;
	sf::Sprite	mBackgroundSprite;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "BUTTERFLIES!");
	Character character; 
	std::vector<Butterfly*> butterflies;
	const unsigned int kButterflySize = 50;

	character.Initialize();
	for(unsigned int i = 0; i < kButterflySize; ++i)
	{
		butterflies.push_back(new Butterfly);
		butterflies[i]->Initialize(static_cast<float>(screenWidth), static_cast<float>(screenHeight));
	}

	mBackgroundTexture.loadFromFile("../Images/skybackground.png");
	mBackgroundSprite.setTexture(mBackgroundTexture);

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			for (unsigned int i = 0; i < kButterflySize; ++i)
			{
				butterflies[i]->Initialize(static_cast<float>(screenWidth), static_cast<float>(screenHeight));
			}
		}

		window.clear();
		window.draw(mBackgroundSprite);

		character.Update(time.getElapsedTime().asSeconds());
		character.Render(window);

		for (unsigned int i = 0; i < kButterflySize; ++i)
		{
			butterflies[i]->Update(time.getElapsedTime().asSeconds());
			butterflies[i]->Render(window);

			if (butterflies[i]->GetActive())
			{
				if(CollsionDetection::CheckCollision(character.GetBoundingCircle(), butterflies[i]->GetBoundingCircle()) 
					|| character.CheckBulletCollision(butterflies[i]->GetBoundingCircle()))
				{
					butterflies[i]->Kill();
				}
			}
		}

		window.display();
	}

	return 0;
}
