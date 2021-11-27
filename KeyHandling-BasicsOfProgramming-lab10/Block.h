#pragma once
#include "mymath.h"
#include <Windows.h>
class Entity;
class Block
{
public:
	float2 pos;
	float2 origin;
	float2 size;
	int teamID = 0;
	bool canBeat;
	bool isTransparent = true;
	Block(float3 color, float2 origin, float2 pos, float2 size);
	static Block* GetBlock(int id, float2 origin, float2 pos, float2 size);
	virtual void Update() = 0;
	virtual void OnEntityCollision(Entity* entity);
	virtual void Draw(HDC hdc);
	float3 color;
};

