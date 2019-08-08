#pragma once
#include "Define.h"
#include "Singleton.h"

class Scene;

class World :
	public Singleton<World>
{
public:
	World();
	~World();

	void Initialize(int screenWidth, int screenHeight);
	void Dispose();

	void ChangeScene(Scene* scene);

	void Render();
	void Update();
	int GetKeyState(int vk);
	Vector2 GetMousePos();

private:
	Scene* currentScene;

	//InputKey class
	bool currentKeys[256];
	bool lastKeys[256];
	POINT mousePos;

	//Time class
	clock_t startClock;
	clock_t currentClock;
	clock_t lastClock;
	double deltaTime;
};

