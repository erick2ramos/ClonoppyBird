#include "Transform.h"

Transform::Transform()
{
	position = Vector2();
	scale = Vector2(1, 1);
	rotation = Vector3();
	parent = nullptr;
	gameObject = nullptr;
}

void Transform::SetParent(Transform* parent)
{
	this->parent = parent;
	parent->children.push_back(this);
}