#pragma once
#include "Block.h"
class BlockEmpty : public Block
{
public:
	BlockEmpty();
	virtual void Update() override;
};

