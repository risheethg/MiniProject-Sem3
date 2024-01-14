#pragma once

#include "Events/Event.h"
#include "Window/Window.h"

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
	private:
		bool m_Running = true;
		std::unique_ptr<Window> m_Window;

		static Application* s_Instance;
	};

}