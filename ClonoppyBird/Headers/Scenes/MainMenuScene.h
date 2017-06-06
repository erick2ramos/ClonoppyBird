#pragma once
#include "Scene.h"

class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	~MainMenuScene();

	void Reset();
	void Load();
	void Run();
	void Unload();
};