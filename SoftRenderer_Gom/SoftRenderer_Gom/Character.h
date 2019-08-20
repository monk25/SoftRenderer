#pragma once
#include "Entity.h"
#include "Sprite.h"
#include "CharacterState.h"

class Character :
	public Entity
{
public:
	enum STATE {
		IDLE,
		MOVE,
		JUMP
	};
public:
	Character();
	~Character();

	void Update() override;
	void ChangeState(STATE state);

	map<STATE, CharacterState*> states;
	STATE currentState;

	Sprite* spr;

	float moveSpeed;
};

