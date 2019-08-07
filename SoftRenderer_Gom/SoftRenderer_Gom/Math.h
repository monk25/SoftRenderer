#pragma once
#include "Vector.h"


template<typename T>
inline void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
inline const T& const Max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}

template<typename T>
inline const T& const Min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template<typename T>
inline const T const Abs(const T &t)
{
	return (t > 0) ? t : t * -1;
}

inline int Random(const int& from, const int& to)
{
	return rand() % (to - from + 1) + from;
}

inline float Dot(const Vector3& v1, const Vector3& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline float Clamp(float& value, const float& min, const float& max)
{
	return Max(Min(value, max), min);
}