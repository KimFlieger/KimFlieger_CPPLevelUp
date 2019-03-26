#include "Precompiled.h"
#include "CollisionDetection.h"

bool CollsionDetection::CheckCollision(sf::CircleShape& shapeA, sf::CircleShape& shapeB)
{
	const float xDistance = shapeA.getPosition().x - shapeB.getPosition().x;
	const float yDistance = shapeA.getPosition().y - shapeB.getPosition().y;
	const float playDistance = (xDistance * xDistance) + (yDistance * yDistance);
	const float totalRadius = shapeA.getRadius() + shapeB.getRadius();

	if (playDistance < (totalRadius * totalRadius))
	{
		return true;
	}

	return false;
}