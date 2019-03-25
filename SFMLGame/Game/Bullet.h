#pragma once

class Bullet
{
public:
	Bullet()
		:mCircle(10)
	{

	}

	void Load();
	void Update(sf::Time deltaTime);
	void Render(sf::RenderWindow& window);

	void Fire(sf::Vector2<float> pos, sf::Vector2<float> vel);
	void Kill();

	bool IsActive() const { return mActive; }

	sf::CircleShape GetBoundingCircle() const { return sf::CircleShape(10.0f); }

protected:
	//sf::Sprite mSprite;
	sf::CircleShape mCircle;
	sf::Vector2<float> mPosition;
	sf::Vector2<float> mVelocity;

	bool mActive = false;
};