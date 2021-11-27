#include "Player.h"
#include "BlockFinish.h"
float Interpolate(float a, float b, float t)
{
	return a + (b - a) * t;
}

bool myClamp2(int edge0, int edge1, int value)
{
	if (value >= edge0 && value <= edge1)
		return true;
	return false;
}


Player::Player(MapManager* mapManager, float2 pos, float2 size) : Entity(float3{100, 100, 255}, mapManager, pos, size)
{
	teamID = 0;
	colorAlive = color;
	float t = 0.5f;
	colorImmortal = float3{ Interpolate(colorAlive.x, 255, t), Interpolate(colorAlive.y, 0, t), Interpolate(colorAlive.z, 0, t) };
}

void Player::Update()
{
	Entity::Update();
	int blockPosX = (pos.x - mapManager->map.origin.x) / mapManager->map.blockSize.x;
	int blockPosY = (pos.y - mapManager->map.origin.y) / mapManager->map.blockSize.y;

	if (health <= 0)
	{
		mapManager->activeMap = 0;
		mapManager->map.Load(mapManager->mapPaths[mapManager->activeMap]);
	}
	if (health > 0)
	{
		if (!immortality)
		{
			color = colorAlive;

			if(myClamp2(0, mapManager->map.xCount - 1, blockPosX) && myClamp2(0, mapManager->map.yCount - 1, blockPosY))
				if (mapManager->map.blocks[blockPosX][blockPosY]->canBeat == true && teamID != mapManager->map.blocks[blockPosX][blockPosY]->teamID)
				{
					health--;
					immortality = true;
				}
				else
				{
					for (int i = 0; i < mapManager->map.entities.size(); i++)
						if (teamID != mapManager->map.entities[i]->teamID)
							if (pos.x == mapManager->map.entities[i]->pos.x && pos.y == mapManager->map.entities[i]->pos.y)
							{
								health--;
								immortality = true;
								break;
							}
				}
		}
		else
		{
			color = colorImmortal;
			if (immortaltyTimer <= immortaltyTime)
				immortaltyTimer++;
			else
			{
				immortaltyTimer = 0;
				immortality = false;
			}
		}
	}
	else
	{

	}
}



