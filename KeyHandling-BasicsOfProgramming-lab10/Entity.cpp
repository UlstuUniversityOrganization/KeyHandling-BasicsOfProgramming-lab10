#include "Entity.h"

void Entity::MoveTo(MoveDirection dir)
{
    switch (dir)
    {
    case MoveDirection::Up:
    {
        pos.y -= size.y;
        break;
    }
    case MoveDirection::Right:
    {
        pos.x += size.x;
        break;
    }
    case MoveDirection::Down:
    {
        pos.y += size.y;
        break;
    }
    case MoveDirection::Left:
    {
        pos.x -= size.x;
        break;
    }
    }
}
