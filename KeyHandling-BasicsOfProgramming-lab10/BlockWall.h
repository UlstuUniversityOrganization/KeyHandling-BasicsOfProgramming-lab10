#pragma once
#include "Block.h"
class BlockWall : public Block
{
public:
	BlockWall(float2 origin, float2 pos, float2 size);
	virtual void Update() override;
};

