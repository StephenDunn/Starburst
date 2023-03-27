#pragma once
#include "Entity.h"
#include "Direction.h"
namespace Starburst {
	class BasicEnemy : public Entity
	{
	private:
		BasicEnemy(int startX, int startY) : Entity(startX, startY, Starburst::Enemy) {};

		public:
			Starburst::Direction Direction;
			std::tuple<int, int> GetPosition();
			
			BasicEnemy(int startX, int startY, Starburst::Direction direction);
	};
}