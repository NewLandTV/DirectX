#include "AppWindow.h"

int main(void)
{
	AppWindow app;

	if (app.Init())
	{
		while (app.IsRun())
		{
			app.Broadcast();
		}
	}

	return 0;
}