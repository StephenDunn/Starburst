#include "pch.h"
#include "Entity.h"
#include <tuple>
#include <vector>
#include "Direction.h"
namespace Starburst {
	Entity::Entity(int startX, int startY, Starburst::EntityType type)
	{
		GridX = startX;
		GridY = startY;
		Identity = type;
	}

	Entity::Entity(int startX, int startY, Starburst::EntityType type, Starburst::Direction direction)
	{
		GridX = startX;
		GridY = startY;
		Identity = type;
		Direction = direction;
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
	void Entity::Move(Starburst::Direction input, std::vector<Entity>& entities)
	{
		bool canMove = true;
		if (input == Starburst::Up) {		

			for (Entity ent : entities)
			{
				auto entPosition = ent.GetPosition();
				if (std::get<0>(entPosition) == GridX && std::get<1>(entPosition) == GridY - 1) {
					canMove = false;
				}
			}

			if (canMove) {
				GridY--;
			}
			else {
				Direction = Starburst::Down;
			}
		}
		else if (input == Starburst::Down) {
			for (Entity ent : entities)
			{
				auto entPosition = ent.GetPosition();
				if (std::get<0>(entPosition) == GridX && std::get<1>(entPosition) == GridY + 1) {
					canMove = false;
				}
			}

			if (canMove) {
				GridY++;
			}
			else {
				Direction = Starburst::Up;
			}
		}
		else if (input == Starburst::Left) {
			for (Entity ent : entities)
			{
				auto entPosition = ent.GetPosition();
				if (std::get<0>(entPosition) == GridX + 1 && std::get<1>(entPosition) == GridY) {
					canMove = false;
				}
			}

			if (canMove) {
				GridY++;
			}

			else {
				Direction = Starburst::Right;
			}
		}
		else if (input == Starburst::Right) {
			for (Entity ent : entities)
			{
				auto entPosition = ent.GetPosition();
				if (std::get<0>(entPosition) == GridX - 1 && std::get<1>(entPosition) == GridY) {
					canMove = false;
				}
			}

			if (canMove) {
				GridX--;
			}
			else {
				Direction = Starburst::Left;
			}
		}
	}
}
