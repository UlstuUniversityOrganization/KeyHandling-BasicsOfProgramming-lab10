#include "framework.h"
#include "KeyHandling-BasicsOfProgramming-lab10.h"
#include "stdio.h"
#include "Player.h"
#include <vector>
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                        
WCHAR szTitle[MAX_LOADSTRING];           
WCHAR szWindowClass[MAX_LOADSTRING];          

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_KEYHANDLINGBASICSOFPROGRAMMINGLAB10, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KEYHANDLINGBASICSOFPROGRAMMINGLAB10));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KEYHANDLINGBASICSOFPROGRAMMINGLAB10));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_KEYHANDLINGBASICSOFPROGRAMMINGLAB10);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

int** LoadTwoDimensionalArray(const char* filePath, int* columnsCount, int* rowsCount)
{
    int** localTable;
    FILE* filePointer;
    fopen_s(&filePointer, filePath, "r");

    fscanf_s(filePointer, "%d", columnsCount);
    fscanf_s(filePointer, "%d", rowsCount);

    localTable = new int* [(*columnsCount)];
    for (int i = 0; i < (*columnsCount); i++)
        localTable[i] = new int[(*rowsCount)];

    for (int i = 0; i < *rowsCount; i++)
        for (int j = 0; j < (*columnsCount); j++)
            fscanf_s(filePointer, "%d", &(localTable[j][i]));

    return localTable;
}

float2 DrawTwoDimensionalArray(HDC hdc, int** array, int xElementsCount, int yElementsCount, int left, int top, int right, int bottom)
{
    int rectangleWidth = (right - left) / (float)xElementsCount;
    int rectangleHeight = (bottom - top) / (float)yElementsCount;
    for (int y = 0; y < yElementsCount; y++)
    {
        for (int x = 0; x < xElementsCount; x++)
        {
            HBRUSH brush = CreateSolidBrush(RGB(array[x][y] * 255, array[x][y] * 255, array[x][y] * 255));
            SelectObject(hdc, brush);
            Rectangle(hdc, left + rectangleWidth * x, top + rectangleHeight * y, left + rectangleWidth * (1 + x), top + rectangleHeight * (1 + y));

        }
    }
    float2 size = { rectangleWidth, rectangleHeight };
    return size;
}

int** map;
int xCount = -1;
int yCount = -1;
float2 mapOrigin = {0, 0};
std::vector<Entity*> entities;
Player* player;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        SetTimer(hWnd, 0, 100, (TIMERPROC) NULL);

        map = LoadTwoDimensionalArray("data.txt", &xCount, &yCount);

        player = new Player();
        player->color = RGB(100, 100, 255);
        player->map = map;
        entities.push_back((Entity*)player);

    }
    case WM_TIMER:
        {
            switch (wParam)
            {
                case 0:
                {
                    InvalidateRect(hWnd, NULL, TRUE);
                    break;
                }
            }
        }
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_KEYDOWN:
    {

        switch (wParam)
        {
            case VK_UP:
            {
                InvalidateRect(hWnd, NULL, TRUE);
                player->MoveTo(MoveDirection::Up);
                break;
            }
            case VK_RIGHT:
            {
                InvalidateRect(hWnd, NULL, TRUE);
                player->MoveTo(MoveDirection::Right);
                break;
            }
            case VK_DOWN:
            {
                InvalidateRect(hWnd, NULL, TRUE);
                player->MoveTo(MoveDirection::Down);
                break;
            }
            case VK_LEFT:
            {
                InvalidateRect(hWnd, NULL, TRUE);
                player->MoveTo(MoveDirection::Left);
                break;
            }
        }
    }
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            float2 rectangleSize = DrawTwoDimensionalArray(hdc, map, xCount, yCount, mapOrigin.x, mapOrigin.y, mapOrigin.x + 500, mapOrigin.y + 500);\

            for (int i = 0; i < entities.size(); i++)
            {
                entities[i]->size = rectangleSize;
                entities[i]->Update();
                entities[i]->Draw(hdc, mapOrigin);
            }
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
