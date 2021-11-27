#pragma once
#include "Block.h"
class SpikesBlock : public Block
{
public:
	int timer = 0;
	int spikeOnTimer = 10;
	bool spikesOn;
	int spikesCountX = 3;
	int spikesCountY = 3;
	SpikesBlock(float2 origin, float2 pos, float2 size);
	virtual void Update() override;
	virtual void Draw(HDC hdc) override;
};

