#include "ConsoleAnimationMan.h"
#include "Scene.h"
#include <cassert>
#include <iomanip>

namespace AI_Game_Agent
{
	ConsoleAnimationMan* ConsoleAnimationMan::_pCam = nullptr;
	
	ConsoleAnimationMan::ConsoleAnimationMan()
	{
		this->cycleTime = 1000;
	}

	ConsoleAnimationMan::~ConsoleAnimationMan()
	{
		ConsoleAnimationMan* pCAM = ConsoleAnimationMan::privGetInstance();
		delete pCAM;
	}

	ConsoleAnimationMan* ConsoleAnimationMan::privGetInstance(void)
	{
		assert(_pCam != nullptr);

		return _pCam;
	}

	void ConsoleAnimationMan::Create()
	{
		assert(_pCam == nullptr);

		_pCam = new ConsoleAnimationMan();
		assert(_pCam);
	}

	void ConsoleAnimationMan::RunAnimation_allTerrain()
	{
		ConsoleAnimationMan* pCAM = ConsoleAnimationMan::privGetInstance();
		assert(pCAM);

		uint8_t startingTerrain[] = { 1,0,0,0,0,1,0,0,0,0,1,1};
		uint8_t startingFloor[] = { 1,1,0,1 };
		Scene scene(4, 4, Scene::SceneType::ACTIVE);
		scene.SetTerrain(4, 3, startingTerrain);
		scene.SetFloor(startingFloor);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);
		
