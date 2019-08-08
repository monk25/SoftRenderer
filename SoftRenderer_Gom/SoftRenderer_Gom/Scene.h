#pragma once
#include "Entity.h"
#include "Camera.h"

class Scene :
	public Entity
{
public:
	Scene();
	~Scene();

public:
	Camera* mainCamera;
};

