#include "Scene.h"
#include <cassert>

namespace AI_Game_Agent
{
	Scene::Scene(uint8_t argNumOfRows, uint8_t argNumOfCols):
		_numOfRows(argNumOfRows), _numOfCols(argNumOfCols)
	{
		_sceneData = new char[argNumOfRows * argNumOfCols];
		_sceneData_Player = PlayerPos::undecided;

		ClearScene();
	}

	Scene::~Scene()
	{
		delete _sceneData;
	}

	void Scene::SetPlayer(PlayerPos playerPos)
	{
		_sceneData_Player = playerPos;
		
		// clear row 0
		//_sceneData[0][0] = converterPlayer[0];
		//_sceneData[1][0] = converterPlayer[0];
		//_sceneData[2][0] = converterPlayer[0];

		switch (playerPos) {
			case PlayerPos::NORMAL:
				assert(_sceneData[(0*_numOfCols) + 0] == ' ');
				_sceneData[(0*_numOfCols) + 0] = converterPlayer[1];
				
				assert(_sceneData[(1*_numOfCols) + 0] == ' ');
				_sceneData[(1*_numOfCols) + 0] = converterPlayer[1];
				
				assert(_sceneData[(2 * _numOfCols) + 0] == ' ');
				_sceneData[(2 * _numOfCols) + 0] = converterPlayer[1];
				break;

			case PlayerPos::JUMP:
				assert(_sceneData[(0 * _numOfCols) + 0] == ' ');
				_sceneData[(0 * _numOfCols) + 0] = converterPlayer[2];
				break;

			case PlayerPos::DIVE:
				assert(_sceneData[(1 * _numOfCols) + 0] == ' ');
				_sceneData[(1 * _numOfCols) + 0] = converterPlayer[2];
				break;

			case PlayerPos::DUCK:
				assert(_sceneData[(2 * _numOfCols) + 0] == ' ');
				_sceneData[(2 * _numOfCols) + 0] = converterPlayer[2];
				break;

			default:
				assert(false);
		}
	}

	void Scene::SetFloor(uint8_t data[])
	{
		//assert(sizeof(data) / sizeof(data[0]) == _numOfCols);

		for (int i=0; i< _numOfCols; i++)
		{
			assert(data[i] < (sizeof(converterFloor) / sizeof(converterFloor[0])));
			_sceneData[(_numOfCols*(_numOfRows - 1)) + i] = converterFloor[data[i]];
		}
	}

	void Scene::SetFloor(uint8_t col, uint8_t data)
	{
		assert(col < _numOfCols);

		assert(data < (sizeof(converterFloor) / sizeof(converterFloor[0])));
		_sceneData[(_numOfCols * (_numOfRows - 1)) + col] = converterFloor[data];
	}

	void Scene::SetTerrain(uint8_t numCol, uint8_t numRow, uint8_t data[])
	{
		assert(numCol == _numOfCols);
		assert(numRow == (_numOfRows - 1)); // -1 to prevent this from modifing the Floor

		// can't check this because its a pointer
		//assert(sizeof(data) / sizeof(data[0]) == (_numOfCols * (_numOfRows - 1))); // -1 to prevent this from modifing the Floor

		for (int j = 0; j < (_numOfRows - 1); j++) // -1 to prevent this from modifing the Floor	
		{
			for (int i = 0; i < _numOfCols; i++)
			{
				assert(data[(j*_numOfCols) + i] < (sizeof(converterTerrain) / sizeof(converterTerrain[0])));
				_sceneData[(_numOfCols * j) + i] = converterTerrain[data[(j * _numOfCols) + i]];
			}
		}
	}
	
	void Scene::SetTerrainCol(uint8_t col, uint8_t data[])
	{
		assert(col < _numOfCols); 

		//assert(sizeof(data) / sizeof(data[0]) == (_numOfRows-1)); // -1 to prevent this from modifing the Floor

		for (int i = 0; i < (_numOfRows-1); i++) // -1 to prevent this from modifing the Floor
		{
			assert(data[i] < (sizeof(converterTerrain) / sizeof(converterTerrain[0])));
			_sceneData[(_numOfCols * i) + col] = converterTerrain[data[i]];
		}
	}
	
