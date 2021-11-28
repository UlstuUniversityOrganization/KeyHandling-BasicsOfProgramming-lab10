#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	int health = 3;
	bool immortality = false;
	int immortaltyTimer = 0;
	int immortaltyTime = 3;
	float3 colorAlive;
	float3 colorImmortal;
	int gameOverScreenTimer = 0;
	int gameOverScreenTime = 15;
	Player(MapManager* mapManager, float2 pos, float2 size);
	virtual void Update() override;
};

