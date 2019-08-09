#pragma once
#include "Scene.h"
#include "Sprite.h"

class TestScene :
	public Scene
{
public:
	TestScene();
	~TestScene();

	void Update() override;
	void Render() override;

public:
	Sprite* spr;
};

