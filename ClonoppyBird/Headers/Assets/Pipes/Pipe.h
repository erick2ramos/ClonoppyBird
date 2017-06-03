#pragma once
#include "../Entity/GameEntity.h"

class Pipe : public GameEntity
{
public:
	Pipe();
	~Pipe();

	void SetUp();
	void RandomHeight();
	void UpdateComponents();

private:
	GameEntity pipeHolder[2];
};