#pragma once
#include "Define.h"
#include "Singleton.h"

struct Bitmap {
	~Bitmap() {
		delete[] data;
	}
	string name;
	int width, height;
	ULONG* data;
};

class Asset :
	public Singleton<Asset>
{
public:
	Asset();
	~Asset();

public:
	void Initialize();
	void Dispose();

	Bitmap* GetBMP(string filename);
	inline ULONG GetPixel(int x, int y, Bitmap* bmp) {
		return bmp->data[y * bmp->width + x];
	}
	inline ULONG GetPixel(int x, int y, string filename) {
		return GetPixel(x, y, GetBMP(filename));
	}

private:
	Bitmap* OpenBMP(string filename);

private:
	map<string, Bitmap*> BMPs;
};

inline Asset& GetAsset() {
	return Asset::GetInstance();
}