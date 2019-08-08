#include "pch.h"
#include "Scene.h"


Scene::Scene() : mainCamera{ nullptr }
{
	mainCamera = new Camera{};
	AddChild(mainCamera);
}


Scene::~Scene()
{
}
