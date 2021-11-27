#pragma once
#include <Windows.h>
#include "block.h"
#include <vector>
#include "MapManager.h"

#define Move
enum MoveDirection
{
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3
};

class Entity
{
public:
	int teamID = 0;
	float2 pos;
	float2 size;
	float3 color;
	float2 origin;
	MapManager* mapManager;
	Entity(float3 color, MapManager* mapManager, float2 pos, float2 size);
	static Entity* GetEntity(int id, MapManager* mapManager, float2 pos, float2 size);
	virtual bool MoveTo(int dir);
	virtual void Update();
	virtual void Draw(HDC hdc);
};

