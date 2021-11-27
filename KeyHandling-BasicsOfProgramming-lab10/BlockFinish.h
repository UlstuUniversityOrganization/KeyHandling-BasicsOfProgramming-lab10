#pragma once
#include "Block.h"
class BlockFinish : public Block
{
public:
	BlockFinish(float2 origin, float2 pos, float2 size);
	virtual void Update() override;
	virtual void OnEntityCollision(Entity* entity) override;
};

