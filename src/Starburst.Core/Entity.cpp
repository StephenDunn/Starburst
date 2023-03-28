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
		NewGridX = startX;
		NewGridY = startY;
		Identity = type;
		Direction = Starburst::None;
	}

	Entity::Entity(int startX, int startY, Starburst::EntityType type, Starburst::Direction direction)
	{
		GridX = startX;
		GridY = startY;
		NewGridX = startX;
		NewGridY = startY;
		Identity = type;
		Direction = direction;


		//auto* glf = new Starburst::Entity(5, 5, Starburst::EntityType::Enemy, Starburst::Down);

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
	std::tuple<int, int> Entity::GetNewPosition()
	{
		return std::make_tuple(NewGridX, NewGridY);
	}
	void Entity::Move(Starburst::Direction input)
	{
		bool canMove = true;
		if (input == Starburst::Up) {
			NewGridY = GridY - 1;
		}
		else if (input == Starburst::Down) {
			NewGridY = GridY + 1;
		}
		else if (input == Starburst::Left) {
			NewGridX = GridX - 1;
		}
		else if (input == Starburst::Right) {
			NewGridX = GridX + 1;
		}
	}
	void Entity::SetPosition()
	{
		GridX = NewGridX;
		GridY = NewGridY;
	}
	void Entity::ResetPosition()
	{
		NewGridX = GridX;
		NewGridY = GridY;
	}
	void Entity::ReverseDirection()
	{
		if (Direction == Starburst::Up) {
			Direction = Starburst::Down;
		}
		else if (Direction == Starburst::Down) {
			Direction = Starburst::Up;
		}
		else if (Direction == Starburst::Left) {
			Direction = Starburst::Right;
		}
		else if (Direction == Starburst::Right) {
			Direction = Starburst::Left;
		}
	}
}
