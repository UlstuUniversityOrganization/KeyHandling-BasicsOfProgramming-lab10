#include "Map.h"
#include "Entity.h"
#include "MapManager.h"
#include "Player.h"

Map::Map(MapManager* parentMapManager, float2 origin, float2 blockSize)
{
    this->parentMapManager = parentMapManager;
    this->origin = origin;
    this->blockSize = blockSize;
    int xCount = 0;
    int yCount = 0;
}

Map::~Map()
{
    for (int x = 0; x < xCount; x++)
        for (int y = 0; y < yCount; y++)
            if (blocks[x][y])
                delete blocks[x][y];

    for (int x = 0; x < xCount; x++)
    {
        if (blocks[x])
            delete[yCount] blocks[x];
    }
    if (blocks)
        delete[xCount] blocks;

    for (int i = 0; i < entities.size(); i++)
        if (entities[i])
            entities[i];
    entities.clear();
}

void Map::Load(const char* filePath)
{
    Map::~Map();
    entities = std::vector<Entity*>();
    int** blockID;
    int** entityID;

    FILE* filePointer;
    fopen_s(&filePointer, filePath, "r");

    fscanf_s(filePointer, "%d", &xCount);
    fscanf_s(filePointer, "%d", &yCount);

    blocks = new Block * *[xCount];
    for (int x = 0; x < xCount; x++)
        blocks[x] = new Block * [yCount];


    blockID = new int* [xCount];
    entityID = new int* [xCount];
    for (int i = 0; i < xCount; i++)
    {
        blockID[i] = new int[yCount];
        entityID[i] = new int[yCount];
    }


    for (int i = 0; i < yCount; i++)
        for (int j = 0; j < xCount; j++)
            fscanf_s(filePointer, "%d", &(blockID[j][i]));

    for (int i = 0; i < yCount; i++)
        for (int j = 0; j < xCount; j++)
            fscanf_s(filePointer, "%d", &(entityID[j][i]));

    for (int y = 0; y < yCount; y++)
        for (int x = 0; x < xCount; x++)
        {
            float posX = (float)x * blockSize.x;
            float posY = (float)y * blockSize.y;
            blocks[x][y] = Block::GetBlock(blockID[x][y], origin, float2{ posX, posY }, blockSize);

            Entity* entity = Entity::GetEntity(entityID[x][y], parentMapManager, float2{ posX, posY }, blockSize);
            if (entity)
                entities.push_back(entity);
        }

    for (int x = 0; x < xCount; x++)
    {
        delete[yCount] blockID[x];
        delete[yCount] entityID[x];
    }
    delete[xCount] blockID;
    delete[xCount] entityID;

    for (int i = 0; i < entities.size(); i++)
    {
        player = dynamic_cast<Player*>(entities[i]);
        if (player)
            break;
    }
}
