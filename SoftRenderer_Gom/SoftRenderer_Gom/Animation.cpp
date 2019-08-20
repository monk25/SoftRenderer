#include "pch.h"
#include "Animation.h"
#include "Asset.h"
#include "Time.h"

Animation::Animation(const string& path, int frameNum, int fps, bool loop)
	: fps(fps), loop(loop)
{
	for (int i = 0; i < frameNum; i++) {
		textures.push_back(Asset::GetInstance().GetTexture(path + ".png"));
	}
	texture = textures[0];
}


Animation::~Animation()
{
}

void Animation::Update()
{
	Sprite::Update();

	currentFrame += fps * GetTime().deltaTime;

	if (int(currentFrame) >= textures.size()) {
		if (loop)
			currentFrame = 0;
		else
			currentFrame = textures.size() - 1;
	}

	texture = textures[int(currentFrame)];
}
