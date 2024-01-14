#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Events/Event.h"

namespace Engine {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "Fruit Ninja", unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height) {}
	};

	class Window
	{
		using EventCallBackFn = std::function<void(Event&)>;
	public:
		Window(const WindowProps& props);
		~Window();

		inline unsigned int GetWidth() const { return m_Data.Width; }
		inline unsigned int GetHeight() const { return m_Data.Height; }
	

		void OnUpdate();
		inline void SetEventCallBack(const EventCallBackFn& callback) { m_Data.EventCallBack = callback; }

		static Window* Create(const WindowProps& props = WindowProps());
	private:
		GLFWwindow* m_Window;
		
		void Init(const WindowProps& props);
		void Shutdown();

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			EventCallBackFn EventCallBack;
		};

		WindowData m_Data;
	};

}

