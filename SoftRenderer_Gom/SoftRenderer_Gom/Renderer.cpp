#include "pch.h"
#include "GDIHelper.h"
#include "Renderer.h"


void PutPixel(int x, int y)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)g_pBits;
	DWORD offset = ScreenWidth * ScreenHeight / 2 + ScreenWidth / 2 + x + ScreenWidth * -y;
	*(dest + offset) = g_CurrentColor;
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

void DrawTriangle(const Vector3& p1, const Vector3& p2, const Vector3& p3)
{
	Vector3 drawDir = p2 - p1;
	Vector3 progressDir = p3 - p1;

	float drawLen = Max(Abs(drawDir.x), Abs(drawDir.y));
	float progressLen = Max(Abs(progressDir.x), Abs(progressDir.y));
	drawDir /= drawLen;
	progressDir /= progressLen;

	for (int i = 0; i <= progressLen; i++) {
		Vector3 v{ p1 + (progressDir * i) };
		float len = (1 - i / progressLen) * drawLen;
		len = (len - (int)len > 0.5f) ? len + 1 : len;
		DrawLine(v, drawDir, len);
	}
}

void DrawTriangle2(Vector3Int p1, Vector3Int p2, Vector3Int p3)
{
	if (p1.y < p2.y) {
		Swap(p1, p2);
	}
	if (p1.y < p3.y) {
		Swap(p1, p3);
	}
	if (p2.y < p3.y) {
		Swap(p2, p3);
	}

	Vector3 v1 = p2 - p1;
	Vector3 v2 = p3 - p1;
	Vector3 v3 = p3 - p2;

	int v1Len = Abs(v1.y);
	int v2Len = Abs(v2.y);
	int v3Len = Abs(v3.y);

	if(v1Len != 0)
		v1 /= v1Len;
	if(v2Len != 0)
		v2 /= v2Len;
	if(v3Len != 0)
		v3 /= v3Len;

	for (int i = 0; i < v1Len; i++) {
		Vector3Int u{ p1 + v1 * i };
		Vector3Int v{ p1 + v2 * i };
		if (u.x > v.x) {
			Swap(u.x, v.x);
		}
		for (int j = u.x; j <= v.x; j++) {
			PutPixel(j, u.y);
		}
	}
	for (int i = 0; i <= v3Len; i++) {
		Vector3 u{ p1 + v1 * v1Len + v3 * i };
		Vector3 v{ p1 + v2 * (v1Len + i) };
		if (u.x > v.x) {
			Swap(u.x, v.x);
		}
		for (int j = u.x; j <= v.x; j++) {
			PutPixel(j, u.y);
		}
	}
}