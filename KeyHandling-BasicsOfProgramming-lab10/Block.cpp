#include "Block.h"
#include "mymath.h"
#include "BlockEmpty.h"
#include "BlockWall.h"
#include "SpikesBlock.h"
#include "BlockFinish.h"

Block::Block(float3 color, float2 origin, float2 pos, float2 size)
{
	this->color = color;
	this->origin = origin;
	this->pos = pos;
	this->size = size;

}
Block* Block::GetBlock(int id, float2 origin, float2 pos, float2 size)
{
    Block* block = nullptr;
    switch (id)
    {
    case 0:
    {
        block = new BlockEmpty(origin, pos, size);
        break;
    }
    case 1:
    {
        block = new BlockWall(origin, pos, size);
        break;
    }
    case 2:
    {
        block = new SpikesBlock(origin, pos, size);
        break;
    }
    case 3:
    {
        block = new BlockFinish(origin, pos, size);
        break;
    }
    }
    return block;
}

void Block::OnEntityCollision(Entity* entity)
{
}

void Block::Draw(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(color.x, color.y, color.z));
	SelectObject(hdc, brush);
	Rectangle(hdc, origin.x + pos.x, origin.y + pos.y, origin.x + pos.x + size.x, origin.y + pos.y + size.y);
	DeleteObject(brush);
}

