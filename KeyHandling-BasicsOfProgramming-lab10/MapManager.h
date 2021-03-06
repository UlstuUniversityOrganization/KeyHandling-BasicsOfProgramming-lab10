#pragma once
#include "Block.h"
#include <vector>
#include "Map.h"

class MapManager
{
public:
	Map map = Map(this, float2{ 0, 0 }, float2{ 50, 50 });
	std::vector<const char*> mapPaths;
	int activeMap = 0;
	bool isDrawing = true;
	bool isUpdating = true;
	int gameOverScreenTimer = 0;
	int gameOverScreenTime = 0;
	bool isDrawingGameOverScreen = false;
	MapManager(float2 origin, float2 blockSize);
	~MapManager();
	void SetGameOverScreen(HDC hdc, HWND hwnd);
};

