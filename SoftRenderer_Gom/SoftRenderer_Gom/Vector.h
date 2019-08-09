#pragma once
#include "Define.h"
#include "Matrix.h"

class Vector2;
class Vector2Int;
class Vector3;
class Vector3Int;
class Vector4;

struct Vector2
{
	Vector2() : x{ 0.0f }, y{ 0.0f } {}
	Vector2(const float& x, const float& y) : x{ x }, y{ y } {}
	Vector2(float* arr) : x{ arr[0] }, y{ arr[1] } {}
	Vector2(const Vector2& other) : x{ other.x }, y{ other.y } {}
	Vector2(const Vector2Int& other);
	Vector2(const Vector3& other);
	Vector2(const Vector3Int& other);
	Vector2(const Vector4& other);
	~Vector2() {}

	operator float* () { return &x; }
	operator const float* () const { return &x; }

	Vector2& operator+=(const Vector2& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
	Vector2& operator-=(const Vector2& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}
	Vector2& operator*=(const Vector2& rhs) {
		this->x *= rhs.x;
		this->y *= rhs.y;
		return *this;
	}
	Vector2& operator*=(const float& rhs) {
		this->x *= rhs;
		this->y *= rhs;
		return *this;
	}
	Vector2& operator*=(const Matrix2x2& rhs) {
		*this = *this * rhs;
		return *this;
	}
	Vector2& operator/=(const Vector2& rhs) {
		this->x /= rhs.x;
		this->y /= rhs.y;
		return *this;
	}
	Vector2& operator/=(const float& rhs) {
		this->x /= rhs;
		this->y /= rhs;
		return *this;
	}
	const Vector2 operator+(const Vector2& rhs) const {
		return Vector2{ this->x + rhs.x, this->y + rhs.y };
	}
	const Vector2 operator-(const Vector2& rhs) const {
		return Vector2{ this->x - rhs.x, this->y - rhs.y };
	}
	const Vector2 operator*(const Vector2& rhs) const {
		return Vector2{ this->x * rhs.x, this->y * rhs.y };
	}
	const Vector2 operator*(const float& rhs) const {
		return Vector2{ this->x * rhs, this->y * rhs };
	}
	const Vector2 operator*(const Matrix2x2& rhs) const {
		float t[2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				t[i] += (*this)[j] * rhs.m[i][j];
			}
		}
		return t;
	}
	const Vector2 operator/(const Vector2& rhs) const {
		return Vector2{ this->x / rhs.x, this->y / rhs.y };
	}
	const Vector2 operator/(const float& rhs) const {
		return Vector2{ this->x / rhs, this->y / rhs };
	}
	friend const Vector2 operator*(const float& lhs, const Vector2& rhs) {
		return Vector2{ rhs.x * lhs, rhs.y * lhs };
	}

public:
	float x, y;
};

struct Vector2Int
{
	Vector2Int() : x{ 0 }, y{ 0 } {}
	Vector2Int(const int& x, const int& y) : x{ x }, y{ y } {}
	Vector2Int(const float& x, const float& y) : x{ x }, y{ y } {}
	Vector2Int(const Vector2Int& other) : x{ other.x }, y{ other.y } {}
	Vector2Int(const Vector2& other);
	Vector2Int(const Vector3& other);
	Vector2Int(const Vector3Int& other);
	Vector2Int(const Vector4& other);
	~Vector2Int() {}

	Vector2Int& operator+=(const Vector2Int& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
	Vector2Int& operator-=(const Vector2Int& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}
	Vector2Int& operator*=(const Vector2Int& rhs) {
		this->x *= rhs.x;
		this->y *= rhs.y;
		return *this;
	}
	Vector2Int& operator*=(const float& rhs) {
		this->x *= rhs;
		this->y *= rhs;
		return *this;
	}
	Vector2Int& operator/=(const Vector2Int& rhs) {
		this->x /= rhs.x;
		this->y /= rhs.y;
		return *this;
	}
	Vector2Int& operator/=(const float& rhs) {
		this->x /= rhs;
		this->y /= rhs;
		return *this;
	}
	const Vector2Int operator+(const Vector2Int& rhs) const {
		return Vector2Int{ this->x + rhs.x, this->y + rhs.y };
	}
	const Vector2Int operator-(const Vector2Int& rhs) const {
		return Vector2Int{ this->x - rhs.x, this->y - rhs.y };
	}
	const Vector2Int operator*(const Vector2Int& rhs) const {
		return Vector2Int{ this->x * rhs.x, this->y * rhs.y };
	}
	const Vector2Int operator*(const float& rhs) const {
		return Vector2Int{ this->x * rhs, this->y * rhs };
	}
	const Vector2Int operator/(const Vector2Int& rhs) const {
		return Vector2Int{ this->x / rhs.x, this->y / rhs.y };
	}
	const Vector2Int operator/(const float& rhs) const {
		return Vector2Int{ this->x / rhs, this->y / rhs };
	}
	friend const Vector2Int operator*(const float& lhs, const Vector2Int& rhs) {
		return Vector2Int{ rhs.x * lhs, rhs.y * lhs };
	}

public:
	int x, y;
};

struct Vector3
{
	Vector3() : x{ 0.0f }, y{ 0.0f }, z{ 0.0f } {}
	Vector3(const float& x, const float& y) : x{ x }, y{ y }, z{ 0.0f } {}
	Vector3(const float& x, const float& y, const float& z) : x{ x }, y{ y }, z{ z } {}
	Vector3(float* arr) : x{ arr[0] }, y{ arr[1] }, z{ arr[2] } {}
	Vector3(const Vector3& other) : x{ other.x }, y{ other.y }, z{ other.z } {}
	Vector3(const Vector2& other);
	Vector3(const Vector2Int& other);
	Vector3(const Vector3Int& other);
	Vector3(const Vector4& other);
	~Vector3() {}

