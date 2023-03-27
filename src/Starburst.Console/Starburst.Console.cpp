// Starburst.Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <..\Starburst.Core\GameState.h>
#include <..\Starburst.Core\EntityType.h>

int main()
{
    std::cout << "Hello World!\n";
    Starburst::GameState* gs = new Starburst::GameState(10, 10);

    gs->AddEntity(Starburst::Entity(1, 1, Starburst::EntityType::Enemy));
    gs->AddEntity(Starburst::Entity(5, 5, Starburst::EntityType::Player));

    gs->Tick(Starburst::Down);
    gs->Tick(Starburst::Down);
    gs->Tick(Starburst::Right);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
