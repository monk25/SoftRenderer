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