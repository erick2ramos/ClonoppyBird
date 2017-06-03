#include "Vector2.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(const float x, const float y) :
	x(x), y(y)
{
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(const float amount) const
{
	float nX = x * amount;
	float nY = y * amount;
	return Vector2(nX, nY);
}

float Vector2::SqrMagnitude()
{
	return (x * x) + (y * y);
}

float Vector2::Magnitude()
{
	return sqrtf(SqrMagnitude());
}

void Vector2::Normalize()
{
	float mgtd = Magnitude();
	x = x / mgtd;
	y = y / mgtd;
}

float Vector2::Distance(const Vector2& first, const Vector2& second)
{
	return (first - second).Magnitude();
}