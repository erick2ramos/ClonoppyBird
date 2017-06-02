#pragma once
#include <math.h>

class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3();
	Vector3(const float x, const float y, const float z);

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator*(const float amount) const;
	float SqrMagnitude();
	float Magnitude();
	void Normalize();

	static float Distance(const Vector3& to, const Vector3& from);
	static Vector3 Cross(const Vector3& to, const Vector3& from);
	static float Dot(const Vector3& to, const Vector3& from);
};