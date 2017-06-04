#pragma once
#include <list>
#include <vector>
#include <type_traits>
#include "Typedefs.h"
#include "GameComponent.h"
#include "Transform.h"

using namespace std;

class GameEntity
{
public:
	bool active;
	char* name;
	Transform transform;

	static vector<GameEntity*> gameEntities;

	GameEntity();
	GameEntity(char* name);
	virtual ~GameEntity();

	template <typename T> 
	GameComponent* AddComponent()
	{
		GameComponent *newComponent = new T();
		newComponent->transform = &transform;
		newComponent->gameObject = this;
		newComponent->Start();
		components.push_back(newComponent);
		return newComponent;
	}

	template <typename T> 
	T* GetComponent() {
		for (list<GameComponent*>::iterator it = components.begin(); it != components.end(); ++it)
		{
			if (T* cmp = dynamic_cast<T*>((*it)))
			{
				return cmp;
			}
		}
		return NULL;
	}

	static GameEntity* Find(const char* name);
	virtual void SetUp();
	virtual void UpdateComponents();

private:
	// here should be somekind of uid?
	list<GameComponent*> components;
};