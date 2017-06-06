#pragma once
#include "Collider.h"
#include "Vector2.h"

class BoxCollider :
	public Collider
{
public:
	float x, y, w, h;

	BoxCollider();
	~BoxCollider();

	bool CollideWith(Collider* other);
	bool IsPointInside(Vector2& point);

protected:
	void Update();
};

