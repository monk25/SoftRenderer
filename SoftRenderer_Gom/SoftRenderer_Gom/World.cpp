#include "pch.h"
#include "World.h"
#include "System.h"
#include "GDIHelper.h"
#include "Renderer.h"


World::World()
{
}


World::~World()
{
}

void World::Initialize(int screenWidth, int screenHeight)
{
	System::GetInstance().InitializeWindows();
	InitGDI(System::GetInstance().GetHwnd());
	srand((unsigned)time(nullptr));
	ZeroMemory(currentKeys, sizeof(currentKeys));
	ZeroMemory(lastKeys, sizeof(lastKeys));
	startClock = lastClock = currentClock = clock();
}

void World::Dispose()
{
	ReleaseGDI(System::GetInstance().GetHwnd());
}

void World::Render()
{
	SetColor(0, 0, 0);
	Clear();

	//Entity Render()
	SetColor(255, 0, 0);

	static Vector2 v1{ -50.0f, -50.0f };
	static Vector2 v2{ 0.0f, 50.0f };
	static Vector2 v3{ 50.0f, -50.0f };

	Vector2 v;
	if (GetKeyState(VK_LEFT) > 0) {
		v.x -= 1;
	}
	if (GetKeyState(VK_RIGHT) > 0) {
		v.x += 1;
	}
	if (GetKeyState(VK_UP) > 0) {
		v.y += 1;
	}
	if (GetKeyState(VK_DOWN) > 0) {
		v.y -= 1;
	}

	if (GetKeyState(VK_SPACE) == 1) {
		v1 = Vector2Int{ Random(-400, 400), Random(-400, 400) };
		v2 = Vector2Int{ Random(-400, 400), Random(-400, 400) };
		v3 = Vector2Int{ Random(-400, 400), Random(-400, 400) };
	}

	v1 += v * deltaTime * 100.0f;
	v2 += v * deltaTime * 100.0f;
	v3 += v * deltaTime * 100.0f;

	DrawTriangle2(v1, v2, v3);
	

	BufferSwap();

	cout << deltaTime << endl;
}

void World::Update()
{
	lastClock = currentClock;
	currentClock = clock();
	deltaTime = (double)(currentClock - lastClock) / CLOCKS_PER_SEC;

	for (int i = 0; i < 256; i++) {
		lastKeys[i] = currentKeys[i];
		currentKeys[i] = GetAsyncKeyState(i) & 0x8000;
	}

	GetCursorPos(&mousePos);
	ScreenToClient(System::GetInstance().GetHwnd(), &mousePos);
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

