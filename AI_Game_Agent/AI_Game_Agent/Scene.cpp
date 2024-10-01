#include "Scene.h"
#include <cassert>

namespace AI_Game_Agent
{
	Scene::Scene(uint8_t argNumOfRows, uint8_t argNumOfCols, SceneType sceneType):
		_numOfRows(argNumOfRows), _numOfCols(argNumOfCols)
	{
		_sceneData = new uint8_t[argNumOfRows * argNumOfCols];
		_sceneData_char = new char[argNumOfRows * argNumOfCols];
		_sceneData_Player = PlayerPos::undecided;
		_sceneType = sceneType;

		if (_sceneType == SceneType::ACTIVE) {
			_currSceneMode = SceneMode::SCENE_NEW;
		}
		else if (_sceneType == SceneType::BUFFER) {
			_currSceneMode = SceneMode::NA__BUFFER_SCENE;
		}
		else
		{
			assert(false);
		}

		ClearScene();
	}

	Scene::~Scene()
	{
		delete _sceneData;
		delete _sceneData_char;
	}

	void Scene::SetPlayer(PlayerPos playerPos)
	{
		assert(_sceneType == SceneType::ACTIVE);
		assert(_currSceneMode == SceneMode::SCENE_UPDATED__LAST_ROW);

		_sceneData_Player = playerPos;

		_currSceneMode == SceneMode::PLAYER_UPDATED;

		WriteToChar();
	}

	void Scene::SetFloor(uint8_t data[])
	{
		for (int colNum =0; colNum < _numOfCols; colNum++)
		{
			_sceneData[(_numOfCols*(_numOfRows - 1)) + colNum] = data[colNum];
		}
	}

	void Scene::SetFloor(uint8_t colNum, FloorEnum data)
	{
		assert(colNum < _numOfCols);

		_sceneData[(_numOfCols * (_numOfRows - 1)) + colNum] = data;
	}

	void Scene::SetTerrain(uint8_t numOfCols, uint8_t numOfRows, uint8_t data[])
	{
		assert(numOfCols == _numOfCols);
		assert(numOfRows == (_numOfRows - 1)); // -1 to prevent this from modifing the Floor

		for (int rowNum = 0; rowNum < (_numOfRows - 1); rowNum++) // -1 to prevent this from modifing the Floor	
		{
			for (int colNum = 0; colNum < _numOfCols; colNum++)
			{
				_sceneData[(_numOfCols * rowNum) + colNum] = data[(rowNum * _numOfCols) + colNum];
			}
		}
	}
	
	void Scene::SetTerrainCol(uint8_t colNum, uint8_t data[])
	{
		assert(colNum < _numOfCols);

		for (int rowNum = 0; rowNum < (_numOfRows-1); rowNum++) // -1 to prevent this from modifing the Floor
		{
			_sceneData[(_numOfCols * rowNum) + colNum] = data[rowNum];
		}
	}
	
	void Scene::SetTerrainRow(uint8_t rowNum, uint8_t data[])
	{
		assert(rowNum < (_numOfRows-1)); // -1 to prevent this from modifing the Floor

		//assert(sizeof(data) / sizeof(data[0]) == _numOfCols);

		for (int colNum = 0; colNum < _numOfCols; colNum++)
		{
			_sceneData[(_numOfCols * rowNum) + colNum] = data[colNum];
		}
	}

	std::string Scene::GetSceneRow_string(uint8_t rowNum) const
	{
		assert(_currSceneMode == SceneMode::PLAYER_UPDATED);
		
		assert(rowNum < _numOfRows);
		//assert((sizeof(charArray) / sizeof(charArray[0])) == _numOfCols); // can't have this check because its a pointer

		std::string rtnVal(_numOfRows, ' ');
		uint8_t buffVal;

		for (int colNum = 0; colNum < _numOfCols; colNum++)
		{
			rtnVal[rowNum] = _sceneData_char[(_numOfCols * rowNum) + colNum];
		}

		return rtnVal;
	}

	void Scene::GetSceneRow(uint8_t rowNum, uint8_t* rtnVal) const
	{
		assert(rowNum < _numOfRows);

		for (int colNum = 0; colNum < _numOfCols; colNum++)
		{
			rtnVal[colNum] = _sceneData[(_numOfCols * rowNum) + colNum];
		}
	}

	std::string Scene::GetSceneColumn_string(uint8_t colNum) const
	{
		// includes floor

		assert(_currSceneMode == SceneMode::PLAYER_UPDATED);
		
		assert(colNum < _numOfCols);
		//assert((sizeof(charArray) / sizeof(charArray[0])) == _numOfCols); // can't have this check because its a pointer

		std::string rtnVal(_numOfCols, ' ');

		for (int rowNum = 0; rowNum < _numOfRows; rowNum++)
		{		
			rtnVal[rowNum] = _sceneData_char[(_numOfCols * rowNum) + colNum];
		}

		return rtnVal;
	}