		scene.ProgressScene();
		uint8_t lastColTerrain[] = { 0, 1, 0 };
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 1;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 1;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 1;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 1;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		pCAM->clearScreen();
		std::cout << "\n\n\n";
	}

	void ConsoleAnimationMan::RunAnimation_noPlayer()
	{
		ConsoleAnimationMan* pCAM = ConsoleAnimationMan::privGetInstance();
		assert(pCAM);

		uint8_t startingTerrain[] = { 0,0,0,0,0,0,0,0,0,0,1,0 };
		uint8_t startingFloor[] = { 1,1,1,1 };
		Scene scene(4, 4, Scene::SceneType::ACTIVE);
		scene.SetTerrain(4, 3, startingTerrain);
		scene.SetFloor(startingFloor);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		uint8_t lastColTerrain[] = { 0, 0, 0 };
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 1;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 1;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 1;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		pCAM->clearScreen();
		std::cout << "\n\n\n";
	}

	void ConsoleAnimationMan::RunAnimation_withPlayer()
	{
		ConsoleAnimationMan* pCAM = ConsoleAnimationMan::privGetInstance();
		assert(pCAM);

		uint8_t startingTerrain[] = { 0,0,0,0,0,0,0,0,0,0,1,0 };
		uint8_t startingFloor[] = { 1,1,1,1 };
		Scene scene(4, 4, Scene::SceneType::ACTIVE);
		scene.SetTerrain(4, 3, startingTerrain);
		scene.SetFloor(startingFloor);
		scene.SetPlayer(Scene::PlayerPos::NORMAL);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		uint8_t lastColTerrain[] = { 0, 0, 0 };
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		scene.SetPlayer(Scene::PlayerPos::NORMAL);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 1;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		scene.SetPlayer(Scene::PlayerPos::JUMP);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		scene.SetPlayer(Scene::PlayerPos::NORMAL);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		scene.SetPlayer(Scene::PlayerPos::NORMAL);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 1;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 1;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		scene.SetPlayer(Scene::PlayerPos::DUCK);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		scene.SetPlayer(Scene::PlayerPos::NORMAL);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		scene.SetPlayer(Scene::PlayerPos::NORMAL);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		scene.SetPlayer(Scene::PlayerPos::DIVE);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, Scene::SOLID);
		scene.SetPlayer(Scene::PlayerPos::NORMAL);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		pCAM->clearScreen();
		std::cout << "\n\n\n";
	}

	void ConsoleAnimationMan::clearScreen(int characterLength) {
		for (int i = 0; i < characterLength; i++) {
			std::cout << "\b";
		}
	}

	void ConsoleAnimationMan::clearScreen() {
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;

		GetConsoleScreenBufferInfo(console, &screen);
		FillConsoleOutputCharacterA(
			console, ' ', screen.dwSize.X * screen.dwSize.Y, TOPLEFT_CURS_LOC, &written
		);
		FillConsoleOutputAttribute(
			console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, TOPLEFT_CURS_LOC, &written
		);
		SetConsoleCursorPosition(console, TOPLEFT_CURS_LOC);
	}

	//void ConsoleAnimationMan::loadNextTerrainScreen(Scene* sceneData)
	//{
	//	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	//	
	//	clearScreen();
	//	COORD tempCursorStart;
	//	uint8_t rowNum;

	//	uint8_t numOfRows = sceneData->GetNumOfRows();
	//	uint8_t numOfCols = sceneData->GetNumOfCols();

	//	for (rowNum =0; rowNum < numOfRows; rowNum++)
	//	{
	//		tempCursorStart = {TOPLEFT_CURS_LOC.X, short(TOPLEFT_CURS_LOC.Y + rowNum)};
	//		SetConsoleCursorPosition(console, tempCursorStart);
	//		std::cout << sceneData->GetSceneRow_string(rowNum) << '\n';
	//	}

	//	//tempCursorStart = { TOPLEFT_CURS_LOC.X, short(TOPLEFT_CURS_LOC.Y + i) };
	//	//SetConsoleCursorPosition(console, tempCursorStart);
	//	//for (i = 0; i < numOfCols; i++)
	//	//{
	//	//	std::cout << '-';
	//	//}
	//}

	void ConsoleAnimationMan::changeColour(int colour) {
		HANDLE hConsole;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, colour);
	}

	void ConsoleAnimationMan::showLoadingScreen() {
		int i;
		std::string closed = "- - -", open = "* * *";
		int colour[] = { RED, GREEN, BLUE };

		clearScreen();

		std::cout << closed << '\n';
		std::cout << closed << '\n';
		std::cout << closed << '\n';
		std::cout << closed << '\n';

		for (i = 0; i < 3; i++) {
			Sleep(1000);

			clearScreen();
			changeColour(colour[i]);

			std::cout << open << '\n';
			std::cout << open << '\n';
			std::cout << open << '\n';

			Sleep(1000);

			clearScreen();
			changeColour(WHITE);

			std::cout << closed << '\n';
			std::cout << closed << '\n';
		}

		clearScreen();
		changeColour(WHITE);
	}

	void ConsoleAnimationMan::showBlinkingLights() {
		changeColour(RED);
		std::cout << "BLINK";
		Sleep(1000);

		changeColour(GREEN);
		std::cout << "ING";
		Sleep(1000);

		changeColour(BLUE);
		std::cout << " LIGHTS";
		Sleep(1000);

		changeColour(WHITE);
	}

	void ConsoleAnimationMan::updateScreen(Scene& pNextScene, int playerScore)
	{
		ConsoleAnimationMan* pCAM = ConsoleAnimationMan::privGetInstance();
		assert(pCAM);

		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		pCAM->clearScreen();
		COORD tempCursorStart;
		uint8_t numOfRows = pNextScene.GetNumOfRows();
		int rowNum;

		//  Print the score
		tempCursorStart = { pCAM->TOPLEFT_CURS_LOC.X, short(pCAM->TOPLEFT_CURS_LOC.Y -2) };
		SetConsoleCursorPosition(console, tempCursorStart);
		std::cout << std::setfill('0') << std::setw(6) << playerScore << '\n';

		// print the Scene
		for (rowNum = 0; rowNum < numOfRows; rowNum++)
		{
			tempCursorStart = { pCAM->TOPLEFT_CURS_LOC.X, short(pCAM->TOPLEFT_CURS_LOC.Y + rowNum) };
			SetConsoleCursorPosition(console, tempCursorStart);

			std::cout << pNextScene.GetSceneRow_string(rowNum) << '\n';
		}
	}

	void ConsoleAnimationMan::SetCycleTime(uint32_t newCycleTime)
	{
		ConsoleAnimationMan* pCAM = ConsoleAnimationMan::privGetInstance();

		pCAM->cycleTime = newCycleTime;
	}

	uint32_t ConsoleAnimationMan::GetCycleTime()
	{
		ConsoleAnimationMan* pCAM = ConsoleAnimationMan::privGetInstance();

		return pCAM->cycleTime;
	}
}
