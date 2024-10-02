#include "GameEngine.h"
#include <cassert>
#include "Player_Human.h"
#include "ConsoleAnimationMan.h"
#include "SceneManager.h"
#include "Util.h"

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

		this->pActiveScene = nullptr;
		this->pBufferScene = nullptr;
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
		
		// set up Ative Scene
		pGE->pActiveScene = SceneManager::GetStartingScene();
		pGE->pActiveScene->SetPlayer(Scene::PlayerPos::NORMAL); //doesn't matter, just need something to start things out

		// dispaly screen
		ConsoleAnimationMan::updateScreen(*(pGE->pActiveScene));

		// Create buffer Scene
		pGE->pBufferScene = SceneManager::GetNewScene();
		uint8_t buffNumOfCols = pGE->pBufferScene->GetNumOfCols();
		uint8_t buffColIdx = 0;
		
		while(true)
		{
			// give scene to Player
			pGE->_pPlayer->CollectData_IngestScene(*(pGE->pActiveScene));

			// Ask player for Decision
			Scene::PlayerPos playerMove = pGE->_pPlayer->MakeDecision_GetNextPlayerPos();
			
			// Advance Scene
			pGE->pActiveScene->ProgressScene();

			// generate new last column of scene
			pGE->pActiveScene->SetTerrainCol(pGE->pActiveScene->GetNumOfCols()-1, pGE->pBufferScene, buffColIdx);
			pGE->pActiveScene->SetSceneWithoutPlayerUpdateCompleted();
			buffColIdx++;

			// Generate new buffer Scene if existing ran out of new data
			if (buffColIdx == buffNumOfCols)
			{
				pGE->pBufferScene = SceneManager::GetNewScene();
				buffNumOfCols = pGE->pBufferScene->GetNumOfCols();
				buffColIdx = 0;
			}

			// mode player
			pGE->pActiveScene->SetPlayer(playerMove);
			
			// and give player score

			// Display to screen
			ConsoleAnimationMan::updateScreen(*(pGE->pActiveScene));
		}
	}

	//void GameEngine::GenerateStartingScene_noPlayer()
	//{
	//	this->pActiveScene = new Scene(numRowsDisplayed, numColsDisplayed);
	//	
	//	uint8_t startingTerrain[] = { 0,0,0,0,0,0,0,0,0,0,1,0 };
	//	uint8_t startingFloor[] = { 1,1,1,1 };
	//	this->pActiveScene->SetTerrain(numColsDisplayed, numRowsDisplayed-1, startingTerrain);
	//	this->pActiveScene->SetFloor(startingFloor);
	//	ConsoleAnimationMan::updateScreen(*this->pActiveScene);
	//}

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