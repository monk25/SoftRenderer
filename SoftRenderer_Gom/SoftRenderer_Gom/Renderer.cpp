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