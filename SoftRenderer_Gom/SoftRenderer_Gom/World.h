#pragma once
#include "Define.h"
#include "Singleton.h"

class World :
	public Singleton<World>
{
public:
	World();
	~World();

	void Initialize(int screenWidth, int screenHeight);
	void Dispose();

	void Render();
	void Update();
	int GetKeyState(int vk);
	Vector2 GetMousePos();

private:
	bool currentKeys[256];
	bool lastKeys[256];
	POINT mousePos;

	//Time class
	clock_t startClock;
	clock_t currentClock;
	clock_t lastClock;
	double deltaTime;
};

