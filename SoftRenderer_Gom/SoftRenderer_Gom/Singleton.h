#pragma once

template <typename T>
class Singleton
{
protected:
	Singleton<T>() {}
	virtual ~Singleton() {}

public:
	inline static T& GetInstance()
	{
		static T instance;
		return instance;
	}
};