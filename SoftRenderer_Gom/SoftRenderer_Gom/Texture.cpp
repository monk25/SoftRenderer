#include "pch.h"
#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
	SafeDelete(texture);
	SafeDelete(vertices);
	SafeDelete(indices);
}

void Texture::Initialize()
{
	float halfWidth, halfHeight;
	halfWidth = width * 0.5f;
	halfHeight = height * 0.5f;
	verticesCount = 4;
	vertices = new Vertex[verticesCount]{
		{ Vector3{ -halfWidth, -halfHeight}, Vector3Int{255, 255, 255}, Vector2{0, 0} },
		{ Vector3{  halfWidth, -halfHeight}, Vector3Int{255, 255, 255}, Vector2{1, 0} },
		{ Vector3{ -halfWidth,  halfHeight}, Vector3Int{255, 255, 255}, Vector2{0, 1} },
		{ Vector3{  halfWidth,  halfHeight}, Vector3Int{255, 255, 255}, Vector2{1, 1} }
	};
	indicesCount = 6;
	indices = new int[indicesCount]{ 0, 1, 2, 1, 3, 2 };
}