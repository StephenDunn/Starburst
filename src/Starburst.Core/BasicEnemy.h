#pragma once
#include "Entity.h"
namespace Starburst {
	class BasicEnemy : public Entity
	{
		BasicEnemy(int startX, int startY) : Entity(startX, startY, Starburst::Enemy) {};
	};
}