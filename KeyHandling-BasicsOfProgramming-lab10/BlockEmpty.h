#pragma once
#include "Block.h"
class BlockEmpty : public Block
{
public:
	BlockEmpty(float2 origin, float2 pos, float2 size);
	virtual void Update() override;
};

