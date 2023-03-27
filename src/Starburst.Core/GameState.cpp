#include "pch.h"
#include "GameState.h"
#include "BasicEnemy.h"
#include <TypeInfo>

namespace Starburst {
	bool GameState::CanNewEntityBePlaced(Starburst::Entity& oldEntity, Starburst::Entity& newEntity)
	{
		auto newEntityPosition = newEntity.GetPosition();
		auto oldEntityPosition = oldEntity.GetPosition();
		if (std::get<0>(newEntityPosition) == std::get<0>(oldEntityPosition) && std::get<1>(newEntityPosition) == std::get<1>(oldEntityPosition)) {
			return false;
		}

		return true;
	}
	GameState::GameState(int gridHeight, int gridWidth) {
		GridHeight = gridHeight;
		GridWidth = gridWidth;
	}
	void GameState::AddEntity(Starburst::Entity entity)
	{
		bool free = true;
		for (auto& ent : Entities)
		{
			if (!CanNewEntityBePlaced(ent, entity)) {
				free = false;
			}
		}

		if (free) {
			if (entity.Identify() == Starburst::Player) {
				Player = entity;
			}
			else
			{
				Entities.push_back(entity);
			}
		}
	}

	void GameState::Tick(Starburst::Direction input)
	{
		switch (input) {
		case Up:
			Player.Move(input, Entities);
			break;
		case Down:
			Player.Move(input, Entities);
			break;
		case Left:
			Player.Move(input, Entities);
			break;
		case Right:
			Player.Move(input, Entities);
			break;
		}

		for (Starburst::Entity ent : Entities)
		{
			ent.Move(ent.Direction, Entities);
		}
	}
}