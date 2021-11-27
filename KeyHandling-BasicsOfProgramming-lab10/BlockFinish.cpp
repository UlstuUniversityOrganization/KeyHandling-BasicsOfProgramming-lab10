#include "BlockFinish.h"
#include "Player.h"
BlockFinish::BlockFinish(float2 origin, float2 pos, float2 size) : Block(float3{255, 255, 255}, origin, pos, size)
{
}

void BlockFinish::Update()
{
	color = float3{ (float)(rand() % 256), (float)(rand() % 256), (float)(rand() % 256) };
}

void BlockFinish::OnEntityCollision(Entity* entity)
{
	Player* player = dynamic_cast<Player*>(entity);
	if (player)
	{
		MapManager* mapManager = player->mapManager;
		if(mapManager->activeMap + 1 < mapManager->mapPaths.size())
			mapManager->activeMap++;
		else 
			mapManager->activeMap = 0;
		mapManager->map.Load(mapManager->mapPaths[mapManager->activeMap]);
	}

}
