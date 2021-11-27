#include "SpikesBlock.h"

SpikesBlock::SpikesBlock(float2 origin, float2 pos, float2 size) : Block(float3{ 100, 100, 100 }, origin, pos, size)
{
	teamID = 1;
}

void SpikesBlock::Update()
{
	if (timer <= spikeOnTimer)
	{
		timer++;
	}
	else 
	{
		timer = 0;
		spikesOn = !spikesOn;
	}
}

void SpikesBlock::Draw(HDC hdc)
{
	Block::Draw(hdc);
	
	HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
	SelectObject(hdc, brush);
	if (spikesOn)
	{
		canBeat = true;
		int spikeSizeX = size.x / spikesCountX;
		int spikeSizeY = size.y / spikesCountY;
		for (int y = 0; y < spikesCountY; y++)
			for (int x = 0; x < spikesCountX; x++)
			{
				Ellipse(hdc, pos.x + x * spikeSizeX, pos.y + y * spikeSizeY, pos.x + spikeSizeX + spikeSizeX * x, pos.y + spikeSizeY + spikeSizeY * y);
			}

	}
	else
	{
		canBeat = false;
	}
	DeleteObject(brush);
}
