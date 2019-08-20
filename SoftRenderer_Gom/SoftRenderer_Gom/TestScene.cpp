#include "pch.h"
#include "TestScene.h"
#include "Sprite.h"
#include "World.h"
#include "Time.h"
#include "Character.h"

TestScene::TestScene()
{
	spr = new Sprite("ikmyung2.bmp");
	spr->scale *= 0.2f;
	AddChild(spr);

	Character* cha = new Character();
	cha->scale *= 0.2f;
	AddChild(cha);
}


TestScene::~TestScene()
{
}

void TestScene::Update()
{
	Scene::Update();

	if (GetWorld().GetKeyState(VK_SPACE) == 1) {
		spr->position = Vector3{};
		spr->rotation = 0.0f;
		spr->scale = Vector2{ 0.2f, 0.2f };

		mainCamera->position = Vector3{};
		mainCamera->rotation = 0.0f;
		mainCamera->scale = Vector2{ 1.0f, 1.0f };
	}

	if (GetWorld().GetKeyState(VK_LEFT) > 0) {
		spr->position.x -= 100.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState(VK_RIGHT) > 0) {
		spr->position.x += 100.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState(VK_UP) > 0) {
		spr->position.y -= 100.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState(VK_DOWN) > 0) {
		spr->position.y += 100.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('N') > 0) {
		spr->rotation -= 10.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('M') > 0) {
		spr->rotation += 10.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('L') > 0) {
		spr->scale -= 0.5f * Vector2{ 1.0f, 1.0f } * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('K') > 0) {
		spr->scale += 0.5f * Vector2{ 1.0f, 1.0f } * GetTime().deltaTime;
	}

	if (GetWorld().GetKeyState('A') > 0) {
		mainCamera->position.x -= 100.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('D') > 0) {
		mainCamera->position.x += 100.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('W') > 0) {
		mainCamera->position.y -= 100.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('S') > 0) {
		mainCamera->position.y += 100.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('Q') > 0) {
		mainCamera->rotation += 10.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('E') > 0) {
		mainCamera->rotation -= 10.0f * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('R') > 0) {
		mainCamera->scale += 0.5f * Vector2{ 1.0f, 1.0f } * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState('F') > 0) {
		mainCamera->scale -= 0.5f * Vector2{ 1.0f, 1.0f } * GetTime().deltaTime;
	}
}

void TestScene::Render()
{
	Scene::Render();
}
