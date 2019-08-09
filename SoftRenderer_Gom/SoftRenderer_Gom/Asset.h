#pragma once
#include "Define.h"
#include "Singleton.h"

class Texture;

class Asset :
	public Singleton<Asset>
{
public:
	Asset();
	~Asset();

public:
	void Initialize();
	void Dispose();

	Texture* GetTexture(string filename);
	inline ULONG GetPixel(int x, int y, Texture* texure);

private:
	Texture* OpenBMP(Texture* texture, string filename);

private:
	map<string, Texture*> textures;
};

inline Asset& GetAsset() {
	return Asset::GetInstance();
}