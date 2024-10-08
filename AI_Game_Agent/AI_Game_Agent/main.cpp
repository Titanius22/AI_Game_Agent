// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ConsoleAnimationMan.h"
#include "GameEngine.h"
#include "SceneManager.h"


int main()
{

    AI_Game_Agent::ConsoleAnimationMan::Create();
    AI_Game_Agent::GameEngine::Create(AI_Game_Agent::GameEngine::PlayerType::HUMAN);
    AI_Game_Agent::SceneManager::Create();

    AI_Game_Agent::GameEngine::Run();


    //AI_Game_Agent::ConsoleAnimationMan::RunAnimation_allTerrain();
    //AI_Game_Agent::ConsoleAnimationMan::RunAnimation_noPlayer();
    //AI_Game_Agent::ConsoleAnimationMan::RunAnimation_withPlayer();

    //std::cout << "hello world";
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