#pragma once
#include <cstdint>

namespace AI_Game_Agent
{
	class Util
	{
	public:
		static const uint8_t LevelSeed[250][2];
		static const int Penalty_HitObsticle;
		static const int Reward_ProgressedOneCol;
		static const int Reward_CollectedCoin;
	};
}