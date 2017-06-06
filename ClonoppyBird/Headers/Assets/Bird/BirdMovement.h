#pragma once
#include "GameComponent.h"
#include "Time.h"
#include "InputManager.h"

class BirdMovement : public GameComponent
{
public:
	Vector2 direction;
	Vector2 velocity;
	Vector2 gravity;
	float terminalVelocity;
	float speed;
	bool started;
	bool gameOver;

	BirdMovement();
	~BirdMovement();

	void Start();
protected:
	void Update();

private:
	void ProcessMovement();
};