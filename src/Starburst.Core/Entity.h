#pragma once
#include <tuple>
#include <vector>
#include "EntityType.h"
#include "Direction.h"

namespace Starburst {
	class Entity
	{
	private:
		int GridX;
		int GridY;
		int NewGridX;
		int NewGridY;
		Starburst::EntityType Identity;
	public:
		Entity();
		Entity(int startX, int startY, Starburst::EntityType type);
		Entity(int startX, int startY, Starburst::EntityType type, Starburst::Direction direction);
		Starburst::Direction Direction;
		Starburst::EntityType Identify();
		std::tuple<int, int> GetPosition();
		std::tuple<int, int> GetNewPosition();
		void Move(Starburst::Direction input);
		void SetPosition();
		void ResetPosition();
		void ReverseDirection();
	};
}