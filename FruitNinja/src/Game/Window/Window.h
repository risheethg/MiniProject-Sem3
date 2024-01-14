#pragma once

#pragma once

#include "pch.h"
#include "Events/Event.h"

namespace Engine {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Fruit Engine", unsigned int width = 1280,
			unsigned int height = 720) : Title(title), Width(width), Height(height)
		{
		}

	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		static Window* Create(const WindowProps& Props = WindowProps());
	};

}