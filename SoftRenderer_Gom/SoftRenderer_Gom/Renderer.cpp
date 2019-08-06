#include "pch.h"
#include "Renderer.h"
#include "GDIHelper.h"
#include "Asset.h"


void PutPixel(int x, int y)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)GetGDI().pBits;
	DWORD offset = ScreenWidth * ScreenHeight / 2 + ScreenWidth / 2 + x + ScreenWidth * -y;
	*(dest + offset) = GetGDI().currentColor;
}

void PutPixel(int x, int y, const Vector3 & color)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)GetGDI().pBits;
	DWORD offset = ScreenWidth * ScreenHeight / 2 + ScreenWidth / 2 + x + ScreenWidth * -y;
	*(dest + offset) = RGB(color.z, color.y, color.x);
}

void DrawLine(const Vector3& start, const Vector3& dir, const int& length)
{
	for (int i = 0; i <= length; i++) {
		Vector3 v = start + i * dir;
		PutPixel(v.x, v.y);
	}
}

void DrawLine(const Vector3& p1, const Vector3& p2)
{
	Vector3 dir = p2 - p1;
	float length = Max(Abs(dir.x), Abs(dir.y));
	dir /= length;
	DrawLine(p1, dir, length);
}

void Renderer::Render(Vertex vertices[], int indices[], int iSize, void* data)
{
	this->data = data;
	for (int i = 0; i < iSize; i += 3) {
		DrawTriangle(vertices[indices[i]], vertices[indices[i + 1]], vertices[indices[i + 2]]);
	}
}

void Renderer::DrawTriangle(Vertex v1, Vertex v2, Vertex v3)
{
	if (v1.pos.y < v2.pos.y) {
		Swap(v1, v2);
	}
	if (v1.pos.y < v3.pos.y) {
		Swap(v1, v3);
	}
	if (v2.pos.y < v3.pos.y) {
		Swap(v2, v3);
	}

	Vector3 d1 = v2.pos - v1.pos;
	Vector3 d2 = v3.pos - v1.pos;
	Vector3 d3 = v3.pos - v2.pos;

	int d1Len = Abs(d1.y);
	int d2Len = Abs(d2.y);
	int d3Len = Abs(d3.y);

	if (d1Len != 0)
		d1 /= d1Len;
	if (d2Len != 0)
		d2 /= d2Len;
	if (d3Len != 0)
		d3 /= d3Len;

	for (int i = 0; i < d1Len; i++) {
		Vector3Int u{ v1.pos + d1 * i };
		Vector3Int v{ v1.pos + d2 * i };
		if (u.x > v.x) {
			Swap(u.x, v.x);
		}
		for (int j = u.x; j <= v.x; j++) {
			Vertex pixel{ Vector2Int(j, u.y), Vector3Int(255, 0, 0), Vector2(0, 0) };
			PutPixel(pixel);
		}
	}
	for (int i = 0; i <= d3Len; i++) {
		Vector3Int u{ v1.pos + d1 * d1Len + d3 * i };
		Vector3Int v{ v1.pos + d2 * (d1Len + i) };
		if (u.x > v.x) {
			Swap(u.x, v.x);
		}
		for (int j = u.x; j <= v.x; j++) {
			Vertex pixel{ Vector2Int(j, u.y), Vector3Int(0, 255, 0), Vector2(0, 0) };
			PutPixel(pixel);
		}
	}
}

void ColorRenderer::PutPixel(Vertex v)
{
	if (!IsInRange(v.pos.x, v.pos.y)) return;

	ULONG* dest = (ULONG*)GetGDI().pBits;
	DWORD offset = ScreenWidth * ScreenHeight / 2 + ScreenWidth / 2 + v.pos.x + ScreenWidth * -v.pos.y;
	*(dest + offset) = RGB(v.color.z, v.color.y, v.color.x);
}

void BitmapRenderer::PutPixel(Vertex v)
{
	if (!IsInRange(v.pos.x, v.pos.y)) return;

	ULONG* dest = (ULONG*)GetGDI().pBits;
	DWORD offset = ScreenWidth * ScreenHeight / 2 + ScreenWidth / 2 + v.pos.x + ScreenWidth * -v.pos.y;
	*(dest + offset) = GetAsset().GetPixel(v.uv.x, v.uv.y, (Bitmap*)data);
}
