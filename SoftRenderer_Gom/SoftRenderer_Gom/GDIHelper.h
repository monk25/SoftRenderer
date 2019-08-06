#pragma once
#include "Define.h"
#include "Singleton.h"

class GDIHelper :
	public Singleton<GDIHelper>
{
public:
	GDIHelper();
	~GDIHelper();

	void InitGDI(HWND hWnd);
	void ReleaseGDI(HWND hWnd);
	void SetColor(BYTE r, BYTE g, BYTE b);
	void Clear();
	void BufferSwap();

public:
	ULONG currentColor;
	BYTE* pBits;

private:
	HDC hScreenDC, hMemoryDC;
	HBITMAP hDefaultBitmap, hDIBitmap;
};

inline GDIHelper& GetGDI() {
	return GDIHelper::GetInstance();
}