#include "pch.h"
#include "World.h"
#include "System.h"
#include "GDIHelper.h"
#include "Renderer.h"

#include "Shape.h"


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

	//static Triangle t;
	//t.Render();

	static Quad q;
	q.Render();

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

