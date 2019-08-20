#include "pch.h"
#include "CharacterState.h"
#include "Character.h"
#include "World.h"
#include "Time.h"


CharacterState::CharacterState(Character* target) : target(target)
{
}


CharacterState::~CharacterState()
{
}

CharacterIdle::CharacterIdle(Character * target) : CharacterState(target)
{
}

void CharacterIdle::Update()
{
	if (GetWorld().GetKeyState(VK_LEFT) > 0 ||
		GetWorld().GetKeyState(VK_RIGHT) > 0) {
		target->ChangeState(Character::STATE::MOVE);
	}
	else if (GetWorld().GetKeyState(VK_SPACE) > 0) {
		target->ChangeState(Character::STATE::JUMP);
	}
}

CharacterMove::CharacterMove(Character * target) : CharacterState(target)
{
}

void CharacterMove::Update()
{
	if (GetWorld().GetKeyState(VK_SPACE) > 0) {
		target->ChangeState(Character::STATE::JUMP);
	}

	if (GetWorld().GetKeyState(VK_LEFT) > 0) {
		target->spr->scale.x = 1;
		target->position.x -= target->moveSpeed * GetTime().deltaTime;
	}
	if (GetWorld().GetKeyState(VK_RIGHT) > 0) {
		target->spr->scale.x = -1;
		target->position.x += target->moveSpeed * GetTime().deltaTime;
	}
}

CharacterJump::CharacterJump(Character * target) : CharacterState(target)
{
}

void CharacterJump::Update()
{

}
