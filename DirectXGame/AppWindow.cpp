// Creation Date: 2022.09.25. Sun, 09:09:06
// Modified Date: 2022.09.25. Sun, 10:17:56
#include "AppWindow.h"

AppWindow::AppWindow()
{

}

AppWindow::~AppWindow()
{

}

void AppWindow::OnCreate()
{
	Window::OnCreate();
	GraphicsEngine::Get()->Init();
}

void AppWindow::OnUpdate()
{
	Window::OnUpdate();
}

void AppWindow::OnDestroy()
{
	Window::OnDestroy();
	GraphicsEngine::Get()->Release();
}
