#pragma once
#include "Entity.h"
class EntityCreepDire : public Entity
{
public:
	int dir = 0;
	int rotationTimer = 0;
	int timeToRotate = 5;

	EntityCreepDire(MapManager* mapManager, float2 pos, float2 size);
	virtual void Update();
};

