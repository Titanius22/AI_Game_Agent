#pragma once

#include "IPlayer.h"

namespace AI_Game_Agent
{
	class Player_Human : public IPlayer
	{
	public:
		// Default constructor
		Player_Human();
		Player_Human(const Player_Human&) = delete;
		Player_Human& operator = (const Player_Human&) = delete;
		~Player_Human();

		Scene::PlayerPos MakeDecision_GetNextPlayerPos() const override;
		void CollectData_ReceiveScore(int score) override;
		void CollectData_IngestScene(const Scene& rScene) override;
	};
}