#pragma once

#include <GLFW/glfw3.h>
#include "Window.h"

namespace Engine {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const { return m_Data.Width; }
		inline unsigned int GetHeight() const { return m_Data.Height; }


		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallBack = callback; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;

			EventCallbackFn EventCallBack;
		};

		WindowData m_Data;
	};

}
