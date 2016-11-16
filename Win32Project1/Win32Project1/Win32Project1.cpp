// Win32Project1.cpp: ���������� ����� ����� ��� ����������.
//

#include "stdafx.h"
#include "Win32Project1.h"

#define MAX_LOADSTRING 100

// ���������� ����������:
HBRUSH greenBrush;
int wTrack = 1;                                 // ���-�� �������� ����
bool b = false;                                 // �������� ���������� �������� ����
HINSTANCE hInst;								// ������� ���������
HWND hWnd1;
HWND hWnd2;
HWND hWnd3;
HWND hWnd4;
HWND hWnd5;
TCHAR szTitle[MAX_LOADSTRING];					// ����� ������ ���������
TCHAR szWindowClass[MAX_LOADSTRING];			// ��� ������ �������� ����

// ��������� ���������� �������, ���������� � ���� ������ ����:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: ���������� ��� �����.
	MSG msg;
	HACCEL hAccelTable;

	// ������������� ���������� �����
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ��������� ������������� ����������:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

	// ���� ��������� ���������:
	while (GetMessage(&msg, NULL, 0, 0))
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
//  �������: MyRegisterClass()
//
//  ����������: ������������ ����� ����.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+2);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   �������: InitInstance(HINSTANCE, int)
//
//   ����������: ��������� ��������� ���������� � ������� ������� ����.
//
//   �����������:
//
//        � ������ ������� ���������� ���������� ����������� � ���������� ����������, � �����
//        ��������� � ��������� �� ����� ������� ���� ���������.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��������� ���������� ���������� � ���������� ����������

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �������: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����������:  ������������ ��������� � ������� ����.
//
//  WM_COMMAND	- ��������� ���� ����������
//  WM_PAINT	-��������� ������� ����
//  WM_DESTROY	 - ������ ��������� � ������ � ���������.
//
//
LRESULT CALLBACK ChildProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	if (Message == WM_DESTROY)
	{
		return 0;
	}
	return DefWindowProc(hwnd, Message, wparam, lparam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_MOUSEMOVE:
		MoveWindow(hWnd, 100, 100, 800, 300, TRUE);
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// ��������� ����� � ����:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			if (MessageBox(hWnd, L"Do u rly want 2 quit?", L"Bye", MB_OKCANCEL | MB_DEFBUTTON1) == IDOK)
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
		//---------------------------------------------------------------------------------------------------------------------------
		//������ ����
	case WM_LBUTTONDOWN:
		if (!b)
			switch (wTrack){
			
			case 1:
				hWnd1 = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | WS_POPUP,
				140, 140, 150, 150, hWnd, NULL, NULL, NULL);
				wTrack++;
			    ShowWindow(hWnd1, SW_SHOW);
			    UpdateWindow(hWnd1);
			    break;
			case 2: 
				hWnd2 = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | WS_POPUP,
				160, 160, 150, 150, hWnd, NULL, NULL, NULL);
				wTrack++;
				ShowWindow(hWnd1, SW_SHOW);
				UpdateWindow(hWnd1);
				break;
			case 3:
				hWnd3 = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | WS_POPUP,
				180, 180, 150, 150, hWnd, NULL, NULL, NULL);
				wTrack++;
				ShowWindow(hWnd1, SW_SHOW);
				UpdateWindow(hWnd1);
				break;
			case 4: 
				hWnd4 = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | WS_POPUP,
				200,200, 150, 150, hWnd, NULL, NULL, NULL);
				wTrack++;
				ShowWindow(hWnd1, SW_SHOW);
				UpdateWindow(hWnd1);
				break;
			case 5: 
				hWnd5 = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | WS_POPUP,
				220, 220, 150, 150, hWnd, NULL, NULL, NULL);
				ShowWindow(hWnd1, SW_SHOW);
				UpdateWindow(hWnd1);
				b = true;
				break;
		}
		else {
			switch (wTrack){
			case 5: DestroyWindow(hWnd5); wTrack--; break;
			case 4: DestroyWindow(hWnd4); wTrack--; break;
			case 3: DestroyWindow(hWnd3); wTrack--; break;
			case 2: DestroyWindow(hWnd2); wTrack--; break;
			case 1: DestroyWindow(hWnd1); b = false; break;
			}
			
		}
		break;
	//---------------------------------------------------------------------------------------------------------------------------
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: �������� ����� ��� ���������...
		EndPaint(hWnd, &ps);
		break;

		//�������� ����
	case WM_CLOSE:                                                                                           
		if (MessageBox(hWnd, L"Do u rly want 2 quit?", L"Bye", MB_OKCANCEL | MB_DEFBUTTON1) == IDOK)
			DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���������� ��������� ��� ���� "� ���������".
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

