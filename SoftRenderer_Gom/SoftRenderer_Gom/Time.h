#pragma once
#include "Define.h"
#include "Singleton.h"

class Time :
	public Singleton<Time>
{
public:
	Time();
	~Time();

public:
	void Initialize();
	void Update();

	double deltaTime;
private:
	double freq;
	LARGE_INTEGER startTime;
	LARGE_INTEGER currentTime;
	LARGE_INTEGER lastTime;
};

inline Time& GetTime() {
	return Time::GetInstance();
}