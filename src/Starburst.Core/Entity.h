#pragma once
#include <tuple>
#include <vector>
#include "EntityType.h"
#include "Input.h"

namespace Starburst {
	class Entity
	{
	private:
		int GridX;
		int GridY;
		Starburst::EntityType Identity;
	public:
		Entity();
		Entity(int startX, int startY, Starburst::EntityType type);
		Starburst::EntityType Identify();
		std::tuple<int, int> GetPosition();
		void Move(Starburst::Input input, std::vector<Entity> &entities);
	};
}