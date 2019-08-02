#pragma once
#include <time.h>

template<typename T>
void Swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T& const Max(const T &a, const T &b)
{
	return (a > b) ? a : b;
}

template<typename T>
const T& const Min(const T &a, const T &b)
{
	return (a < b) ? a : b;
}

template<typename T>
const T const Abs(const T &t)
{
	return (t > 0) ? t : t * -1;
}

struct Vector3
{
public:
	Vector3() : x(0), y(0), z(0) {}
	Vector3(int x, int y) : x(x), y(y), z(0) {}
	Vector3(int x, int y, int z) : x(x), y(y), z(z) {}
	~Vector3() {}

	float GetMagnitude() const
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}
	static float Cross(const Vector3& lhv, const Vector3& rhv)
	{
		return lhv.x * rhv.y - lhv.y * rhv.x;
	}

	const Vector3 const operator+=(const Vector3& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}

	const Vector3 const operator-=(const Vector3& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}

	const Vector3 const operator*=(const Vector3& rhs) {
		this->x *= rhs.x;
		this->y *= rhs.y;
		this->z *= rhs.z;
		return *this;
	}

	const Vector3 const operator*=(const float& rhs) {
		this->x *= rhs;
		this->y *= rhs;
		this->z *= rhs;
		return *this;
	}

	const Vector3 const operator/=(const Vector3& rhs) {
		this->x /= rhs.x;
		this->y /= rhs.y;
		this->z /= rhs.z;
		return *this;
	}

	const Vector3 const operator/=(const float& rhs) {
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
		return *this;
	}

	const Vector3 const operator+(const Vector3& rhs) const {
		Vector3 tmp{ *this };
		tmp += rhs;
		return tmp;
	}

	const Vector3 const operator-(const Vector3& rhs) const {
		Vector3 tmp{ *this };
		tmp -= rhs;
		return tmp;
	}

	const Vector3 const operator*(const Vector3& rhs) const {
		Vector3 tmp{ *this };
		tmp *= rhs;
		return tmp;
	}

	const Vector3 const operator*(const float& rhs) const {
		Vector3 tmp{ *this };
		tmp *= rhs;
		return tmp;
	}

	const Vector3 const operator/(const Vector3& rhs) const {
		Vector3 tmp{ *this };
		tmp *= rhs;
		return tmp;
	}

	const Vector3 const operator/(const float& rhs) const {
		Vector3 tmp{ *this };
		tmp /= rhs;
		return tmp;
	}

	friend const Vector3 const operator*(const float& lhs, const Vector3& rhs) {
		Vector3 tmp{ rhs };
		tmp *= lhs;
		return tmp;
	}


public:
	float x, y, z;
};