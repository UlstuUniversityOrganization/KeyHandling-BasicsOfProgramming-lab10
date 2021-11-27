#include "MapManager.h"
#include "Entity.h"

MapManager::MapManager(float2 origin, float2 blockSize)
{
    mapPaths.push_back("lvl1.txt");
    mapPaths.push_back("lvl2.txt");
    mapPaths.push_back("lvl3.txt");
    mapPaths.push_back("lvl4.txt");
}

MapManager::~MapManager()
{
    //for (int i = 0; i < mapPaths.size(); i++)
    //    delete mapPaths[i];
}
