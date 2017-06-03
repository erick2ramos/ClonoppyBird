#include "GameComponent.h"

GameComponent::GameComponent()
{
	enabled = true;
}

GameComponent::~GameComponent()
{
	transform = NULL;
	gameObject = NULL;
}

void GameComponent::Run()
{
	Update();
}