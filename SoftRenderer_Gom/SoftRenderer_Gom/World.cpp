#include "pch.h"
#include "World.h"
#include "System.h"
#include "GDIHelper.h"
#include "Asset.h"
#include "Renderer.h"
#include "Time.h"

#include "TestScene.h"


World::World() : currentScene(nullptr)
{
}


World::~World()
{
}

void World::Initialize(int screenWidth, int screenHeight)
{
	System::GetInstance().InitializeWindows();
	GDIHelper::GetInstance().InitGDI(System::GetInstance().GetHwnd());
	Asset::GetInstance().Initialize();
	Time::GetInstance().Initialize();
	srand((unsigned)time(nullptr));
	ZeroMemory(currentKeys, sizeof(currentKeys));
	ZeroMemory(lastKeys, sizeof(lastKeys));
	ChangeScene(new TestScene());
}

void World::Dispose()
{
	SafeDelete(currentScene);
	Asset::GetInstance().Dispose();
	GDIHelper::GetInstance().ReleaseGDI(System::GetInstance().GetHwnd());
}

void World::ChangeScene(Scene * scene)
{
	SafeDelete(currentScene);
	currentScene = scene;
}

void World::Render()
{
	currentScene->Render();
}

void World::Update()
{
	Time::GetInstance().Update();

	for (int i = 0; i < 256; i++) {
		lastKeys[i] = currentKeys[i];
		currentKeys[i] = GetAsyncKeyState(i) & 0x8000;
	}

	GetCursorPos(&mousePos);
	ScreenToClient(System::GetInstance().GetHwnd(), &mousePos);

	currentScene->Update();
}

int World::GetKeyState(int vk)
{
	//KeyPress
	if (currentKeys[vk] && lastKeys[vk]) return 2;
	//KeyDown
	if (currentKeys[vk] && !lastKeys[vk]) return 1;
	//KeyUp
	if (!currentKeys[vk] && lastKeys[vk]) return -1;
	//None
	return -2;
}

Vector2 World::GetMousePos()
{
	return Vector2(mousePos.x, mousePos.y);
}

