#include "pch.h"
#include "Sprite.h"
#include "Asset.h"


Sprite::Sprite() : texture(nullptr), shader(&BitmapRenderer::GetInstance())
{
}

Sprite::Sprite(const string & path) : texture(nullptr), shader(&BitmapRenderer::GetInstance())
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

	shader->Render(matrix, texture);
}
