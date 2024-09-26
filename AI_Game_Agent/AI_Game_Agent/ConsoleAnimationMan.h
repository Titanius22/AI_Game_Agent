#pragma once

#include <iostream>
#include <windows.h>
#include "Scene.h"

namespace AI_Game_Agent
{
	class ConsoleAnimationMan
	{

	public:
		static void Create();
		//static void Destroy();

		//static void Update();
		static void RunAnimation_allTerrain();
		static void RunAnimation_noPlayer();
		static void RunAnimation_withPlayer();

		static void SetCycleTime(uint32_t newCycleTime);
		static uint32_t GetCycleTime();
		static void updateScreen(Scene& pNextScene);
		

		// Default constructor
		ConsoleAnimationMan(const ConsoleAnimationMan&) = delete;
		ConsoleAnimationMan& operator = (const ConsoleAnimationMan&) = delete;
		~ConsoleAnimationMan();

	private:

		static ConsoleAnimationMan* _pCam;
		const int BLUE = 1;
		const int GREEN = 2;
		const int RED = 4;
		const int WHITE = 15;

		uint32_t cycleTime;

		const COORD TOPLEFT_CURS_LOC = { 20, 5 };
		
		// Default constructor
		ConsoleAnimationMan();

		static ConsoleAnimationMan* privGetInstance();

		void clearScreen(int characterLength);
		void clearScreen();
		void changeColour(int colour);
		void showLoadingScreen();
		void showBlinkingLights();

		void loadNextTerrainScreen(int numCol, int numRow, std::string sceneData);
		//void loadNextFloorScreen(int numCol, std::string sceneData);

	};
}

