#include "pch.h"
#include "Application.h"

#include "Log.h"
#include "Events/Event.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

#include "Layers/GameLayer.h"
#include "Renderer/Shader.h"

#include "stb_image.h"

#include "Gameplay/Pastry.h"

#include <glad/glad.h>

namespace Engine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		Init();
	}

	Application::~Application()
	{
		Shutdown();
	}

	void Application::Init()
	{
		Log::Init();
		ENGINE_CORE_WARN("Logger Initialized!");

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		bg = new Background("res/images/background_res_ref.jpg");
	}

	void Application::Shutdown()
	{
		delete bg;
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher ed(event);
		ed.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
		if (event.m_Handled == false)
			gamelayer.OnEvent(event);

		//ENGINE_TRACE(event.ToString());
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			bg->Draw();

			m_Window->OnUpdate();
			gamelayer.OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}
}