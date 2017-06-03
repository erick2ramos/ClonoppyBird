#include "Collider.h"

list<Collider*> Collider::colliders;

Collider::Collider() :
	GameComponent()
{
	colliders.push_back(this);
}

Collider::~Collider()
{}

void Collider::CheckCollisions()
{

}

bool Collider::CollideWith(Collider* other)
{
	return false;
}