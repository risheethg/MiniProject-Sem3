#include "pch.h"
#include "Application.h"

#include "Log.h"
#include "Events/Event.h"
#include "Events/MouseEvent.h"
#include "Events/ApplicationEvent.h"

#include "Layers/GameLayer.h"




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
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		Log::Init();
		ENGINE_CORE_WARN("Logger Initialized!");

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_GameManager = new GameManager();
	}

	void Application::Shutdown()
	{
		//Delete
		delete m_GameManager;
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher ed(event);
		ed.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		
		if (event.m_Handled == false)
			gamelayer.OnEvent(event);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
			gamelayer.OnUpdate();
			m_GameManager->Run();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}
}