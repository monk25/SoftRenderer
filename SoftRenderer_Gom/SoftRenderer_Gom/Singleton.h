#pragma once

template <typename T>
class Singleton
{
protected:
	Singleton<T>() {}
	virtual ~Singleton() {}

public:
	static T& GetInstance()
	{
		static T instance;
		return instance;
	}
};