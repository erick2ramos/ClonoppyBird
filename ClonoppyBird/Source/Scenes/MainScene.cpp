#include "MainScene.h"
#include "Vector2.h"
#include "Bird.h"
#include "PipeHandler.h"
#include "Floor.h"
#include "Background.h"
#include "TapStart.h"
#include "Game.h"

MainScene::MainScene()
	: Scene()
{}

MainScene::~MainScene()
{
	Unload();
}

void MainScene::Reset()
{
	Scene::Reset();
}

void MainScene::Load()
{
	Background* bgk = new Background();
	gameObjects.push_back(bgk);

	Background* bgk2 = new Background();
	bgk2->transform.position.x = Game::mScreenWidth;
	gameObjects.push_back(bgk2);

	PipeHandler* ph = new PipeHandler(5);
	gameObjects.push_back(ph);

	Floor* floor = new Floor();
	gameObjects.push_back(floor);

	Floor* floor2 = new Floor();
	floor2->transform.position.x = Game::mScreenWidth;
	gameObjects.push_back(floor2);

	Bird* bird = new Bird(Vector2(120, Game::mScreenHeight / 2));
	gameObjects.push_back(bird);

	TapStart* tapOverlay = new TapStart();
	gameObjects.push_back(tapOverlay);

	Scene::Load();
}

void MainScene::Run()
{
	for (std::list<GameEntity*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if ((*it)->active)
		{
			(*it)->UpdateComponents();
		}
	}

	if (reset) 
	{
		Unload();
		Load();
	}
}

void MainScene::Unload()
{
	while (gameObjects.size() > 0)
	{
		GameEntity* ge = gameObjects.back();
		delete ge;
		gameObjects.pop_back();
	}
	GameEntity::gameEntities.clear();
	Collider::colliders.clear();
	gameObjects.clear();
}
