#include "pch.h"
#include "Random.h"

namespace Engine {

	int Random::GetModel(int x)
	{
		srand(time(0));
		return (rand() % x);
	}

	float Random::GetPosition(int x)
	{
		srand(time(0));
		return (1 + rand() % x);
	}

	int Random::GetSpawnTime(int x)
	{
		srand(time(0));
		return (1 + rand() % x);
	}

	int Random::GetSpawnForce(int x)
	{
		srand(time(0));
		return (1 + rand() % x);
	}
}