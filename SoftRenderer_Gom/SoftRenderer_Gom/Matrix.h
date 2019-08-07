#pragma once
#include "Define.h"

class Vector2;
class Vector2Int;
class Vector3;
class Vector3Int;
class Vector4;

struct Matrix2x2
{
	Matrix2x2() : m{ 0.0f, } {}
	Matrix2x2(float _11, float _12, float _21, float _22)
		: _11(_11), _12(_12), _21(_21), _22(_22) {}
	Matrix2x2(const Matrix2x2& other)
		: _11(other._11), _12(other._12), _21(other._21), _22(other._22) {}
	~Matrix2x2() {}
	
	Matrix2x2& operator+=(const Matrix2x2& rhs) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				m[i][j] += rhs.m[i][j];
			}
		}
	}

	Matrix2x2& operator-=(const Matrix2x2& rhs) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				m[i][j] -= rhs.m[i][j];
			}
		}
	}

	Matrix2x2& operator*=(const Matrix2x2& rhs) {
		*this = *this * rhs;
	}

	const Matrix2x2 operator+(const Matrix2x2& rhs) const {
		return Matrix2x2{
			_11 + rhs._11, _12 + rhs._12,
			_21 + rhs._21, _22 + rhs._22
		};
	}

	const Matrix2x2 operator-(const Matrix2x2& rhs) const {
		return Matrix2x2{
			_11 - rhs._11, _12 - rhs._12,
			_21 - rhs._21, _22 - rhs._22
		};
	}

	const Matrix2x2 operator*(const Matrix2x2& rhs) const {
		Matrix2x2 tmp{};
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					tmp.m[i][j] += m[i][k] * rhs.m[k][j];
				}
			}
		}
		return tmp;
	}

public:
	union {
		struct {
			float _11, _12;
			float _21, _22;
		};
		float m[2][2];
	};
};

struct Matrix3x3
{
	Matrix3x3() : m{ 0.0f } {}

public:
	union {
		struct {
			float _11, _12, _13;
			float _21, _22, _23;
			float _31, _32, _33;
		};
		float m[3][3];
	};
};

struct Matrix4x4
{
	Matrix4x4() : m{ 0.0f } {}

public:
	union {
		struct {
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4];
	};
};