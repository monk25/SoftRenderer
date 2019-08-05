#pragma once
#include "Define.h"

extern ULONG g_CurrentColor;
extern BYTE *g_pBits;

void InitGDI(HWND hWnd);
void ReleaseGDI(HWND hWnd);
void SetColor(BYTE r, BYTE g, BYTE b);
void Clear();
void BufferSwap();

inline bool IsInRange(int x, int y)
{
	return (Abs(x) < (ScreenWidth / 2)) && (Abs(y) < (ScreenHeight / 2));
}