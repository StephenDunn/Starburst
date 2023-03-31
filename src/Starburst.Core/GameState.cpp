#include "pch.h"
#include "GameState.h"
#include "BasicEnemy.h"
#include <TypeInfo>
#include <string>
#include <vector>

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

	bool GameState::CompareEntityPositions(std::tuple<int, int> oldEntity, std::tuple<int, int> newEntity)
	{
		if (std::get<0>(oldEntity) == std::get<0>(newEntity) && std::get<1>(oldEntity) == std::get<1>(newEntity)) {
			return true;
		}

		return false;
	}

	int GameState::GetGridWidth( )
	{
		return GridWidth;
	}

	int GameState::GetGridHeight( )
	{
		return GridHeight;
	}

	GameState::GameState(int gridHeight, int gridWidth) {
		GridHeight = gridHeight;
		GridWidth = gridWidth;
		Entities = {};
		GameStatus = Live;
	}

	void GameState::AddEntity(int startX, int startY, Starburst::EntityType type, Starburst::Direction direction)
	{
		Starburst::Entity* entity = new Starburst::Entity(startX, startY, type, direction);
		bool free = true;
		for (auto ent : Entities)
		{
			if (!CanNewEntityBePlaced(*ent, *entity)) {
				free = false;
				break;
			}
		}

		if (free) {
			if (entity->Identify() == Starburst::Player) {
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
			Player->Move(input);
			break;
		case Down:
			Player->Move(input);
			break;
		case Left:
			Player->Move(input);
			break;
		case Right:
			Player->Move(input);
			break;
		}

		auto playerNewPosition = Player->GetNewPosition();

		// Initial check to make sure player does not walk over enemy.
		for (Starburst::Entity* entB : Entities)
		{
			auto entBNewPosition = entB->GetNewPosition();
			if (CompareEntityPositions(playerNewPosition, entBNewPosition)) {
				auto entId = entB->Identify();
				if (entId == EntityType::Enemy) {
					GameStatus = Status::GameOver;
				}
				else if (entId == EntityType::Wall) {
					Player->ResetPosition();
				}
			}
		}

		if (std::get<0>(playerNewPosition) > GridHeight || std::get<1>(playerNewPosition) > GridWidth || std::get<0>(playerNewPosition) < 1 || std::get<1>(playerNewPosition) < 1) {
			Player->ResetPosition();
		}
		else {
			Player->SetPosition();
		}


		for (Starburst::Entity* ent : Entities)
		{
			ent->Move(ent->Direction);
		}

		for (Starburst::Entity* entA : Entities)
		{
			auto entANewPosition = entA->GetNewPosition();
			bool overlaps = false;
			for (Starburst::Entity* entB : Entities)
			{
				if (entA != entB) {
					auto entBNewPosition = entB->GetNewPosition();
					if (CompareEntityPositions(entANewPosition, entBNewPosition)) {
						overlaps = true;
					}
				}
			}

			if (std::get<0>(entANewPosition) > GridHeight || std::get<1>(entANewPosition) > GridWidth || std::get<0>(entANewPosition) < 1 || std::get<1>(entANewPosition) < 1) {
				overlaps = true;
			}

			if (overlaps) {
				entA->ResetPosition();
				entA->ReverseDirection();
			}
			else {
				entA->SetPosition();
			}
		}

		// Second check player collision check to make sure player does not land on the same tile as an enemy.
		for (Starburst::Entity* entB : Entities)
		{
			auto entBNewPosition = entB->GetNewPosition();
			if (CompareEntityPositions(playerNewPosition, entBNewPosition)) {
				auto entId = entB->Identify();
				if (entId == EntityType::Enemy) {
					GameStatus = Status::GameOver;
				}
			}
		}
	}
	Starburst::Status GameState::GetGameStatus()
	{
		return GameStatus;
	}
	std::vector<std::vector<std::string>> GameState::WriteGameState()
	{
		std::vector<std::vector<std::string>> gridArray(GridWidth, std::vector<std::string>(GridHeight));

		for (int i = 0; i < GridWidth; i++) {
			for (int j = 0; j < GridHeight; j++) {
				gridArray[i][j] = " - ";
			}
		}

		for (auto ent : Entities)
		{
			auto position = ent->GetPosition();
			if (ent->Identify() == EntityType::Enemy) {
				gridArray[std::get<1>(position) - 1][std::get<0>(position) - 1] = " @ ";
			}
			if (ent->Identify() == EntityType::Wall) {
				gridArray[std::get<1>(position) - 1][std::get<0>(position) - 1] = " W ";
			}
			if (ent->Identify() == EntityType::Player) {
				gridArray[std::get<1>(position) - 1][std::get<0>(position) - 1] = " X ";
			}
		}

		auto playerPosition = Player->GetPosition();
		gridArray[std::get<1>(playerPosition) - 1][std::get<0>(playerPosition) - 1] = " X ";

		return gridArray;
	}
}