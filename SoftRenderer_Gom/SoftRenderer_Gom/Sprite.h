#pragma once
#include "Entity.h"
#include "Texture.h"
#include "Renderer.h"


class Sprite :
	public Entity
{
public:
	Sprite();
	Sprite(const string& path);
	~Sprite();

	void SetPath(const string& path);

	void Render() override;

public:
	Texture* texture;
	Renderer* shader;
};

