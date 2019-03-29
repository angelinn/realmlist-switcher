#include "UI/MainWindow.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	LoadStrings(hInstance);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_REALMLISTSWITCHERWIN32));

	MSG msg = { 0 };
	
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



typedef struct SizeAndPos_s
{
	int x, y, width, height;
} SizeAndPos_t;

// typically these would be #defines but there is no reason to not make them constants
const WORD ID_btnHELLO = 1;
const WORD ID_btnQUIT = 2;
const WORD ID_CheckBox = 3;
const WORD ID_txtEdit = 4;
const WORD ID_btnShow = 5;

//                                    x,      y,      width,  height
const SizeAndPos_t mainWindow = { 150,    150,    300,    300 };

const SizeAndPos_t btnHello = { 20,     50,     80,     25 };
const SizeAndPos_t btnQuit = { 120,    50,     80,     25 };
const SizeAndPos_t chkCheck = { 20,     90,     185,    35 };

const SizeAndPos_t txtEdit = { 20,     150,    150,    20 };
const SizeAndPos_t btnShow = { 180,    150,    80,     25 };

void CreateAboutDialog(HWND window)
{
	CreateWindowW(L"Button", L"Hello", WS_VISIBLE | WS_CHILD,
		btnHello.x, btnHello.y, btnHello.width, btnHello.height, window, (HMENU)ID_btnHELLO, NULL, NULL);
	CreateWindowW(L"Button", L"Quit", WS_VISIBLE | WS_CHILD,
		btnQuit.x, btnQuit.y, btnQuit.width, btnQuit.height, window, (HMENU)ID_btnHELLO, NULL, NULL);
}
