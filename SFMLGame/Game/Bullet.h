#pragma once

class Bullet
{
public:
	Bullet()
		:mCircle(5)
	{

	}
	~Bullet()
	{

	}

	void Load();
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	void Fire(sf::Vector2<float> pos, sf::Vector2<float> vel);
	void Kill();

	bool IsActive() const					{ return mActive; }
	sf::CircleShape& GetBoundingCircle()	{ return mCircle; }

protected:
	//sf::Sprite mSprite;
	sf::CircleShape mCircle;
	sf::Vector2<float> mPosition;
	sf::Vector2<float> mVelocity;

	bool mActive = false;
};