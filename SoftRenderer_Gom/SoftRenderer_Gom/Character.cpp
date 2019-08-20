#include "pch.h"
#include "Character.h"


Character::Character()
{
	spr = new Sprite("ikmyung2.bmp");
	AddChild(spr);

	states[STATE::IDLE] = new CharacterIdle(this);
	states[STATE::MOVE] = new CharacterMove(this);
	states[STATE::JUMP] = new CharacterJump(this);

	currentState = STATE::IDLE;
	moveSpeed = 10.0f;
}


Character::~Character()
{
}

void Character::Update()
{
	states[currentState]->Update();
}

void Character::ChangeState(STATE state)
{
	states[currentState]->End();
	currentState = state;
	states[currentState]->Begine();
}
