#include "winsocket.h"
#include "header.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	//DWORD dwThreadId = 1;
	//DWORD dwThrdParam = 1;
	//HANDLE hThread = CreateThread(NULL, 0, AntiThread, &dwThrdParam, 0, &dwThreadId);
	AntiThread();
	SocketFunc();
	return 0;
}