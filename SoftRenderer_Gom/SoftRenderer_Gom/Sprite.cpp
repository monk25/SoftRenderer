#include "pch.h"
#include "Sprite.h"
#include "Asset.h"


Sprite::Sprite() : texture(nullptr)
{
}

Sprite::Sprite(const string & path) : texture(nullptr)
{
	SetPath(path);
}


Sprite::~Sprite()
{
}

void Sprite::SetPath(const string & path)
{
	texture = GetAsset().GetTexture(path);
	rect.right = texture->width;
	rect.bottom = texture->height;
}

void Sprite::Render()
{
	if (!visible || texture == nullptr)
		return;

	Entity::Render();

	//shader->Render();
}