	void Scene::GetSceneColumn(uint8_t colNum, uint8_t* rtnVal) const
	{
		// includes floor

		assert(colNum < _numOfCols);

		for (int rowNum = 0; rowNum < _numOfRows; rowNum++)
		{
			rtnVal[rowNum] = _sceneData[(_numOfCols * rowNum) + colNum];
		}
	}

	void Scene::ClearScene()
	{
		ClearTerrain();
		ClearFloor();
	}

	void Scene::ClearTerrain()
	{
		for (int colNum = 0; colNum < _numOfCols; colNum++)
		{
			for (int rowNum = 0; rowNum < (_numOfRows-1); rowNum++)
			{
				_sceneData[(_numOfCols * rowNum) + colNum] = TerrainEnum::EMPTY;
			}
		}
	}

	void Scene::ClearFloor()
	{
		for (int colNum = 0; colNum < _numOfCols; colNum++)
		{
			_sceneData[(_numOfCols * (_numOfRows - 1)) + colNum] = FloorEnum::SOLID;
		}
	}

	void Scene::ProgressScene()
	{
		assert(_sceneType == SceneType::ACTIVE);
		assert(_currSceneMode == SceneMode::PLAYER_UPDATED);
		
		// Shift columns to the left
		for (int rowNum = 0; rowNum < _numOfRows; rowNum++)
		{
			for (int colNum = 0; colNum < (_numOfCols-1); colNum++)
			{
				_sceneData[(_numOfCols * rowNum) + colNum] = _sceneData[(_numOfCols * rowNum) + (colNum +1)];
			}
		}

		// reset the last col
		for (int rowNum = 0; rowNum < (_numOfRows - 1); rowNum++)
		{
			_sceneData[(_numOfCols * rowNum) + (_numOfCols - 1)] = TerrainEnum::EMPTY;
		}
		_sceneData[(_numOfCols * (_numOfRows - 1)) + (_numOfCols - 1)] = FloorEnum::SOLID;
	
		_currSceneMode == SceneMode::SCENE_PROGRESSED;
	}

	uint8_t Scene::GetNumOfCols() const
	{
		return _numOfCols;
	}

	uint8_t Scene::GetNumOfRows() const
	{
		return _numOfRows;
	}

	/// <summary>
	/// Write data from _sceneData into _sceneData_char after converting to chars
	/// </summary>
	void Scene::WriteToChar()
	{
		assert(_currSceneMode == SceneMode::PLAYER_UPDATED);
		
		// Write terrain and floor
		uint8_t buffVal;
		uint8_t rowNum, colNum, arrayIdx;
		for(rowNum = 0; rowNum < _numOfRows; rowNum++)
		{
			for (colNum = 0; colNum < _numOfCols; colNum++)
			{
				arrayIdx = (_numOfCols * rowNum) + colNum;
				buffVal = _sceneData[arrayIdx];

				if (rowNum >= 0 && rowNum < (_numOfRows - 1))
				{
					// terrain
					assert(buffVal < ((sizeof(converterTerrain)) / (sizeof(converterTerrain[0]))));
					_sceneData_char[arrayIdx] = converterTerrain[buffVal];
				}
				else if (rowNum == (_numOfRows - 1))
				{
					// floor
					assert(buffVal < ((sizeof(converterFloor)) / (sizeof(converterFloor[0]))));
					_sceneData_char[arrayIdx] = converterFloor[buffVal];
				}
				else
				{
					assert(false);
				}
			}
		}

		
		// Write player last
		switch (_sceneData_Player)
		{
			case PlayerPos::NORMAL:
				assert(_sceneData[(0 * _numOfCols) + 0] == TerrainEnum::EMPTY);
				_sceneData_char[(0 * _numOfCols) + 0] = converterPlayer[1];

				assert(_sceneData[(1 * _numOfCols) + 0] == TerrainEnum::EMPTY);
				_sceneData_char[(1 * _numOfCols) + 0] = converterPlayer[1];

				assert(_sceneData[(2 * _numOfCols) + 0] == TerrainEnum::EMPTY);
				_sceneData_char[(2 * _numOfCols) + 0] = converterPlayer[1];
				break;

			case PlayerPos::JUMP:
				assert(_sceneData[(0 * _numOfCols) + 0] == TerrainEnum::EMPTY);
				_sceneData_char[(0 * _numOfCols) + 0] = converterPlayer[2];
				break;

			case PlayerPos::DIVE:
				assert(_sceneData[(1 * _numOfCols) + 0] == TerrainEnum::EMPTY);
				_sceneData_char[(1 * _numOfCols) + 0] = converterPlayer[2];
				break;

			case PlayerPos::DUCK:
				assert(_sceneData[(2 * _numOfCols) + 0] == TerrainEnum::EMPTY);
				_sceneData_char[(2 * _numOfCols) + 0] = converterPlayer[2];
				break;

			default:
				assert(false);
		}
	}
}
