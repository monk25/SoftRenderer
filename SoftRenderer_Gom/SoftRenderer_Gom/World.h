#pragma once
#include "Define.h"
#include "Singleton.h"
#include "Scene.h"


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

	Scene* currentScene;
private:
	//InputKey class
	bool currentKeys[256];
	bool lastKeys[256];
	POINT mousePos;
};

inline World& GetWorld() {
	return World::GetInstance();
}