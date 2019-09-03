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
		int uv = static_cast<int>(v * height) * width + static_cast<int>(u * width);
		uv *= 4;
		return png[uv + 2] | png[uv + 1] << 8 | png[uv + 0] << 16 | png[uv + 3] << 24;
	}

public:
	ULONG* texture;
	unsigned char* png;
	int width;
	int height;
	string name;

	Vertex* vertices;
	int verticesCount;
	int* indices;
	int indicesCount;
};

