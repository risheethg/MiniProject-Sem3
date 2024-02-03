#pragma once

namespace Engine {

	class Random
	{
	public:
		static int GetModel(int x);
		static glm::vec3 GetPosition(int x);
		static glm::vec3 GetAnimation(int x);
		static int GetSpawnTime(int x);
	};

}

