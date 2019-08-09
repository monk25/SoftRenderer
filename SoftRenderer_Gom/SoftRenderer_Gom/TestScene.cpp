#include "pch.h"
#include "TestScene.h"
#include "Sprite.h"
#include "World.h"


TestScene::TestScene()
{
	spr = new Sprite("ikmyung2.bmp");
	AddChild(spr);
}


TestScene::~TestScene()
{
}

void TestScene::Update()
{
	Scene::Update();
	spr->position.x += 10.0f * GetWorld().deltaTime;
	spr->rotation += GetWorld().deltaTime;
	spr->scale -= Vector2{0.05f, 0.05f} * GetWorld().deltaTime;

	cout << GetWorld().deltaTime << endl;
}

void TestScene::Render()
{
	Scene::Render();
}
