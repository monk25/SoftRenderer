#include "pch.h"
#include "Time.h"


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
}