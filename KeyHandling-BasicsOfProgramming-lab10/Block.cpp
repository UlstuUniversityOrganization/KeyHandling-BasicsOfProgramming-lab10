#include "Block.h"

Block::Block(COLORREF color)
{
	this->color = color;
}

void Block::Draw(HDC hdc)
{
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, brush);
	Rectangle(hdc, origin.x + size.x * pos.x, origin.y + size.y * pos.y, origin.x + size.x * (1 + pos.x), origin.y + size.y * (1 + pos.y));
}
