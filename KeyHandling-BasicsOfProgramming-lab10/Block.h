#pragma once
#include "mymath.h"
#include <Windows.h>
class Block
{
public:
	float2 pos;
	float2 origin;
	float2 size;
	Block(COLORREF color);
	virtual void Update() = 0;
	virtual void Draw(HDC hdc);
private:
	COLORREF color;
};

