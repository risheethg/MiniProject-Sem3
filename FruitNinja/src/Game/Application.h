#pragma once

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Window/Window.h"

#include "Layers/GameLayer.h"

#include "GameManager/GameManager.h"

namespace Engine {

	class Application
	{
	public:
		Application();
		~Application();

		void Init();
		void Shutdown();

		void OnEvent(Event& event);

		void Run();

		static float s_DeltaTime;
	private:
		bool m_Running = true;
		
		std::unique_ptr<Window> m_Window;

		static Application* s_Instance;
		GameManager* m_GameManager;

		GameLayer gamelayer;

		bool OnWindowClose(WindowCloseEvent& event);

		float m_CurrentFrame, m_LastFrame;
	};

}
