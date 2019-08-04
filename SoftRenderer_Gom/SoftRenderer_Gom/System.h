#pragma once
#include "Define.h"
#include "Singleton.h"

class System :
	public Singleton<System>
{
public:
	System();
	~System();

	void Run();

	LRESULT CALLBACK MessageHandle(HWND, UINT, WPARAM, LPARAM);

	int GetScreenWidth();
	void SetScreenWidth(int screen_width);

	int GetScreenHeight();
	void SetScreenHeight(int screen_width);

	HWND GetHwnd();

	void InitializeWindows();
private:
	bool Frame();
	void ShutdownWindows();

private:
	LPCWSTR applicationName;
	HINSTANCE hInstance;
	HWND hwnd;

	int screenWidth, screenHeight;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
