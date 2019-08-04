#include "pch.h"
#include "System.h"
#include "World.h"


System::System() : screenWidth(0), screenHeight(0)
{
}


System::~System()
{
	ShutdownWindows();
}

void System::Run()
{
	MSG msg;

	bool done, result;

	ZeroMemory(&msg, sizeof(MSG));

	done = false;
	while (!done) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT) {
			done = true;
		}
		else {
			result = Frame();
			if (!result) {
				MessageBox(hwnd, L"Frame Processing Failed", L"Error", MB_OK);
				done = true;
			}
			if (World::GetInstance().GetKeyState(VK_ESCAPE) > 0) {
				done = true;
			}
		}
	}
}

bool System::Frame()
{
	World::GetInstance().Update();
	World::GetInstance().Render();
	return true;
}

LRESULT CALLBACK System::MessageHandle(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	return DefWindowProc(hwnd, umsg, wparam, lparam);
}

void System::InitializeWindows()
{
	WNDCLASSEXW wc;
	DEVMODE dm_screen_settings;
	int pos_x, pos_y;

	hInstance = GetModuleHandle(NULL);
	applicationName = L"Engine";

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	RegisterClassExW(&wc);

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (FullScreen) {
		memset(&dm_screen_settings, 0, sizeof(dm_screen_settings));
		dm_screen_settings.dmSize = sizeof(dm_screen_settings);
		dm_screen_settings.dmPelsWidth = screenWidth;
		dm_screen_settings.dmPelsHeight = screenHeight;
		dm_screen_settings.dmBitsPerPel = 32;
		dm_screen_settings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&dm_screen_settings, CDS_FULLSCREEN);

		pos_x = pos_y = 0;
	}
	else {
		pos_x = (screenWidth - ScreenWidth / 72 - ScreenWidth) / 2;
		pos_y = (screenHeight - ScreenHeight / 18 - ScreenHeight) / 2;

		screenWidth = ScreenWidth;
		screenHeight = ScreenHeight;
	}

	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = screenWidth - 1;
	rect.bottom = screenHeight - 1;
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	int WindowWidth = rect.right - rect.left + 1;
	int WindowHeight = rect.bottom - rect.top + 1;

	hwnd = CreateWindowW(applicationName, L"GomJun", WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,
		(GetSystemMetrics(SM_CXFULLSCREEN) - WindowWidth) / 2, (GetSystemMetrics(SM_CYFULLSCREEN) - WindowHeight) / 2, WindowWidth, WindowHeight,
		nullptr, nullptr, hInstance, nullptr);

	ShowWindow(hwnd, SW_SHOW);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	ShowCursor(true);

	return;
}

void System::ShutdownWindows()
{
	ShowCursor(true);

	if (FullScreen) {
		ChangeDisplaySettings(NULL, 0);
	}

	DestroyWindow(hwnd);
	UnregisterClass(applicationName, hInstance);

	return;
}

int System::GetScreenWidth()
{
	return screenWidth;
}

void System::SetScreenWidth(int screen_width)
{
	screenWidth = screen_width;
}

int System::GetScreenHeight()
{
	return screenHeight;
}

void System::SetScreenHeight(int screen_height)
{
	screenHeight = screen_height;
}

HWND System::GetHwnd()
{
	return hwnd;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;

	default:
		System::GetInstance().MessageHandle(hwnd, umessage, wparam, lparam);
	}
}