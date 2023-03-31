#include "pch.h"
#include "Factories.h"

Starburst::GameState* Starburst::GameFactory::GameStateFactory() {
    Starburst::GameState* gs = new Starburst::GameState(10, 10);


    gs->AddEntity(1, 1, Starburst::EntityType::Enemy, Starburst::Down);
    gs->AddEntity(9, 1, Starburst::EntityType::Enemy, Starburst::Right);
    gs->AddEntity(5, 5, Starburst::EntityType::Player, Starburst::Down);
    gs->AddEntity(5, 4, Starburst::EntityType::Wall, Starburst::None);
    gs->AddEntity(5, 3, Starburst::EntityType::Wall, Starburst::None);
    gs->AddEntity(5, 2, Starburst::EntityType::Wall, Starburst::None);
    gs->AddEntity(5, 1, Starburst::EntityType::Wall, Starburst::None);

    return gs;
}
