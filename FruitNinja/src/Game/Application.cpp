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

	float Application::s_DeltaTime = 0;

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

		m_GameManager = new GameManager();

		//Delta Time 
		m_LastFrame = 0;
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
			//Delta time/////
			m_CurrentFrame = (float)glfwGetTime();
			Application::s_DeltaTime = m_CurrentFrame - m_LastFrame;
			m_LastFrame = m_CurrentFrame;
			////////////////

			m_Window->OnUpdate();
			gamelayer.OnUpdate();
			m_GameManager->OnUpdate();
			m_GameManager->Render();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}
}