// Creation Date: 2022.09.25. Sun, 08:35:39
// Modified Date: 2022.09.25. Sun, 10:26:44
#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Window
{
protected:
	HWND hWnd;

	bool isRun;

public:
	Window();
	~Window();

	// Initialize the window
	bool Init();
	bool Broadcast();

	// Release the window
	bool Release();
	bool IsRun();

	// EVENTS
	virtual void OnCreate() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnDestroy();
};

#endif
