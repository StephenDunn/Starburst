#pragma once
#include "Renderer.h"
#include "Factories.h"
#include "ButtonState.h"

class GameContainer
{
private:
	Starburst::GameState* GState;
	Renderer* Rend;
	Starburst::GameFactory gameFactory;
	Input* Inputs;
public:
	GameContainer(Renderer* rend, Input* inputs);

	void SimulateGame();
};

