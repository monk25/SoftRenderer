#include "pch.h"
#include "Vector.h"

Vector2::Vector2(const Vector2Int & other) : x{ static_cast<float>(other.x) }, y{ static_cast<float>(other.y) } {}
Vector2::Vector2(const Vector3 & other) : x{ other.x }, y{ other.y } {}
Vector2::Vector2(const Vector3Int & other) : x{ static_cast<float>(other.x) }, y{ static_cast<float>(other.y) } {}
Vector2::Vector2(const Vector4 & other) : x{ other.x }, y{ other.y } {}

Vector2Int::Vector2Int(const Vector2 & other) : x{ static_cast<int>(other.x) }, y{ static_cast<int>(other.y) } {}
Vector2Int::Vector2Int(const Vector3 & other) : x{ static_cast<int>(other.x) }, y{ static_cast<int>(other.y) } {}
Vector2Int::Vector2Int(const Vector3Int & other) : x{ other.x }, y{ other.y } {}
Vector2Int::Vector2Int(const Vector4 & other) : x{ static_cast<int>(other.x) }, y{ static_cast<int>(other.y) } {}

Vector3::Vector3(const Vector2 & other) : x{ other.x }, y{ other.y }, z{ 0.0f } {}
Vector3::Vector3(const Vector2Int & other) : x{ static_cast<float>(other.x) }, y{ static_cast<float>(other.y) }, z{ 0.0f } {}
Vector3::Vector3(const Vector3Int & other) : x{ static_cast<float>(other.x) }, y{ static_cast<float>(other.y) }, z{ static_cast<float>(other.z) } {}
Vector3::Vector3(const Vector4 & other) : x{ other.x }, y{ other.y }, z{ other.z } {}

Vector3Int::Vector3Int(const Vector2 & other) : x{ static_cast<int>(other.x) }, y{ static_cast<int>(other.y) }, z{ 0 } {}
Vector3Int::Vector3Int(const Vector2Int & other) : x{ other.x }, y{ other.y }, z{ 0 } {}
Vector3Int::Vector3Int(const Vector3 & other) : x{ static_cast<int>(other.x) }, y{ static_cast<int>(other.y) }, z{ static_cast<int>(other.z) } {}
Vector3Int::Vector3Int(const Vector4 & other) : x{ static_cast<int>(other.x) }, y{ static_cast<int>(other.y) }, z{ static_cast<int>(other.z) } {}

Vector4::Vector4(const Vector2 & other) : x{ other.x }, y{ other.y }, z{ 0.0f }, w{ 0.0f } {}
Vector4::Vector4(const Vector2Int & other) : x{ static_cast<float>(other.x) }, y{ static_cast<float>(other.y) }, z{ 0.0f }, w{ 0.0f } {}
Vector4::Vector4(const Vector3 & other) : x{ other.x }, y{ other.y }, z{ other.z }, w{ 0.0f } {}
Vector4::Vector4(const Vector3Int & other) : x{ static_cast<float>(other.x) }, y{ static_cast<float>(other.y) }, z{ static_cast<float>(other.z) }, w{ 0.0f } {}
