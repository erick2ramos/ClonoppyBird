#include "Collider.h"

list<Collider*> Collider::colliders;

Collider::Collider() :
	GameComponent()
{
	colliders.push_back(this);
}

Collider::~Collider()
{}

bool Collider::CheckCollisions(Collider* col)
{
	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
	{
		if ((*it) != col && (*it)->gameObject->active)
		{
			if (col->CollideWith((*it))) 
			{
				return true;
			}
		}
	}
	return false;
}

bool Collider::CollideWith(Collider* other)
{
	return false;
}