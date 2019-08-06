#include "pch.h"
#include "Define.h"
#include "GDIHelper.h"

GDIHelper::GDIHelper()
{
}

GDIHelper::~GDIHelper()
{
}

void GDIHelper::BufferSwap()
{
	BitBlt(hScreenDC, 0, 0, ScreenWidth, ScreenHeight, hMemoryDC, 0, 0, SRCCOPY);
}

void GDIHelper::SetColor(BYTE r, BYTE g, BYTE b)
{
	currentColor = RGB(b, g, r);
}

void GDIHelper::Clear()
{
	ULONG* dest = (ULONG*)pBits;
	DWORD bytecount = ScreenWidth * ScreenHeight * sizeof(ULONG);
	ULONG value = currentColor;
	bytecount /= 4;
	while (bytecount--)
	{
		*dest++ = value;
	}
	return;
}

void GDIHelper::InitGDI(HWND hWnd)
{
	hScreenDC = GetDC(hWnd);
	hMemoryDC = CreateCompatibleDC(hScreenDC);

	BITMAPINFO bmi;
	memset(&bmi, 0, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = ScreenWidth;
	bmi.bmiHeader.biHeight = -ScreenHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	hDIBitmap = CreateDIBSection(hMemoryDC, &bmi, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
	hDefaultBitmap = (HBITMAP)SelectObject(hMemoryDC, hDIBitmap);

	//g_bIsActive = TRUE;
}

void GDIHelper::ReleaseGDI(HWND hWnd)
{
	//g_bIsActive = FALSE;

	DeleteObject(hDefaultBitmap);
	DeleteObject(hDIBitmap);
	ReleaseDC(hWnd, hScreenDC);
	ReleaseDC(hWnd, hMemoryDC);
}