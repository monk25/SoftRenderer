#pragma once
#include "Entity.h"


class Sprite :
	public Entity
{
public:
	Sprite();
	~Sprite();

	void Render() override;
};

