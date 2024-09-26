#pragma once

#include "Scene.h"

namespace AI_Game_Agent
{
	class IPlayer
	{
	public:
		virtual Scene::PlayerPos MakeDecision_GetNextPlayerPos() const = 0 ;
		virtual void CollectData_ReceiveScore(int score) = 0;
		virtual void CollectData_IngestScene(const Scene& rScene) = 0;

	};
}

