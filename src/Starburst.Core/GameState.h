#include "Entity.h"
#include "BasicEnemy.h"
#include "Direction.h"
#include "Status.h"
#include <vector>
#include <string>

namespace Starburst {
	class GameState
	{
		int GridHeight;

		int GridWidth;

		std::vector<Starburst::Entity*> Entities;

		Starburst::Entity* Player;

		Starburst::Status GameStatus;

		bool CanNewEntityBePlaced(Starburst::Entity& oldEntity, Starburst::Entity& newEntity);
		bool CompareEntityPositions(std::tuple<int, int> entityA, std::tuple<int, int> entityB);

	public:

		GameState(int gridHeight, int gridWidth);

		void AddEntity(int startX, int startY, Starburst::EntityType type, Starburst::Direction direction);

		void Tick(Starburst::Direction input);

		Starburst::Status GetGameStatus();

		std::vector<std::vector<std::string>> WriteGameState();
	};
}