#pragma once

class Character;

class CharacterState
{
public:
	CharacterState(Character* target);
	virtual ~CharacterState();

	virtual void Begine() {}
	virtual void Update() {}
	virtual void End() {}

	Character* target;
};

class CharacterIdle :
	public CharacterState
{
public:
	CharacterIdle(Character* target);

	void Update() override;
};

class CharacterMove :
	public CharacterState
{
public:
	CharacterMove(Character* target);

	void Update() override;
};

class CharacterJump :
	public CharacterState
{
public:
	CharacterJump(Character* target);

	void Update() override;
};