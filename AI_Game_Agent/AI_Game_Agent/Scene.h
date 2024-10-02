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

		enum class SceneType
		{
			ACTIVE,    // actively updated, progressed, player set, repeat
			BUFFER     // just a holder of scene data
		};

		// Default constructor
		Scene() = delete;
		Scene(const Scene&) = delete;
		Scene& operator = (const Scene&) = delete;
		~Scene();

		// Special contructor
		Scene(uint8_t numOfRows, uint8_t numOfCols, SceneType sceneType);

		void SetPlayer(PlayerPos playerPos);
		void SetFloor(uint8_t data[]);
		void SetFloor(uint8_t colNum, FloorEnum data);
		void SetTerrain(uint8_t numCol, uint8_t numRow, uint8_t data[]);
		void SetTerrainCol(uint8_t colNum, uint8_t data[]);
		void SetTerrainCol(uint8_t colToOverwrite, const Scene* scene, uint8_t colToCopy);
		void SetTerrainRow(uint8_t rowNum, uint8_t data[]);
		void SetSceneWithoutPlayerUpdateCompleted();

		void GetSceneRow(uint8_t rowNum, uint8_t* rtnVal) const;
		std::string GetSceneRow_string(uint8_t rowNum) const;
		void GetSceneColumn(uint8_t colNum, uint8_t* rtnVal) const;
		std::string GetSceneColumn_string(uint8_t colNum) const;

		void ClearScene();
		void ProgressScene();

		uint8_t GetNumOfCols() const;
		uint8_t GetNumOfRows() const;

	private:
		enum class SceneMode
		{
			SCENE_NEW,               // newly created, should only enter this mode once
			SCENE_PROGRESSED,        // Scene progressed from last frame
			SCENE_UPDATED__LAST_ROW, // after scene progressed, last column was populated
			PLAYER_UPDATED,          // Player position updated, new mode is SCENE_PROGRESSED

			NA__BUFFER_SCENE         // not part of sequence, used if its a buffer scene
			                         // meaning it just stores data.
		};
		
		const char converterTerrain[3] = {' ', 'x', 'o'};
		const char converterFloor[2]   = {' ', '-'     };
		const char converterPlayer[3]  = {' ', '#', '='};

		uint8_t _numOfRows; // includes floor
		uint8_t _numOfCols;

		uint8_t* _sceneData; //row, col
		char* _sceneData_char; //row, col
		PlayerPos _sceneData_Player;
		SceneType _sceneType;
		SceneMode _currSceneMode;
		
		void ClearTerrain();
		void ClearFloor();
		void WriteToChar();
	};
}