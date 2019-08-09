#pragma once
#include "Define.h"
#include "Singleton.h"
#include "Texture.h"

inline bool IsInRange(int x, int y)
{
	return (Abs(x) < (ScreenWidth / 2)) && (Abs(y) < (ScreenHeight / 2));
}
void PutPixel(int x, int y);
void PutPixel(int x, int y, const Vector3& color);
void DrawLine(const Vector3& start, const Vector3& dir, const int& length);
void DrawLine(const Vector3& p1, const Vector3& p2);

class Renderer
{
public:
	Renderer() {}
	virtual ~Renderer() {}

protected:
	virtual void PutPixel(Vertex v) = 0;

private:
	void DrawTriangle(Vertex v1, Vertex v2, Vertex v3);

public:
	void Render(Matrix3x3 matrix, Texture* texture);

protected:
	void* resource;
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

class BitmapRenderer :
	public Renderer, public Singleton<BitmapRenderer>
{
public:
	BitmapRenderer() {}
	virtual ~BitmapRenderer() {}

protected:
	virtual void PutPixel(Vertex v) override;
};