	void Scene::SetTerrainRow(uint8_t row, uint8_t data[])
	{
		assert(row < (_numOfRows-1)); // -1 to prevent this from modifing the Floor

		//assert(sizeof(data) / sizeof(data[0]) == _numOfCols);

		for (int i = 0; i < _numOfCols; i++)
		{
			assert(data[i] < (sizeof(converterTerrain) / sizeof(converterTerrain[0])));
			_sceneData[(_numOfCols * row) + i] = converterTerrain[data[i]];
		}
	}

	std::string Scene::GetSceneRow_string(uint8_t rowNum) const
	{
		assert(rowNum < _numOfRows);
		//assert((sizeof(charArray) / sizeof(charArray[0])) == _numOfCols); // can't have this check because its a pointer

		std::string rtnVal(_numOfRows, ' ');
		uint8_t buffVal;

		for (int i = 0; i < _numOfCols; i++)
		{
			buffVal = _sceneData[(_numOfCols * rowNum) + i];
			
			if (rowNum >= 0 && rowNum < (_numOfRows - 1))
			{
				// terrain
				assert(buffVal < ((sizeof(converterTerrain)) / (sizeof(converterTerrain[0]))));
				rtnVal[i] = converterTerrain[buffVal];
			}
			else if (rowNum == (_numOfRows-1))
			{
				// floor
				assert(buffVal < ((sizeof(converterFloor)) / (sizeof(converterFloor[0]))));
				rtnVal[i] = converterFloor[buffVal];
			}
			else
			{
				assert(false);
			}
		}

		return rtnVal;
	}

	void Scene::GetSceneRow(uint8_t rowNum, uint8_t* rtnVal) const
	{
		assert(rowNum < _numOfRows);

		for (int i = 0; i < _numOfCols; i++)
		{
			rtnVal[i] = _sceneData[(_numOfCols * rowNum) + i];
		}
	}

	std::string Scene::GetSceneColumn_string(uint8_t colNum) const
	{
		// includes floor
		
		assert(colNum < _numOfCols);
		//assert((sizeof(charArray) / sizeof(charArray[0])) == _numOfCols); // can't have this check because its a pointer

		std::string rtnVal(_numOfCols, ' ');
		uint8_t buffVal;

		for (int rowNum = 0; rowNum < _numOfRows; rowNum++)
		{
			buffVal = _sceneData[(_numOfCols * rowNum) + colNum];
			
			rtnVal[rowNum] = _sceneData[(_numOfCols * rowNum) + colNum];

			if (rowNum >= 0 && rowNum < (_numOfRows - 1))
			{
				// terrain
				assert(buffVal < ((sizeof(converterTerrain)) / (sizeof(converterTerrain[0]))));
				rtnVal[rowNum] = converterTerrain[buffVal];
			}
			else if (rowNum == (_numOfRows - 1))
			{
				// floor
				assert(buffVal < ((sizeof(converterFloor)) / (sizeof(converterFloor[0]))));
				rtnVal[rowNum] = converterFloor[buffVal];
			}
			else
			{
				assert(false);
			}
		}

		return rtnVal;
	}

	void Scene::GetSceneColumn(uint8_t colNum, uint8_t* rtnVal) const
	{
		// includes floor

		assert(colNum < _numOfCols);

		for (int i = 0; i < _numOfRows; i++)
		{
			rtnVal[i] = _sceneData[(_numOfCols * i) + colNum];
		}
	}

	void Scene::ClearScene()
	{
		for (int i = 0; i < _numOfCols; i++)
		{
			for (int j = 0; j < _numOfRows; j++)
			{
				_sceneData[(_numOfCols * j) + i] = ' ';
			}
		}
	}

	void Scene::ProgressScene()
	{
		// Shift columns to the left
		for (int j = 0; j < _numOfRows; j++)
		{
			for (int i = 0; i < (_numOfCols-1); i++)
			{
				_sceneData[(_numOfCols * j) + i] = _sceneData[(_numOfCols * j) + (i+1)];
			}
		}

		// reset the last col
		for (int k = 0; k < (_numOfRows - 1); k++)
		{
			_sceneData[(_numOfCols * k) + (_numOfCols - 1)] = converterTerrain[0];
		}
		_sceneData[(_numOfCols * (_numOfRows - 1)) + (_numOfCols - 1)] = converterFloor[0];
	}

	uint8_t Scene::GetNumOfCol() const
	{
		return _numOfCols;
	}

	uint8_t Scene::GetNumOfRow() const
	{
		return _numOfRows;
	}
}
