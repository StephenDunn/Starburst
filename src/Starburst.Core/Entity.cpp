#include "pch.h"
#include "Entity.h"
#include <tuple>
#include <vector>
#include "Input.h"
namespace Starburst {
	Entity::Entity(int startX, int startY, Starburst::EntityType type)
	{
		GridX = startX;
		GridY = startY;
		Identity = type;
	}

	Entity::Entity() {}

	Starburst::EntityType Entity::Identify()
	{
		return Identity;
	}

	std::tuple<int, int> Entity::GetPosition()
	{
		return std::make_tuple(GridX, GridY);
	}
	void Entity::Move(Starburst::Input input, std::vector<Entity>& entities)
	{
		if (input == Starburst::Up) {
			GridY--;
		}
		else if (input == Starburst::Down) {
			GridY++;
		}
		else if (input == Starburst::Left) {
			GridX++;
		}
		else if (input == Starburst::Right) {
			GridX--;
		}
	}
}
