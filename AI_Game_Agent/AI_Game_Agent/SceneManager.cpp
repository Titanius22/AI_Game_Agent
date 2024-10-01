#include "SceneManager.h"
#include "ConsoleAnimationMan.h"
#include <cassert>

namespace AI_Game_Agent
{
	SceneManager* SceneManager::_pSM = nullptr;

	SceneManager::SceneManager()
	{
		poStartingScene     = nullptr;
		poBufferScene_2cols = new Scene(SceneManager::NUM_OF_ROWS, 2, Scene::SceneType::BUFFER);
		poBufferScene_3cols = new Scene(SceneManager::NUM_OF_ROWS, 3, Scene::SceneType::BUFFER);
		poBufferScene_4cols = new Scene(SceneManager::NUM_OF_ROWS, 4, Scene::SceneType::BUFFER);
	}

	SceneManager::~SceneManager()
	{
		if (poStartingScene     != nullptr) {delete poStartingScene    ;};
		if (poBufferScene_3cols != nullptr) {delete poBufferScene_3cols;};
		if (poBufferScene_4cols != nullptr) {delete poBufferScene_4cols;};
		
		SceneManager* pCAM = SceneManager::privGetInstance();
		delete pCAM;
	}

	SceneManager* SceneManager::privGetInstance(void)
	{
		assert(_pSM != nullptr);

		return _pSM;
	}

	void SceneManager::Create()
	{
		assert(_pSM == nullptr);

		_pSM = new SceneManager();
		assert(_pSM);
	}

	Scene* SceneManager::GetStartingScene()
	{
		SceneManager* pSM = SceneManager::privGetInstance();
		assert(pSM);
		assert(pSM->poStartingScene == nullptr);

		uint8_t numColsDisplayed = 4;
		pSM->poStartingScene = new Scene(SceneManager::NUM_OF_ROWS, numColsDisplayed, Scene::SceneType::ACTIVE);

		uint8_t startingTerrain[] = { 0,0,0,0,0,0,0,0,0,0,1,0 };
		uint8_t startingFloor[] = { 1,1,1,1 };
		pSM->poStartingScene->SetTerrain(numColsDisplayed, SceneManager::NUM_OF_ROWS - 1, startingTerrain);
		pSM->poStartingScene->SetFloor(startingFloor);
		return pSM->poStartingScene;
	}

	Scene* SceneManager::GetNewScene(const uint8_t const numOfCols, uint8_t seedNum)
	{
		SceneManager* pSM = SceneManager::privGetInstance();
		assert(pSM);

		if (numOfCols == 2)
		{
			pSM->poBufferScene_2cols = new(pSM->poBufferScene_2cols) Scene(SceneManager::NUM_OF_ROWS, numOfCols, Scene::SceneType::BUFFER);
			uint8_t terrain[] = { 0,0,0,0,0,0 }; // not used, here just to shut up complier
			switch (seedNum) {
				case 0:
					// do nothing, Scene already cleared
					uint8_t terrain[] = { 0,0,0,0,0,0 };
					break;
				case 1:
					uint8_t terrain[] = { 0,1,0,0,0,0 };
					break;
				case 2:
					uint8_t terrain[] = { 0,0,0,1,0,0 };
					break;
				case 3:
					uint8_t terrain[] = { 0,0,0,0,0,1 };
					break;
				case 4:
					uint8_t terrain[] = { 0,1,0,1,0,0 };
					break;
				case 5:
					uint8_t terrain[] = { 0,0,0,1,0,1 };
					break;
				case 6:
					uint8_t terrain[] = { 0,1,0,0,0,1 };
					break;
				default:
					assert(false);
					uint8_t terrain[] = { 0,0,0,0,0,0 };
			}
			pSM->poStartingScene->SetTerrain(numOfCols, SceneManager::NUM_OF_ROWS - 1, terrain);

			uint8_t floor[] = { 1,1 };
			pSM->poBufferScene_2cols->SetFloor(floor);

			return pSM->poBufferScene_2cols;
		}
		else if (numOfCols == 3)
		{
			pSM->poBufferScene_3cols = new(pSM->poBufferScene_3cols) Scene(SceneManager::NUM_OF_ROWS, numOfCols, Scene::SceneType::BUFFER);
			uint8_t terrain[] = { 0,0,0,0,0,0,0,0,0 }; // not used, here just to shut up complier
			
			switch (seedNum) {
				case 0:
					// do nothing, Scene already cleared
					uint8_t terrain[] = { 0,0,0,0,0,0,0,0,0 };
					break;
				case 1:
					uint8_t terrain[] = { 0,0,0,0,0,1,0,1,0 };
					break;
				case 2:
					uint8_t terrain[] = { 0,1,0,0,0,1,0,0,0 };
					break;
				case 3:
					uint8_t terrain[] = { 0,0,1,0,1,0,0,0,0 };
					break;
				case 4:
					uint8_t terrain[] = { 0,0,0,0,1,0,0,0,1 };
					break;
				case 5:
					uint8_t terrain[] = { 0,1,0,0,0,0,0,0,1 };
					break;
				case 6:
					uint8_t terrain[] = { 0,0,1,0,0,0,0,1,0 };
					break;
				default:
					assert(false);
					uint8_t terrain[] = { 0,0,0,0,0,0,0,0,0 };
			}
			pSM->poBufferScene_3cols->SetTerrain(numOfCols, SceneManager::NUM_OF_ROWS - 1, terrain);

			uint8_t floor[] = { 1,1,1 };
			pSM->poBufferScene_3cols->SetFloor(floor);

			return pSM->poBufferScene_3cols;
		}
		else
		{
			assert(false);
		}
	}
}
