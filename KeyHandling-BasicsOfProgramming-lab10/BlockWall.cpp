#include "BlockWall.h"

BlockWall::BlockWall(float2 origin, float2 pos, float2 size) : Block(float3{ 0, 0, 0 }, origin, pos, size)
{
	isTransparent = false;
}

void BlockWall::Update()
{
}
