#include "pch.h"
#include "BasicEnemy.h"
#include "Direction.h"

namespace Starburst {
	std::tuple<int, int> BasicEnemy::GetPosition()
	{
		return Entity::GetPosition();
	}
	BasicEnemy::BasicEnemy(int startX, int startY, Starburst::Direction direction)
	{
		BasicEnemy(startX, startY);
		Direction = direction;
	}
}
