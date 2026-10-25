// Creation Date: 2022.09.25. Sun, 08:35:41
// Modified Date: 2022.09.25. Sun, 10:26:38
#include "Window.h"

Window* window = nullptr;

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		// Event fired when the window will be created
		window->OnCreate();

		break;
	case WM_DESTROY:
		// Event fired when the window will be destroyed
		window->OnDestroy();

		PostQuitMessage(0);

		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return NULL;
}

Window::Window()
{

}

Window::~Window()
{

}

bool Window::Init()
{
	WNDCLASSEX wc;

	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"MyWindowClass";
	wc.lpszMenuName = L"";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProc;

	// if the registration of class will fail, the function will return false
	if (!RegisterClassEx(&wc))
	{
		return false;
	}

	if (!window)
	{
		window = this;
	}

	// Creation of the window
	hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"DirectX Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);

	// if the creation fail return false
	if (!hWnd)
	{
		return false;
	}

	// show up the window
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// set this flag to true to indicate that the window is initialized and running
	isRun = true;

	return true;
}

bool Window::Broadcast()
{
	MSG msg;

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);

		DispatchMessage(&msg);
	}

	window->OnUpdate();

	Sleep(0);

	return true;
}

bool Window::Release()
{
	// Destroy the window
	if (!DestroyWindow(hWnd))
	{
		return false;
	}

	return true;
}

bool Window::IsRun()
{
	return isRun;
}

void Window::OnDestroy()
{
	isRun = false;
}
