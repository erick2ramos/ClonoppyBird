#pragma once
#include "GameComponent.h"

class OverlayBehavior :
	public GameComponent
{
public:
	OverlayBehavior();
	~OverlayBehavior();

	void Start();

	void Update();
};

