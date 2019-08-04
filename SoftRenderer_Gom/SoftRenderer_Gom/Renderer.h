#pragma once

#include "Define.h"

inline bool IsInRange(int x, int y)
{
	return (abs(x) < (ScreenWidth / 2)) && (abs(y) < (ScreenHeight / 2));
}

void PutPixel(int x, int y);
void DrawLine(const Vector3& start, const Vector3& dir, const int& length);
void DrawLine(const Vector3& p1, const Vector3& p2);
void DrawTriangle(const Vector3& p1, const Vector3& p2, const Vector3& p3);