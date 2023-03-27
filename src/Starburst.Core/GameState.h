#include "Entity.h"
#include "Input.h"
#include <vector>
namespace Starburst {
	class GameState
	{
		int GridHeight;

		int GridWidth;

		std::vector<Starburst::Entity> Entities;

		Starburst::Entity Player;

	public:

		GameState(int gridHeight, int gridWidth);

		void AddEntity(Starburst::Entity entity);

		void Tick(Starburst::Input input);
	};
}