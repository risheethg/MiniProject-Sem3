#include "pch.h"
#include "Random.h"

namespace Engine {

	int Random::GetModel(int x)
	{
		srand(time(0));
		return (rand() % x);
	}

	glm::vec3 Random::GetPosition(int x)
	{
		srand(time(0));
		return glm::vec3((1 + rand() % x), 0.0f, 0.0f);
	}

	int Random::GetSpawnTime(int x)
	{
		srand(time(0));
		return (1 + rand() % x);
	}

	glm::vec3 Random::GetAnimation(int x)
	{
		srand(time(0));
		return glm::vec3((float)(2 + rand() % x) / 10, (float)(2 + rand() % x) / 10, (float)(2 + rand() % x) / 10);
	}
}