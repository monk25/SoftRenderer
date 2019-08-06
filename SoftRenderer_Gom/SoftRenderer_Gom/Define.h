#pragma once
#include "pch.h"
#include "Math.h"

#if defined(DEBUG) | defined(_DEBUG)
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#define FORCEINLINE __forceinline;

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