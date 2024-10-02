#pragma once
#include "Scene.h"

namespace AI_Game_Agent
{
	class SceneManager
	{
	public:
		static void Create();
		//static void Destroy();

		static Scene* GetStartingScene();
		static Scene* GetNewScene();
		static Scene* GetNewScene(const uint8_t numOfCols, uint8_t seedNum);

		// Default constructor
		SceneManager(const SceneManager&) = delete;
		SceneManager& operator = (const SceneManager&) = delete;
		~SceneManager();

		const static uint8_t NUM_OF_ROWS = 4;

	private:
		
		static SceneManager* _pSM;

		Scene* poStartingScene;
		Scene* poBufferScene_2cols;
		Scene* poBufferScene_3cols;
		Scene* poBufferScene_4cols;
		uint32_t bufferSceneCounter; // number of buffer Scenes generated and displayed on screen


		// Default constructor
		SceneManager();

		static SceneManager* privGetInstance();
	};
}

