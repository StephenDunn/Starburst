// Starburst.Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <..\Starburst.Core\GameState.h>
#include <..\Starburst.Core\EntityType.h>
#include <..\Starburst.Core\BasicEnemy.h>
#include <..\Starburst.Core\Direction.h>
#include <..\Starburst.Core\Status.h>
#include <TypeInfo>
#include "Utilities.h"

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27

int main()
{
    Starburst::GameState* gs = new Starburst::GameState(10, 5);


    gs->AddEntity(1, 1, Starburst::EntityType::Enemy, Starburst::Down);
    gs->AddEntity(9, 1, Starburst::EntityType::Enemy, Starburst::Right);
    gs->AddEntity(5, 5, Starburst::EntityType::Player, Starburst::Down);
    gs->AddEntity(5, 4, Starburst::EntityType::Wall, Starburst::None);
    gs->AddEntity(5, 3, Starburst::EntityType::Wall, Starburst::None);
    gs->AddEntity(5, 2, Starburst::EntityType::Wall, Starburst::None);
    gs->AddEntity(5, 1, Starburst::EntityType::Wall, Starburst::None);

    while(true) {
        Utilities::clear_screen();

        if (gs->GetGameStatus() == Starburst::GameOver) {
            std::cout << "****************Game Over****************";
            break;
        }


        auto board = gs->WriteGameState();

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                std::cout << board[i][j];
            }
            std::cout << "\n";
        }

        bool keyInvalid = true;
        int keyPress;
        while (keyInvalid) {
            keyPress = _getch();
            if (keyPress == KB_UP || keyPress == KB_DOWN || keyPress == KB_LEFT || keyPress == KB_RIGHT || keyPress == KB_ESCAPE) {
                keyInvalid = false;
            }
        }

        switch (keyPress) {
        case KB_UP:
            gs->Tick(Starburst::Up);
            break;
        case KB_DOWN:
            gs->Tick(Starburst::Down);
            break;
        case KB_LEFT:
            gs->Tick(Starburst::Left);
            break;
        case KB_RIGHT:
            gs->Tick(Starburst::Right);
            break;
        case KB_ESCAPE:
            return 0;

        }
    }

    _getch();
}


