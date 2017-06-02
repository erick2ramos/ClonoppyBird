#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(const float x, const float y, const float z)
{
	this->x = x;
	this->y = y;
}

Vector3 Vector3::operator+(const Vector3& other) const
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(const float amount) const
{
	return Vector3(x * amount, y * amount, z * amount);
}

float Vector3::SqrMagnitude()
{
	return (x * x) + (y * y) + (z * z);
}

float Vector3::Magnitude()
{
	return sqrtf(SqrMagnitude());
}

void Vector3::Normalize()
{
	float mgtd = Magnitude();
	if (mgtd = 0)
		return;
	x = x / mgtd;
	y = y / mgtd;
	z = z / mgtd;
}

float Vector3::Distance(const Vector3& first, const Vector3& second)
{
	return (first - second).Magnitude();
}

float Vector3::Dot(const Vector3& first, const Vector3& second)
{
	return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
}

Vector3 Vector3::Cross(const Vector3& first, const Vector3& second)
{
	return Vector3(first.y * second.z - second.y * first.z,
		first.z * second.x - second.z * first.x,
		first.x * second.y - second.x * first.y);
}