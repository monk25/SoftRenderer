#pragma once
#include "Define.h"
#include "Singleton.h"

void PutPixel(int x, int y);
void PutPixel(int x, int y, const Vector3& color);
void DrawLine(const Vector3& start, const Vector3& dir, const int& length);
void DrawLine(const Vector3& p1, const Vector3& p2);

struct Vertex {
	Vertex() : pos(), color(), uv() {}
	Vertex(Vector3Int pos) : pos(pos) {}
	Vertex(Vector3Int pos, Vector3Int color) : pos(pos), color(color) {}
	Vertex(Vector3Int pos, Vector3Int color, Vector2 uv) : 
		pos(pos), color(color), uv(uv) {}
	~Vertex() {}

	Vector3Int pos;
	Vector3Int color;
	Vector2 uv;
};

class Renderer
{
public:
	Renderer() {}
	virtual ~Renderer() {}

protected:
	virtual void PutPixel(Vertex v) = 0;

private:

public:
	void DrawTriangle(Vertex v1, Vertex v2, Vertex v3);
	void Render(Vertex vertices[], int indices[], int iSize);
};

class ColorRenderer :
	public Renderer, public Singleton<ColorRenderer>
{
public:
	ColorRenderer() {}
	virtual ~ColorRenderer() {}

protected:
	virtual void PutPixel(Vertex v) override;
};