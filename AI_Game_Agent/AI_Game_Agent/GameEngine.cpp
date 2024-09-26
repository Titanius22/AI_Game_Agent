#include "GameEngine.h"
#include <cassert>
#include "Player_Human.h"
#include "ConsoleAnimationMan.h"

namespace AI_Game_Agent
{
	GameEngine* GameEngine::_pGe = nullptr;

	void GameEngine::Create(PlayerType inputPlayerType)
	{
		assert(_pGe == nullptr);

		_pGe = new GameEngine(inputPlayerType);
		assert(_pGe);
	}
	//void Destroy();

	GameEngine::~GameEngine()
	{
		delete _pPlayer;
		
		GameEngine* pGE = GameEngine::privGetInstance();
		delete pGE;
	}

	GameEngine::GameEngine(PlayerType inputPlayerType)
	{
		this->_pPlayer = nullptr;
		
		switch (inputPlayerType)
		{
		case PlayerType::HUMAN:
			this->_pPlayer = new Player_Human();
			break;
		default:
			assert(false);
			break;
		}

		this->numRowsDisplayed = 4;
		this->numColsDisplayed = 4;
	}

	GameEngine* GameEngine::privGetInstance()
	{
		assert(_pGe != nullptr);

		return _pGe;
	}

	void GameEngine::Run()
	{
		GameEngine* pGE = GameEngine::privGetInstance();
		assert(pGE);
		
		pGE->GenerateStartingScene_noPlayer();
		
		while(true)
		{
			// give scene to Player
			pGE->_pPlayer->CollectData_IngestScene(*(pGE->pActiveScene));

			// Ask player for Decision
			Scene::PlayerPos playerMove = pGE->_pPlayer->MakeDecision_GetNextPlayerPos();
			
			// Advance Scene
			pGE->pActiveScene->ProgressScene();

			// mode player and give player score
			pGE->pActiveScene->SetPlayer(playerMove);
			
			// // generate scene

			// Display to screen
			ConsoleAnimationMan::updateScreen(*(pGE->pActiveScene));
		}
	}

	void GameEngine::GenerateStartingScene_noPlayer()
	{
		this->pActiveScene = new Scene(numRowsDisplayed, numColsDisplayed);
		
		uint8_t startingTerrain[] = { 0,0,0,0,0,0,0,0,0,0,1,0 };
		uint8_t startingFloor[] = { 1,1,1,1 };
		this->pActiveScene->SetTerrain(numColsDisplayed, numRowsDisplayed-1, startingTerrain);
		this->pActiveScene->SetFloor(startingFloor);
		ConsoleAnimationMan::updateScreen(*this->pActiveScene);
	}

	void GenerateBufferScene(Scene& scene)
	{
		/*uint8_t startingTerrain[] = { 0,0,0,0,0,0,0,0,0,0,1,0 };
		uint8_t startingFloor[] = { 1,1,1,1 };
		Scene scene(4, 4);
		scene.SetTerrain(4, 3, startingTerrain);
		scene.SetFloor(startingFloor);
		ConsoleAnimationMan::updateScreen(scene);

		scene.ProgressScene();
		uint8_t lastColTerrain[] = { 0, 0, 0 };
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, 1);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 1;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, 1);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, 1);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, 1);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 1;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 1;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, 1);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, 1);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, 1);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, 1);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		scene.ProgressScene();
		lastColTerrain[0] = 0;
		lastColTerrain[1] = 0;
		lastColTerrain[2] = 0;
		scene.SetTerrainCol(3, lastColTerrain);
		scene.SetFloor(3, 1);
		pCAM->updateScreen(scene);
		Sleep(pCAM->cycleTime);

		pCAM->clearScreen();
		std::cout << "\n\n\n";*/
	}

}