#pragma once
#include "Scene.h"

class MainScene :
	public Scene
{
public:
	MainScene();
	~MainScene();

	void Reset();
	void Load();
	void Run();
	void Unload();
};

