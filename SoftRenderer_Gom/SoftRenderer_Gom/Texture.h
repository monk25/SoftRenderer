#pragma once
#include "Define.h"

struct Vertex {
	Vertex() : pos(), color(), uv() {}
	Vertex(Vector3 pos) : pos(pos) {}
	Vertex(Vector3 pos, Vector3Int color) : pos(pos), color(color) {}
	Vertex(Vector3 pos, Vector3Int color, Vector2 uv) :
		pos(pos), color(color), uv(uv) {}
	~Vertex() {}

	Vector3 pos;
	Vector3Int color;
	Vector2 uv;
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

