#include "Entity.h"
#include "BasicEnemy.h"
#include "Direction.h"
#include <vector>
namespace Starburst {
	class GameState
	{
		int GridHeight;

		int GridWidth;

		std::vector<Starburst::Entity> Entities;

		Starburst::Entity Player;

		bool CanNewEntityBePlaced(Starburst::Entity& oldEntity, Starburst::Entity& newEntity);

	public:

		GameState(int gridHeight, int gridWidth);

		void AddEntity(Starburst::Entity entity);
		void AddBasicEnemy(Starburst::BasicEnemy entity);

		void Tick(Starburst::Direction input);
	};
}