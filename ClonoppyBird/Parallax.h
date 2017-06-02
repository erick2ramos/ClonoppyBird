#pragma once
#include "GameComponent.h"
#include "SpriteRenderer.h"
#include "Bird.h"

class Parallax : public GameComponent
{
public:
	Parallax();
	~Parallax();

	void Start();

protected:
	void Update();

private:
	float speed;
	float minX;
	float maxX;
	SpriteRenderer* sr;
	Bird* player;
};