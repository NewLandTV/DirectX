// Creation Date: 2022.09.25. Sun, 09:09:04
// Modified Date: 2022.09.25. Sun, 10:00:13
#ifndef __APP_WINDOW_H__
#define __APP_WINDOW_H__

#include "Window.h"
#include "GraphicsEngine.h"

class AppWindow : public Window
{
public:
	AppWindow();
	~AppWindow();

	// Inherited via Window
	virtual void OnCreate() override;
	virtual void OnUpdate() override;
	virtual void OnDestroy() override;
};

#endif
