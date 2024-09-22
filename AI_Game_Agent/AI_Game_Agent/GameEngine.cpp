#include "GameEngine.h"
#include <cassert>

namespace AI_Game_Agent
{
	GameEngine* GameEngine::_pGe = nullptr;

	void GameEngine::Create()
	{
		assert(_pGe == nullptr);

		_pGe = new GameEngine();
		assert(_pGe);
	}
	//void Destroy();

	GameEngine::~GameEngine()
	{
		GameEngine* pGE = GameEngine::privGetInstance();
		delete pGE;
	}

	GameEngine::GameEngine()
	{
		// do nothing
	}

	GameEngine* GameEngine::privGetInstance()
	{
		assert(_pGe != nullptr);

		return _pGe;
	}
}