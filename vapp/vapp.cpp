// vapp.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "vapp.h"

#define MAX_LOADSTRING 100
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hWnd;
HINSTANCE hdll;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int, int, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

typedef bool (* LPFNGameInit)();
typedef bool (* LPFNGameStart)(HWND hwnd);
typedef bool (* LPFNGameStop)();
typedef void (* LPFNGameUpdate)();
typedef void (* LPFNGameRender)();
typedef bool (* LPFNGameSetClientWindow)(int width, int height);
typedef int (* LPFNGameGetWidth)();
typedef int (* LPFNGameGetHeight)();
LPFNGameStop pfnGameStop = NULL;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_VAPP, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);

    // Perform application initialization:
	/*
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_VAPP));
	*/
	LPFNGameUpdate pfnGameUpdate = NULL;
	LPFNGameRender pfnGameRender = NULL;
	hdll = LoadLibrary(_T("valkyr"));
	int winWidth = 0;
	int winHeight = 0;
	MSG msg = {0};

	if (hdll != NULL) {
		LPFNGameInit pfnGameInit = (LPFNGameInit)GetProcAddress(hdll, "game_init");
		if (pfnGameInit == NULL) {
			FreeLibrary(hdll);
			if (MessageBox(0, _T("function gameinit not found"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
				PostQuitMessage(0);
		}
		else {
			if (!pfnGameInit())
			{
				if (MessageBox(0, _T(" initialization error"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
					PostQuitMessage(0);
			}
			else
			{
			}
		}
		
		LPFNGameSetClientWindow pfnSetClientWindow = (LPFNGameSetClientWindow)GetProcAddress(hdll, "game_setclientwindow");
		if (pfnSetClientWindow == NULL) {
			FreeLibrary(hdll);
			if (MessageBox(0, _T("window config error"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
				PostQuitMessage(0);
		}
		else
		{
			pfnSetClientWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
		}
		
		//winWidth = WINDOW_WIDTH;
		//winHeight = WINDOW_HEIGHT;
		
		LPFNGameGetWidth pfnGetWidth = (LPFNGameGetWidth)GetProcAddress(hdll, "game_getwidth");
		if (pfnGetWidth == NULL) {
			FreeLibrary(hdll);
			if (MessageBox(0, _T("window config error"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
				PostQuitMessage(0);
		}
		else
		{
			winWidth = pfnGetWidth();
		}
		LPFNGameGetHeight pfnGetHeight = (LPFNGameGetHeight)GetProcAddress(hdll, "game_getheight");
		if (pfnGetHeight == NULL) {
			FreeLibrary(hdll);
			if (MessageBox(0, _T("window config error"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
				PostQuitMessage(0);
		}
		else
		{
			winHeight = pfnGetHeight();
		}
		
		if (!InitInstance(hInstance, nCmdShow, winWidth, winHeight))
		{
			return FALSE;
		}
		LPFNGameStart pfnGameStart = (LPFNGameStart)GetProcAddress(hdll, "game_start");
		if (pfnGameStart == NULL) {
			FreeLibrary(hdll);
			if (MessageBox(0, _T("function gamestart not found"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
				PostQuitMessage(0);
		}
		else {
			if (!pfnGameStart(hWnd))
			{
				if (MessageBox(0, _T("launch error"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
					PostQuitMessage(0);
			}
			else
			{
			}
		}
		pfnGameUpdate = (LPFNGameUpdate)GetProcAddress(hdll, "game_update");
		if (pfnGameUpdate == NULL) {
			FreeLibrary(hdll);
			if (MessageBox(0, _T("function gameUpdate not found"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
				PostQuitMessage(0);
		}
		pfnGameRender = (LPFNGameRender)GetProcAddress(hdll, "game_render");
		if (pfnGameRender == NULL) {
			FreeLibrary(hdll);
			if (MessageBox(0, _T("function gameRender not found"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
				PostQuitMessage(0);
		}
	}
	else {
		//FreeLibrary(hdll);
		if (MessageBox(0, _T("valkyr.dll not found"), _T("Error"), MB_ICONERROR | MB_OK) == IDOK)
			PostQuitMessage(0);
	}

    // Main message loop:
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			pfnGameUpdate();
			pfnGameRender();
		}
	}

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_VAPP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    //wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_VAPP);
	wcex.lpszMenuName = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow, int width, int height)
{
   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		pfnGameStop = (LPFNGameStop)GetProcAddress(hdll, "game_stop");
		if (pfnGameStop == NULL) {
			FreeLibrary(hdll);
			MessageBox(0, _T("function gameStop not found"), _T("Error"), MB_ICONERROR | MB_OK);
		}
		if (pfnGameStop())
		{
			MessageBox(0, _T("Application will Exit"), _T("Warning"), 0);
		}
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
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
