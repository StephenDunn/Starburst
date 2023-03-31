#pragma once
#include "GameState.h"
namespace Starburst {
    class GameFactory {
    public:
        Starburst::GameState* GameStateFactory();
    };
}