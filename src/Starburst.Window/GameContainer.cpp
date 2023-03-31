#include "GameContainer.h"
#define IsButtonDown(b) Inputs->Buttons[b].IsDown
#define IsButtonPressed(b) Inputs->Buttons[b].IsDown && Inputs->Buttons[b].Changed

GameContainer::GameContainer(Renderer* rend, Input* inputs)
{
	Rend = rend;
	GState = gameFactory.GameStateFactory();
	Inputs = inputs;
}

void GameContainer::SimulateGame()
{
    Rend->ClearScreen(0x000000);


    if (IsButtonPressed(ButtonUp)) {
        Rend->DrawRectangle(-5, 10, 15, 15, 0x22ff44);
    }
    if (IsButtonDown(ButtonUp)) {
        Rend->DrawRectangle(-5, 10, 10, 10, 0x11ff22);
    }



    Rend->DrawRectangle(-25, -30, 10, 5, 0xff0022);
    Rend->DrawRectangle(70, 7, 10, 4, 0xffff00);

    int gridHeight = GState->GetGridHeight();
    int gridWidth = GState->GetGridWidth();

    Rend->DrawGrid(gridWidth, gridHeight, 0x0000ff);

    if (IsButtonPressed(ButtonUp)) {
        GState->Tick(Starburst::Up);
    }
    else if (IsButtonPressed(ButtonDown)) {
        GState->Tick(Starburst::Down);
    }
    else if (IsButtonPressed(ButtonLeft)) {
        GState->Tick(Starburst::Left);
    }
    else if (IsButtonPressed(ButtonRight)) {
        GState->Tick(Starburst::Right);
    }


}
