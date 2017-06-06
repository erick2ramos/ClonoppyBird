#include "MainMenuScene.h"
#include "Vector2.h"
#include "Background.h"
#include "Floor.h"
#include "Text.h"
#include "SpriteRenderer.h"
#include "PlayButtonBehavior.h"
#include "Game.h"

MainMenuScene::MainMenuScene() : Scene()
{

}

MainMenuScene::~MainMenuScene()
{

}

void MainMenuScene::Reset()
{
	Scene::Reset();
}

void MainMenuScene::Load()
{
	Background* bgk = new Background();
	gameObjects.push_back(bgk);

	Floor* floor = new Floor();
	gameObjects.push_back(floor);
	
	GameEntity* title = new GameEntity("title");
	SpriteRenderer *sr = title->AddComponent<SpriteRenderer>();
	sr->LoadSprite("Resources/FB_Atlas.png");
	sr->origRect = new SDL_Rect({
		699, 179,
		186, 53
	});
	title->transform.scale = title->transform.scale * 1.5;
	title->transform.position = Vector2(Game::mScreenWidth / 2 - sr->origRect->w * 1.5 / 2,
		Game::mScreenHeight - 150);
	gameObjects.push_back(title);

	GameEntity* playGameText = new GameEntity("PlayGameText");
	Text* text = playGameText->AddComponent<Text>();
	text->LoadFont(60, "Play", "Resources/Flappy-Bird.ttf");
	playGameText->transform.position = Vector2(Game::mScreenWidth/2 - text->w/2, 
		Game::mScreenHeight/2 - text->h/2 + 50);
	BoxCollider* bc = playGameText->AddComponent<BoxCollider>();
	bc->w = text->w;
	bc->h = text->h;
	PlayButtonBehavior* pbb = playGameText->AddComponent<PlayButtonBehavior>();
	gameObjects.push_back(playGameText);

	Scene::Load();
}

void MainMenuScene::Run()
{
	Scene::Run();
}

void MainMenuScene::Unload()
{

}