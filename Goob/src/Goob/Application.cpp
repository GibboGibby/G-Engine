#include "gbpch.h"
#include "Application.h"

#include "Goob/Events/ApplicationEvent.h"
#include "Goob/Log.h"

#include <iostream>

namespace Goob
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			GOOB_TRACE("({}) - Category Application", e);
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
				break;
			}
		}
	}
}