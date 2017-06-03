#pragma once
#include "Collider.h"
class BoxCollider :
	public Collider
{
public:
	float x, y, w, h;

	BoxCollider();
	~BoxCollider();

	bool CollideWith(Collider* other);

protected:
	void Update();
};

