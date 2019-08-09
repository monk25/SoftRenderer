#pragma once
#include "Define.h"

struct Vertex {
	Vertex() : pos(), color(), normal() {}
	Vertex(Vector3 pos) : pos(pos) {}
	Vertex(Vector3 pos, Vector3Int color) : pos(pos), color(color) {}
	Vertex(Vector3 pos, Vector3Int color, Vector2 normal) :
		pos(pos), color(color), normal(normal) {}
	~Vertex() {}

	Vector3 pos;
	Vector3Int color;
	Vector2 normal;
};

class Texture
{
public:
	Texture();
	~Texture();

	void Initialize();
	inline const ULONG& GetPixel(int x, int y) {
		return texture[y * width + x];
	}
	inline const ULONG& GetPixelUV(const float& u, const float& v) {
		return texture[static_cast<int>(v * height) * width + static_cast<int>(u * width)];
	}

public:
	ULONG* texture;
	int width;
	int height;
	string name;

	Vertex* vertices;
	int verticesCount;
	int* indices;
	int indicesCount;
};