	operator float*() { return &x; }
	operator const float*() const { return &x; }

	Vector3& operator+=(const Vector3& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}
	Vector3& operator-=(const Vector3& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}
	Vector3& operator*=(const Vector3& rhs) {
		this->x *= rhs.x;
		this->y *= rhs.y;
		this->z *= rhs.z;
		return *this;
	}
	Vector3& operator*=(const float& rhs) {
		this->x *= rhs;
		this->y *= rhs;
		this->z *= rhs;
		return *this;
	}
	Vector3& operator*=(const Matrix3x3& rhs) {
		*this = *this * rhs;
		return *this;
	}
	Vector3& operator/=(const Vector3& rhs) {
		this->x /= rhs.x;
		this->y /= rhs.y;
		this->z /= rhs.z;
		return *this;
	}
	Vector3& operator/=(const float& rhs) {
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
		return *this;
	}
	const Vector3 operator+(const Vector3& rhs) const {
		return Vector3{ this->x + rhs.x, this->y + rhs.y, this->z + rhs.z };
	}
	const Vector3 operator-(const Vector3& rhs) const {
		return Vector3{ this->x - rhs.x, this->y - rhs.y, this->z - rhs.z };
	}
	const Vector3 operator*(const Vector3& rhs) const {
		return Vector3{ this->x * rhs.x, this->y * rhs.y, this->z * rhs.z };
	}
	const Vector3 operator*(const float& rhs) const {
		return Vector3{ this->x * rhs, this->y * rhs, this->z * rhs };
	}
	const Vector3 operator*(const Matrix3x3& rhs) const {
		float t[3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				t[i] += (*this)[j] * rhs.m[i][j];
			}
		}
		return t;
	}
	const Vector3 operator/(const Vector3& rhs) const {
		return Vector3{ this->x / rhs.x, this->y / rhs.y, this->z / rhs.z };
	}
	const Vector3 operator/(const float& rhs) const {
		return Vector3{ this->x / rhs, this->y / rhs, this->z / rhs };
	}
	friend const Vector3 operator*(const float& lhs, const Vector3& rhs) {
		return Vector3{ rhs.x * lhs, rhs.y * lhs, rhs.z * lhs };
	}

public:
	float x, y, z;
};

struct Vector3Int
{
	Vector3Int() : x{ 0 }, y{ 0 }, z{ 0 } {}
	Vector3Int(const int& x, const int& y) : x{ x }, y{ y }, z{ 0 } {}
	Vector3Int(const int& x, const int& y, const int& z) : x{ x }, y{ y }, z{ z } {}
	Vector3Int(const float& x, const float& y) : x{ x }, y{ y }, z{ 0 } {}
	Vector3Int(const float& x, const float& y, const float& z) : x{ x }, y{ y }, z{ z } {}
	Vector3Int(const Vector3Int& other) : x{ other.x }, y{ other.y }, z{ other.z } {}
	Vector3Int(const Vector2& other);
	Vector3Int(const Vector2Int& other);
	Vector3Int(const Vector3& other);
	Vector3Int(const Vector4& other);
	~Vector3Int() {}

