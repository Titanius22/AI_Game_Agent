#pragma once

#include "IPlayer.h"


namespace AI_Game_Agent
{
	class GameEngine
	{

	public:
		enum class PlayerType
		{
			HUMAN,
			AI_RANDOM,
			AI
		};		
		
		static void Create(PlayerType inputPlayerType);
		//static void Destroy();

		// Default constructor
		GameEngine(const GameEngine&) = delete;
		GameEngine& operator = (const GameEngine&) = delete;
		GameEngine() = delete;
		~GameEngine();

		static void Run();

	private:

		static GameEngine* _pGe;
		IPlayer* _pPlayer;
		Scene* pActiveScene;
		Scene* pBufferScene;
		uint32_t rowCounter; // number of rows generated and displayed on screen

		uint8_t numRowsDisplayed;
		uint8_t numColsDisplayed;

		// special constructor
		GameEngine(PlayerType inputPlayerType);

		static GameEngine* privGetInstance();
		void GenerateStartingScene_noPlayer();
		void GenerateBufferScene(Scene& scene);
	};
}
