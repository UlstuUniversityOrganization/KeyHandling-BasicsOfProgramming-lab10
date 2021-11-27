#include "EntityCreepDire.h"

EntityCreepDire::EntityCreepDire(MapManager* mapManager, float2 pos, float2 size) : Entity(float3{150, 50, 50}, mapManager, pos, size)
{
	teamID = 1;
}

void EntityCreepDire::Update()
{
	Entity::Update();
	if (rotationTimer >= timeToRotate)
	{
		rotationTimer++;
	}
	else
	{
		dir = rand() % 10;
		rotationTimer = 0;
	}
	if(dir < 5)
		MoveTo(dir);
}
