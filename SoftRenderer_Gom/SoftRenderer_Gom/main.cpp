#include "pch.h"
#include "System.h"
#include "World.h"

#if defined(DEBUG) | defined(_DEBUG)
int main()
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdling, int iCmdshow)
#endif
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	World::GetInstance().Initialize(1280, 720);
	System::GetInstance().Run();
	World::GetInstance().Dispose();

	return 0;
}
