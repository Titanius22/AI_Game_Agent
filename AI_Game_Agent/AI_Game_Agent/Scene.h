#pragma once
#include <iostream>

namespace AI_Game_Agent
{
	class Scene
	{
	public:

		enum class PlayerPos
		{
			undecided,
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
		Scene() = delete;
		Scene(const Scene&) = delete;
		Scene& operator = (const Scene&) = delete;
		~Scene();

		// Special contructor
		Scene(uint8_t numOfRows, uint8_t numOfCols);

		void SetPlayer(PlayerPos playerPos);
		void SetFloor(uint8_t data[]);
		void SetFloor(uint8_t col, uint8_t data);
		void SetTerrain(uint8_t numCol, uint8_t numRow, uint8_t data[]);
		void SetTerrainCol(uint8_t col, uint8_t data[]);
		void SetTerrainRow(uint8_t row, uint8_t data[]);

		std::string GetSceneRow(uint8_t rowNum) const;
		std::string GetSceneColumn(uint8_t colNum) const;

		void ClearScene();
		void ProgressScene();

		uint8_t GetNumOfCol() const;
		uint8_t GetNumOfRow() const;

	private:
		const char converterTerrain[3] = {' ', 'x', 'o'};
		const char converterFloor[2]   = {' ', '-'     };
		const char converterPlayer[3]  = {' ', '#', '='};

		uint8_t _numOfRows; // includes floor
		uint8_t _numOfCols;

		char* sceneData; //row, col
	};
}