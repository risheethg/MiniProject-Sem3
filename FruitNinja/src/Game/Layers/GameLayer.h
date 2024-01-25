#pragma once

#include "Events\Event.h"

namespace Engine {

	class GameLayer
	{
	public:
		GameLayer();
		~GameLayer();

		void OnUpdate();
		void OnEvent(Event& e);

	private:
		bool m_Paused = false;
	};

}

