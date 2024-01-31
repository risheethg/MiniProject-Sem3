#pragma once
#include "pch.h"

namespace Engine {
	
	class Timer
	{
	public:	
		
		void Start()
		{
			m_StartTime = glfwGetTime();
		}

		bool HasElapsed(float seconds)
		{
			float CurrentTime = glfwGetTime();
			float delta = CurrentTime - m_StartTime;
			if (delta >= seconds)
			{
				m_StartTime = glfwGetTime();
				return true;
			}
			return false;
		}

		bool HasElapsedCallback(float seconds, std::function<void()> callback)
		{
			float CurrentTime = glfwGetTime();
			float delta = CurrentTime - m_StartTime;
			if (delta >= seconds)
			{
				callback();
				m_StartTime = glfwGetTime();
				return true;
			}
			return false;
		}
	private:
		float m_StartTime;
	};

}