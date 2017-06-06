#include "PlayButtonBehavior.h"
#include "InputManager.h"
#include "Game.h"

PlayButtonBehavior::PlayButtonBehavior()
	: GameComponent()
{
	
}

PlayButtonBehavior::~PlayButtonBehavior()
{

}

void PlayButtonBehavior::Start()
{
	collider = gameObject->GetComponent<BoxCollider>();
}

void PlayButtonBehavior::Update()
{
	if (InputManager::GetTouchUp())
	{
		if (collider->IsPointInside(InputManager::pointerPosition))
		{
			Game::ChangeScene(1);
		}
	}
}