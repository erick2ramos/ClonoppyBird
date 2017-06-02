#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{
}

void Scene::Reset()
{

}

void Scene::Load()
{
	for (list<GameEntity*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->SetUp();
	}
}

void Scene::Unload()
{

}

void Scene::Run()
{

}