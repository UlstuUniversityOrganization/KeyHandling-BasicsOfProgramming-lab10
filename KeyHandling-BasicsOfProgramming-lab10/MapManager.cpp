#include "MapManager.h"
#include "Entity.h"
#include <tchar.h>

MapManager::MapManager(float2 origin, float2 blockSize)
{
    mapPaths.push_back("lvl1.txt");
    mapPaths.push_back("lvl2.txt");
    mapPaths.push_back("lvl3.txt");
    mapPaths.push_back("lvl4.txt");
}

MapManager::~MapManager()
{
}

void MapManager::SetGameOverScreen(HDC hdc, HWND hwnd)
{
    if (isDrawingGameOverScreen == true)
    {
        RECT clientRect;
        GetClientRect(hwnd, &clientRect);
        int width = clientRect.right - clientRect.left;
        int height = clientRect.bottom - clientRect.top;

        int fontHight = 100;
        int fontWidth = 0;

        HFONT hFont = CreateFont(fontHight, fontWidth, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
        SelectObject(hdc, hFont);
        SetTextColor(hdc, RGB(255, 0, 0));

        TCHAR text[] = _T("Game over");

        TextOut(hdc, width * 0.30f, height * 0.5f - fontHight * 0.5f, (LPCWSTR)text, _tcslen(text));
    }
}
