#pragma once


namespace AI_Game_Agent
{
	class GameEngine
	{

	public:
		static void Create();
		//static void Destroy();

		// Default constructor
		GameEngine(const GameEngine&) = delete;
		GameEngine& operator = (const GameEngine&) = delete;
		~GameEngine();

	private:

		static GameEngine* _pGe;

		// Default constructor
		GameEngine();

		static GameEngine* privGetInstance();
	};
}
