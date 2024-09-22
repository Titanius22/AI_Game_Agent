#pragma once
#include <iostream>

namespace AI_Game_Agent
{
	class Scene
	{
	public:

		enum PlayerPos
		{
			NORMAL,
			JUMP,
			DIVE,
			DUCK
		};

		enum TerrainEnum
		{
			EMPTY = 0,
			OBSTICLE = 1,
			REWARD = 2
		};

		enum FloorEnum
		{
			HOLE = 0,
			SOLID = 1
		};

		// Default constructor
		Scene();
		Scene(const Scene&) = default;
		Scene& operator = (const Scene&) = default;
		~Scene() = default;

		void SetPlayer(PlayerPos playerPos);
		void SetFloor(uint8_t data[]);
		void SetFloor(uint8_t col, uint8_t data);
		void SetTerrain(uint8_t numCol, uint8_t numRow, uint8_t data[]);
		void SetTerrainCol(uint8_t col, uint8_t data[]);
		void SetTerrainRow(uint8_t row, uint8_t data[]);

		std::string GetSceneRow(uint8_t rowNum);

		void ClearScene();
		void ProgressScene();

		uint8_t GetNumOfCol();
		uint8_t GetNumOfRow();

	private:
		const char converterTerrain[3] = {' ', 'x', 'o'};
		const char converterFloor[2]   = {' ', '-'     };
		const char converterPlayer[3]  = {' ', '#', '='};

		static const uint8_t NUM_O_COL = 4;
		static const uint8_t NUM_O_ROW = 4; // includes floor

		char sceneData[NUM_O_ROW][NUM_O_COL]; //row, col
	};
}