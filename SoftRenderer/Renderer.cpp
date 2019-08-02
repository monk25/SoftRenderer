
#include "stdafx.h"
#include "SoftRenderer.h"
#include "GDIHelper.h"
#include "Renderer.h"

bool IsInRange(int x, int y);
void PutPixel(int x, int y);

bool IsInRange(int x, int y)
{
	return (abs(x) < (g_nClientWidth / 2)) && (abs(y) < (g_nClientHeight / 2));
}

void PutPixel(int x, int y)
{
	if (!IsInRange(x, y)) return;

	ULONG* dest = (ULONG*)g_pBits;
	DWORD offset = g_nClientWidth * g_nClientHeight / 2 + g_nClientWidth / 2 + x + g_nClientWidth * -y;
	*(dest + offset) = g_CurrentColor;
}

void const DrawLine(const Vector3& start, const Vector3& dir, const int& length)
{
	for (int i = 0; i <= length; i++) {
		Vector3 v = start + i * dir;
		PutPixel(v.x, v.y);
	}
}

void const DrawLine(const Vector3& p1, const Vector3& p2)
{
	Vector3 dir = p2 - p1;
	float length = Max(Abs(dir.x), Abs(dir.y));
	dir /= length;
	DrawLine(p1, dir, length);
}

void const DrawTriangle(const Vector3& p1, const Vector3& p2, const Vector3& p3)
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

void DrawTriangle2(const Vector3& v1, const Vector3& v2, const Vector3& v3)
{
	float Xstart = min(min(v1.x, v2.x), v3.x);
	float Ystart = min(min(v1.y, v2.y), v3.y);
	float Xend = max(max(v1.x, v2.x), v3.x);
	float Yend = max(max(v1.y, v2.y), v3.y);

	Vector3 start(Xstart, Ystart);
	Vector3 end(Xend, Yend);

	for (int y = 0; y < end.y - start.y; ++y)
	{
		for (int x = 0; x < end.x - start.x; ++x)
		{
			Vector3 p = (start + Vector3(x, y));

			if (Vector3::Cross((v1 - v2), p - v2) >= 0 && Vector3::Cross((v2 - v3), p - v3) >= 0 && Vector3::Cross((v3 - v1), p - v1) >= 0)
			{
				//getColor;
				auto totalLength = (v1 - p).GetMagnitude() + (v2 - p).GetMagnitude() + (v3 - p).GetMagnitude();

				PutPixel(p.x, p.y);
			}
		}
	}
}

Vector3 v1{ 0, 0, 0 };
Vector3 v2{ 0, 0, 0 };
Vector3 v3{ 0, 0, 0 };

void UpdateFrame(void)
{
	// Buffer Clear
	SetColor(32, 128, 255);
	Clear();

	if ((GetAsyncKeyState(VK_SPACE) & 0x8000)) {
		v1.x = rand() % 400 - 200;
		v1.y = rand() % 400 - 200;
		v2.x = rand() % 400 - 200;
		v2.y = rand() % 400 - 200;
		v3.x = rand() % 400 - 200;
		v3.y = rand() % 400 - 200;
	}

	SetColor(0, 0, 0);
	DrawTriangle(v1, v2, v3);

	// Buffer Swap 
	BufferSwap();
}
