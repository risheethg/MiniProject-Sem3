#pragma once

namespace Engine {

	class Game
	{
	public:
		Game();
		~Game();

		void Init();
		void Shutdown();

		void Run();
	private:
		bool m_Running = true;
	};

}
