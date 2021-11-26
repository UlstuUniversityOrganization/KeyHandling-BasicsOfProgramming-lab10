#include "Player.h"

Player::Player()
{
	pos = {0, 0};
	size = {50, 50};
}

void Player::Update()
{

}

void Player::Draw(HDC hdc, float2 origin)
{
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, brush);
	Rectangle(hdc, origin.x + pos.x, origin.y + pos.y, origin.x + pos.x + size.x, origin.y + pos.y + size.y);
}



