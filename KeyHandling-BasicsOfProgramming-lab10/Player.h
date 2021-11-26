#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	//virtual void MoveTo(MoveDirection dir, int** map) override;
	virtual void Update() override;
	virtual void Draw(HDC hdc, float2 origin) override;
};

