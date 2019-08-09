#pragma once
#include "pch.h"
#include "Math.h"

#if defined(DEBUG) | defined(_DEBUG)
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

using namespace std;
using namespace std::experimental::filesystem::v1;

const int ScreenWidth{ 1280 };
const int ScreenHeight{ 720 };
const bool FullScreen{ false };
const bool VsyncEnable{ true };
const float ScreenDepth{ 1000.0f };
const float ScreenNear{ 0.1f };

const float PI{ 3.1415926535897932f };
const float SMALL_NUMBER{ 1.e-8f };
const float KINDA_SMALL_NUMBER{ 1.e-4f };
const float BIG_NUMBER{ 3.4e+38f };

inline void SafeDelete(void* data) {
	if (data)
		delete data;
}

inline void SafeRelease(void* data) {
	if (data)
		delete data;
}

struct Rect : public RECT
{
public:
	Rect() { left = top = right = bottom = 0; }
	Rect(int left, int top, int right, int bottom) {
		this->left = left;
		this->top = top;
		this->right = right;
		this->bottom = bottom;
	}

	bool IntersectsRect(Rect rect) {
		Rect tmpRect;
		return IntersectRect(&tmpRect, this, &rect);
	}

	bool IntersectsRect(Rect rect, Vector2 pos) {
		Rect tmpRect;
		return IntersectRect(&tmpRect, this, &(rect.Offset(pos)));
	}

	Rect Offset(Vector2 pos) {
		Rect r = *this;
		r.right += pos.x;
		r.left += pos.x;
		r.top += pos.y;
		r.bottom += pos.y;
		return r;
	}

	int Width() {
		return right - left;
	}

	int Height() {
		return bottom - top;
	}

	Vector2Int Center() {
		return Vector2Int{ Width(), Height() } * 0.5f;
	}
};