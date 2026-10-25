// Creation Date: 2022.09.25. Sun, 08:34:55
// Modified Date: 2022.09.25. Sun, 09:22:00
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
