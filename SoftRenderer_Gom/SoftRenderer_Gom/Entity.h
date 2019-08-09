#pragma once
#include "Define.h"


class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void Update();
	virtual void Render();
	void AddChild(Entity* child);
	void Removing();

public:
	Entity* parent;
	vector<Entity*> children;
	Vector2 position;
	Vector2 scale;
	float rotation;
	Matrix3x3 matrix;
	Rect rect;
	bool visible;
	bool removing;
};

