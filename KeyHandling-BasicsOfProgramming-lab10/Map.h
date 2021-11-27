#pragma once
#include "Block.h"
#include <vector>
class Entity;
class MapManager;
class Player;

class Map
{
public:
	Block*** blocks;
	std::vector<Entity*> entities;
	Player* player;
	MapManager* parentMapManager;
	float2 origin;
	float2 blockSize;
	int xCount;
	int yCount;

	Map(MapManager* parentMapManager, float2 origin, float2 blockSize);
	~Map();
	void Load(const char* filePath);
};