	Vector3Int& operator+=(const Vector3Int& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}
	Vector3Int& operator-=(const Vector3Int& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}
	Vector3Int& operator*=(const Vector3Int& rhs) {
		this->x *= rhs.x;
		this->y *= rhs.y;
		this->z *= rhs.z;
		return *this;
	}
	Vector3Int& operator*=(const float& rhs) {
		this->x *= rhs;
		this->y *= rhs;
		this->z *= rhs;
		return *this;
	}
	Vector3Int& operator/=(const Vector3Int& rhs) {
		this->x /= rhs.x;
		this->y /= rhs.y;
		this->z /= rhs.z;
		return *this;
	}
	Vector3Int& operator/=(const float& rhs) {
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
		return *this;
	}
	const Vector3Int operator+(const Vector3Int& rhs) const {
		return Vector3Int{ this->x + rhs.x, this->y + rhs.y, this->z + rhs.z };
	}
	const Vector3Int operator-(const Vector3Int& rhs) const {
		return Vector3Int{ this->x - rhs.x, this->y - rhs.y, this->z - rhs.z };
	}
	const Vector3Int operator*(const Vector3Int& rhs) const {
		return Vector3Int{ this->x * rhs.x, this->y * rhs.y, this->z * rhs.z };
	}
	const Vector3Int operator*(const float& rhs) const {
		return Vector3Int{ this->x * rhs, this->y * rhs, this->z * rhs };
	}
	const Vector3Int operator/(const Vector3Int& rhs) const {
		return Vector3Int{ this->x / rhs.x, this->y / rhs.y, this->z / rhs.z };
	}
	const Vector3Int operator/(const float& rhs) const {
		return Vector3Int{ this->x / rhs, this->y / rhs, this->z / rhs };
	}
	friend const Vector3Int operator*(const float& lhs, const Vector3Int& rhs) {
		return Vector3Int{ rhs.x * lhs, rhs.y * lhs, rhs.z * lhs };
	}

public:
	int x, y, z;
};

struct Vector4
{
	Vector4() : x{ 0.0f }, y{ 0.0f }, z{ 0.0f }, w{ 0.0f } {}
	Vector4(const float& x, const float& y, const float& z) : x{ x }, y{ y }, z{ z }, w{ 0.0f } {}
	Vector4(const float& x, const float& y, const float& z, const float& w) : x{ x }, y{ y }, z{ z }, w{ w } {}
	Vector4(float* arr) : x{ arr[0] }, y{ arr[1] }, z{ arr[2] }, w{ arr[3] } {}
	Vector4(const Vector4& other) : x{ other.x }, y{ other.y }, z{ other.z }, w{ other.w } {}
	Vector4(const Vector2& other);
	Vector4(const Vector2Int& other);
	Vector4(const Vector3& other);
	Vector4(const Vector3Int& other);
	~Vector4() {}

	operator float*() { return &x; }
	operator const float*() const { return &x; }

	Vector4& operator+=(const Vector4& rhs) {
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		return *this;
	}
	Vector4& operator-=(const Vector4& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}
	Vector4& operator*=(const Vector4& rhs) {
		this->x *= rhs.x;
		this->y *= rhs.y;
		this->z *= rhs.z;
		return *this;
	}
	Vector4& operator*=(const float& rhs) {
		this->x *= rhs;
		this->y *= rhs;
		this->z *= rhs;
		return *this;
	}
	Vector4& operator*=(const Matrix4x4& rhs) {
		*this = *this * rhs;
		return *this;
	}
	Vector4& operator/=(const Vector4& rhs) {
		this->x /= rhs.x;
		this->y /= rhs.y;
		this->z /= rhs.z;
		return *this;
	}
	Vector4& operator/=(const float& rhs) {
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
		return *this;
	}
	const Vector4 operator+(const Vector4& rhs) const {
		return Vector4{ this->x + rhs.x, this->y + rhs.y, this->z + rhs.z };
	}
	const Vector4 operator-(const Vector4& rhs) const {
		return Vector4{ this->x - rhs.x, this->y - rhs.y, this->z - rhs.z };
	}
	const Vector4 operator*(const Vector4& rhs) const {
		return Vector4{ this->x * rhs.x, this->y * rhs.y, this->z * rhs.z };
	}
	const Vector4 operator*(const float& rhs) const {
		return Vector4{ this->x * rhs, this->y * rhs, this->z * rhs };
	}
	const Vector4 operator*(const Matrix4x4& rhs) const {
		float t[4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				t[i] = (*this)[j] * rhs.m[i][j];
			}
		}
		return t;
	}
	const Vector4 operator/(const Vector4& rhs) const {
		return Vector4{ this->x / rhs.x, this->y / rhs.y, this->z / rhs.z };
	}
	const Vector4 operator/(const float& rhs) const {
		return Vector4{ this->x / rhs, this->y / rhs, this->z / rhs };
	}
	friend const Vector4 operator*(const float& lhs, const Vector4& rhs) {
		return Vector4{ rhs.x * lhs, rhs.y * lhs, rhs.z * lhs };
	}

public:
	float x, y, z, w;
};