#pragma once
#include <Windows.h>
#include "mymath.h"
enum class MoveDirection
{
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3
};

class Entity
{
public:
	float2 pos;
	float2 size;
	COLORREF color;
	int** map;
	virtual void MoveTo(MoveDirection dir);
	virtual void Update() = 0;
	virtual void Draw(HDC hdc, float2 origin) = 0;
};

