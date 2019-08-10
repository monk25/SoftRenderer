#include "pch.h"
#include "Time.h"
#include "System.h"


Time::Time()
{
}


Time::~Time()
{
}

void Time::Initialize()
{
	if(!QueryPerformanceFrequency(&startTime))
		cout << "QueryPerformanceFrequency failed!\n";

	freq = 1.0 / static_cast<double>(startTime.QuadPart);
	QueryPerformanceCounter(&startTime);
	lastTime = currentTime = startTime;
}

void Time::Update()
{
	lastTime = currentTime;
	QueryPerformanceCounter(&currentTime);
	deltaTime = static_cast<double>(currentTime.QuadPart - lastTime.QuadPart) * freq;

	static double time = 0;
	static int frame = 0;
	time += GetTime().deltaTime;
	frame++;
	if (time >= 1.0f) {
		wstringstream ws;
		ws << "FPS " << frame << "   (ms) " << time / frame * 1000.0f;
		SetWindowTextW(System::GetInstance().GetHwnd(), ws.str().c_str());
		time = 0.0f;
		frame = 0;
	}
}