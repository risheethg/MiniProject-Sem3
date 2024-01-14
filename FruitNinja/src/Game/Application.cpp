#include "pch.h"
#include "Application.h"

#include "Log.h"


namespace Engine {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		Init();

		m_Window = std::unique_ptr<Window>(Window::Create({"Test", 1280, 720}));
		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
		Shutdown();
	}

	void Application::Init()
	{
		Log::Init();
		ENGINE_CORE_WARN("Logger Initialized!");
	}

	void Application::Shutdown()
	{
		/*
		glfw.shutdown()
		window.shutdown()
		sound.shutdown()
		*/
	}

	void Application::OnEvent(Event& event)
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}
}