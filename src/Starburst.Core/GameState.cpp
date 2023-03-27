#include "pch.h"
#include "GameState.h"

namespace Starburst {
	GameState::GameState(int gridHeight, int gridWidth) {
		GridHeight = gridHeight;
		GridWidth = gridWidth;
	}
	void GameState::AddEntity(Starburst::Entity entity)
	{
		auto entityPosition = entity.GetPosition();
		bool free = true;
		for (auto& ent : Entities)
		{
			auto entPosition = ent.GetPosition();
			if (std::get<0>(entPosition) == std::get<0>(entityPosition) && std::get<1>(entPosition) == std::get<1>(entityPosition)) {
				free = false;
			}
		}

		if (free) {
			if (entity.Identify() == Starburst::Player) {
				Player = entity;
			}
			else {
				Entities.push_back(entity);
			}
		}
	}
	void GameState::Tick(Starburst::Input input)
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
	}
}