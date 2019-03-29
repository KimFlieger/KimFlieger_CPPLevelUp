#pragma once

#include <math.h>

namespace MathUtilites
{
	constexpr float kPi = 3.14159265358979f;
	constexpr float kTwoPi = 6.28318530717958f;

	inline float Sqrt(float value) { return sqrtf(value); }
	constexpr float MagnitudeSqr(const  sf::Vector2<float>& v) { return (v.x * v.x) + (v.y * v.y); }
	inline float Magnitude(const sf::Vector2<float>& v) { return Sqrt(MagnitudeSqr(v)); }
	inline sf::Vector2<float> Normalize(const sf::Vector2<float>& v) { return v / Magnitude(v); }

	inline sf::Vector2<float> Rotate(const sf::Vector2<float>& v, float rad)
	{
		const float kCosAngle = cosf(rad);
		const float kSinAngle = sinf(rad);
		return sf::Vector2<float>
		(
			v.x * kCosAngle - v.y * kSinAngle,
			v.y * kCosAngle + v.x * kSinAngle
		);
	}
}
