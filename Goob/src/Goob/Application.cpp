#include "gbpch.h"
#include "Application.h"

#include "Goob/Events/ApplicationEvent.h"
#include "Goob/Log.h"

#include <iostream>

#include <GLFW/glfw3.h>

namespace Goob
{

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
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
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}