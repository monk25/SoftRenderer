#include "pch.h"
#include "Asset.h"
#include "Texture.h"
#include "lodepng.h"


Asset::Asset()
{
}


Asset::~Asset()
{
}

void Asset::Initialize()
{
}

void Asset::Dispose()
{
	for (auto& iter : textures) {
		delete iter.second;
	}
}

Texture* Asset::OpenBMP(Texture* texture, string filename)
{
	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, filename.c_str(), "rb");
	if (!fp) return NULL;

	BITMAPFILEHEADER bmpfh;
	size_t size = fread(&bmpfh, 1, sizeof(BITMAPFILEHEADER), fp);
	if (size != sizeof(BITMAPFILEHEADER)) return NULL;

	BITMAPINFOHEADER bmpih;
	size = fread(&bmpih, 1, sizeof(BITMAPINFOHEADER), fp);
	if (size != sizeof(BITMAPINFOHEADER)) return NULL;

	int bytePerLine = ((bmpih.biWidth * 3) + 3) &~3;
	size_t imageSize = bytePerLine * bmpih.biHeight;
	BYTE *pBmp = new BYTE[imageSize];
	if (!pBmp) return NULL;

	size = fread(pBmp, 1, imageSize, fp);
	if (size != imageSize)
	{
		delete[] pBmp;
		return NULL;
	}

	fclose(fp);

	ULONG *pImageBuf = new ULONG[bmpih.biWidth * bmpih.biHeight];

	for (int j = 0; j < bmpih.biHeight; j++)
	{
		for (int i = 0; i < bmpih.biWidth; i++)
		{
			int ColorIndex = bytePerLine * (bmpih.biHeight - j - 1) + (i * 3);
			BYTE BValue = pBmp[ColorIndex];
			BYTE GValue = pBmp[ColorIndex + 1];
			BYTE RValue = pBmp[ColorIndex + 2];

			int DestIndex = j * bmpih.biWidth + i;

			BYTE *CurrentColor = (BYTE *)(pImageBuf + DestIndex);
			pImageBuf[DestIndex] = RGB(BValue, GValue, RValue);
		}
	}

	if (pBmp)
	{
		delete[] pBmp;
	}

	texture->texture = pImageBuf;
	texture->width = bmpih.biWidth;
	texture->height = bmpih.biHeight;
	texture->name = filename;
	return texture;
}

Texture * Asset::OpenPng(Texture * texture, string filename)
{
	//texture->png = new unsigned char[1024];
	lodepng_decode32_file(&texture->png, 
		(unsigned int*)(&texture->width), 
		(unsigned int*)(&texture->height), 
		filename.c_str());
	texture->name = filename;

	return texture;
}

Texture * Asset::GetTexture(string filename)
{
	filename = "../Resource/" + filename;
	if (!exists(filename)) {
		cout << "파일 없음 : " << filename << endl;
	}

	if (!textures[filename]) {
		textures[filename] = new Texture;
		string extension = filename.substr(filename.find_last_of('.') + 1);
		if (extension == "bmp") {
			OpenBMP(textures[filename], filename);
		}
		else if (extension == "png") {
			OpenPng(textures[filename], filename);
		}
		else {
			cout << extension << " 에 맞는 load 형식 없음" << endl;
		}

		textures[filename]->Initialize();
	}

	return textures[filename];
}

inline ULONG GetPixel(int x, int y, Texture* texure) {
	return texure->texture[y * texure->width + x];
}
