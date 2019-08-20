#pragma once
#include "Sprite.h"

class Animation :
	public Sprite
{
public:
	Animation(const string& path, int frameNum, int fps = 20, bool loop = true);
	~Animation();

	void Update() override;

public:
	vector<Texture*> textures;
	float currentFrame;
	float fps;
	bool loop;
};

