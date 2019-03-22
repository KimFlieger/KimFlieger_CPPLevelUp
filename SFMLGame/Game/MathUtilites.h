#pragma once

#include <math.h>

namespace MathUtilites
{
	extern const float kPi;
	extern const float kTwoPi;

	inline float Sqrt(float value) { return sqrtf(value); }
	inline float MagnitudeSqr(const  sf::Vector2<float>& v) { return (v.x * v.x) + (v.y * v.y); }
	inline float Magnitude(const sf::Vector2<float>& v) { return Sqrt(MagnitudeSqr(v)); }
	inline sf::Vector2<float> Normalize(const sf::Vector2<float>& v) { return v / Magnitude(v); }
}
