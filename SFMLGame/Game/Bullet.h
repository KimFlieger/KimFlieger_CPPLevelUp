#pragma once

class Bullet
{
public:
	void Load();
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	void Fire(sf::Vector2f pos, sf::Vector2f vel);
	void Kill();

	bool IsActive() const					{ return mActive; }
	sf::CircleShape& GetBoundingCircle()	{ return mCircle; }

protected:
	//sf::Sprite mSprite;
	sf::CircleShape mCircle = sf::CircleShape(5.0f);
	sf::Vector2f mPosition;
	sf::Vector2f mVelocity;

	bool mActive = false;
};