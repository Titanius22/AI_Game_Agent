#include "Scene.h"
#include <cassert>

namespace AI_Game_Agent
{
	Scene::Scene()
	{
		ClearScene();
	}

	void Scene::SetPlayer(PlayerPos playerPos)
	{
		// clear row 0
		//sceneData[0][0] = converterPlayer[0];
		//sceneData[1][0] = converterPlayer[0];
		//sceneData[2][0] = converterPlayer[0];

		switch (playerPos) {
			case PlayerPos::NORMAL:
				assert(sceneData[0][0] == ' ');
				sceneData[0][0] = converterPlayer[1];
				
				assert(sceneData[1][0] == ' ');
				sceneData[1][0] = converterPlayer[1];
				
				assert(sceneData[2][0] == ' ');
				sceneData[2][0] = converterPlayer[1];
				break;

			case PlayerPos::JUMP:
				assert(sceneData[0][0] == ' ');
				sceneData[0][0] = converterPlayer[2];
				break;

			case PlayerPos::DIVE:
				assert(sceneData[1][0] == ' ');
				sceneData[1][0] = converterPlayer[2];
				break;

			case PlayerPos::DUCK:
				assert(sceneData[2][0] == ' ');
				sceneData[2][0] = converterPlayer[2];
				break;

			default:
				assert(false);
		}
	}

	void Scene::SetFloor(uint8_t data[])
	{
		//assert(sizeof(data) / sizeof(data[0]) == NUM_O_COL);

		for (int i=0; i< NUM_O_COL; i++)
		{
			assert(data[i] < (sizeof(converterFloor) / sizeof(converterFloor[0])));
			sceneData[NUM_O_ROW - 1][i] = converterFloor[data[i]];
		}
	}

	void Scene::SetFloor(uint8_t col, uint8_t data)
	{
		assert(col < NUM_O_COL);

		assert(data < (sizeof(converterFloor) / sizeof(converterFloor[0])));
		sceneData[NUM_O_ROW - 1][col] = converterFloor[data];
	}

	void Scene::SetTerrain(uint8_t numCol, uint8_t numRow, uint8_t data[])
	{
		assert(numCol == NUM_O_COL);
		assert(numRow == (NUM_O_ROW - 1)); // -1 to prevent this from modifing the Floor

		// can't check this because its a pointer
		//assert(sizeof(data) / sizeof(data[0]) == (NUM_O_COL * (NUM_O_ROW - 1))); // -1 to prevent this from modifing the Floor

		for (int j = 0; j < (NUM_O_ROW - 1); j++) // -1 to prevent this from modifing the Floor	
		{
			for (int i = 0; i < NUM_O_COL; i++)
			{
				assert(data[(j*NUM_O_COL) + i] < (sizeof(converterTerrain) / sizeof(converterTerrain[0])));
				sceneData[j][i] = converterTerrain[data[(j * NUM_O_COL) + i]];
			}
		}
	}
	
	void Scene::SetTerrainCol(uint8_t col, uint8_t data[])
	{
		assert(col < NUM_O_COL); 

		//assert(sizeof(data) / sizeof(data[0]) == (NUM_O_ROW-1)); // -1 to prevent this from modifing the Floor

		for (int i = 0; i < (NUM_O_ROW-1); i++) // -1 to prevent this from modifing the Floor
		{
			assert(data[i] < (sizeof(converterTerrain) / sizeof(converterTerrain[0])));
			sceneData[i][col] = converterTerrain[data[i]];
		}
	}
	
	void Scene::SetTerrainRow(uint8_t row, uint8_t data[])
	{
		assert(row < (NUM_O_ROW-1)); // -1 to prevent this from modifing the Floor

		//assert(sizeof(data) / sizeof(data[0]) == NUM_O_COL);

		for (int i = 0; i < NUM_O_COL; i++)
		{
			assert(data[i] < (sizeof(converterTerrain) / sizeof(converterTerrain[0])));
			sceneData[row][i] = converterTerrain[data[i]];
		}
	}

	std::string Scene::GetSceneRow(uint8_t rowNum)
	{
		assert(rowNum < NUM_O_ROW);
		//assert((sizeof(charArray) / sizeof(charArray[0])) == NUM_O_COL); // can't have this check because its a pointer

		std::string rtnVal(NUM_O_ROW, ' ');

		for (int i = 0; i < NUM_O_COL; i++)
		{
			rtnVal[i] = sceneData[rowNum][i];
		}

		return rtnVal;
	}

	void Scene::ClearScene()
	{
		for (int i = 0; i < NUM_O_COL; i++)
		{
			for (int j = 0; j < NUM_O_ROW; j++)
			{
				sceneData[j][i] = ' ';
			}
		}
	}

	void Scene::ProgressScene()
	{
		// Shift columns to the left
		for (int j = 0; j < NUM_O_ROW; j++)
		{
			for (int i = 0; i < (NUM_O_COL-1); i++)
			{
				sceneData[j][i] = sceneData[j][i+1];
			}
		}

		// reset the last col
		for (int k = 0; k < (NUM_O_ROW - 1); k++)
		{
			sceneData[k][NUM_O_COL-1] = converterTerrain[0];
		}
		sceneData[NUM_O_ROW-1][NUM_O_COL - 1] = converterFloor[0];
	}

	uint8_t Scene::GetNumOfCol()
	{
		return NUM_O_COL;
	}

	uint8_t Scene::GetNumOfRow()
	{
		return NUM_O_ROW;
	}
}
