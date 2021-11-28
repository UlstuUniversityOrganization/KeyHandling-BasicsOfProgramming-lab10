#include "Entity.h"
#include "mymath.h"
#include "Player.h"
#include "EntityCreepDire.h"
#include "BlockFinish.h"

bool myClamp(int edge0, int edge1, int value)
{
    if (value >= edge0 && value <= edge1)
        return true;
    return false;
}

Entity::Entity(float3 color, MapManager* mapManager, float2 pos, float2 size)
{
    this->mapManager = mapManager;
    this->pos = pos;
    this->size = size;
    origin = { 0, 0 };
    this->color = color;
}

bool Entity::MoveTo(int dir)
{
    switch (dir)
    {
    case MoveDirection::Up:
    {
        int newPosX = ((int)pos.x - mapManager->map.origin.x) / (int)size.x;
        int newPosY = (((int)pos.y - (int)size.y) - mapManager->map.origin.y) / (int)size.y;

        Block* block = nullptr;
        if (myClamp(0, mapManager->map.xCount - 1, newPosX) && myClamp(0, mapManager->map.yCount - 1, newPosY))
            block = mapManager->map.blocks[newPosX][newPosY];

        if (!block || (block && block->isTransparent == true))
            pos.y -= size.y;

        else
            return false;
        break;
    }
    case MoveDirection::Right:
    {
        int newPosX = (((int)pos.x + size.x) - mapManager->map.origin.x) / (int)size.x;
        int newPosY = ((int)pos.y - mapManager->map.origin.y) / (int)size.y;

        Block* block = nullptr;
        if (myClamp(0, mapManager->map.xCount - 1, newPosX) && myClamp(0, mapManager->map.yCount - 1, newPosY))
            block = mapManager->map.blocks[newPosX][newPosY];

        if (!block || (block && block->isTransparent == true))
            pos.x += size.x;
        else
            return false;

        break;
    }
    case MoveDirection::Down:
    {
        int newPosX = ((int)pos.x - mapManager->map.origin.x) / (int)size.x;
        int newPosY = (((int)pos.y + size.y) - mapManager->map.origin.y) / (int)size.y;

        Block* block = nullptr;
        if (myClamp(0, mapManager->map.xCount - 1, newPosX) && myClamp(0, mapManager->map.yCount - 1, newPosY))
            block = mapManager->map.blocks[newPosX][newPosY];

        if (!block || (block && block->isTransparent == true))
            pos.y += size.y;
        else
            return false;
        break;
    }
    case MoveDirection::Left:
    {
        int newPosX = (((int)pos.x - size.x) - mapManager->map.origin.x) / (int)size.x;
        int newPosY = ((int)pos.y - mapManager->map.origin.y) / (int)size.y;

        Block* block = nullptr;
        if (myClamp(0, mapManager->map.xCount - 1, newPosX) && myClamp(0, mapManager->map.yCount - 1, newPosY))
            block = mapManager->map.blocks[newPosX][newPosY];

        if (!block || (block && block->isTransparent == true))
            pos.x -= size.x;
        else
            return false;
        break;
    }
    }
}

void Entity::Update()
{
    int posX = (pos.x - mapManager->map.origin.x) / size.x;
    int posY = (pos.y  - mapManager->map.origin.y) / size.y;

    if (myClamp(0, mapManager->map.xCount - 1, posX) && myClamp(0, mapManager->map.yCount - 1, posY))
        if (mapManager->map.blocks[posX][posY])
            mapManager->map.blocks[posX][posY]->OnEntityCollision(this);
}

void Entity::Draw(HDC hdc)
{
    HBRUSH brush = CreateSolidBrush(RGB((int)color.x, (int)color.y, (int)color.z));
    SelectObject(hdc, brush);
    Rectangle(hdc, origin.x + pos.x, origin.y + pos.y, origin.x + pos.x + size.x, origin.y + pos.y + size.y);
    DeleteObject(brush);
}

Entity* Entity::GetEntity(int id, MapManager* mapManager, float2 pos, float2 size)
{
    Entity* entity = nullptr;
    switch (id)
    {
    case 1:
    {
        entity = new Player(mapManager, pos, size);
        break;
    }
    case 2:
    {
        entity = new EntityCreepDire(mapManager, pos, size);
    }
    }
    return entity;
}
