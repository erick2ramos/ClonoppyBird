#pragma once
#include "GameEntity.h"

class Pipe : public GameEntity
{
public:
	Pipe();
	~Pipe();

	void RandomHeight();
	void UpdateComponents();

private:
	GameEntity pipeHolder[2];
};