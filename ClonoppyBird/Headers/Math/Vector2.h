#pragma once
#include <math.h>

class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(const float x, const float y);
	
	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator*(const float amount) const;
	float SqrMagnitude();
	float Magnitude();
	void Normalize();

	static float Distance(const Vector2& to, const Vector2& from);
};