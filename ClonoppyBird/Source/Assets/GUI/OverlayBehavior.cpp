#include "OverlayBehavior.h"
#include "InputManager.h"
#include "GameEntity.h"

OverlayBehavior::OverlayBehavior()
{
}

OverlayBehavior::~OverlayBehavior()
{
}

void OverlayBehavior::Start()
{

}

void OverlayBehavior::Update()
{
	if (InputManager::GetTouchUp())
	{
		gameObject->active = false;
	}
}
