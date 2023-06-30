// 230608.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "230608.h"
#include "MainGame.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
HWND	g_hWnd;

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);		// â ��Ÿ���� �����ϴ� ����� �Լ�
BOOL                InitInstance(HINSTANCE, int);				// �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);		// �����쿡�� �߻��� �޼����� ���������� ó���ϴ� ����� ���
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);			// ������ â�� ���� ������ �˷��ִ� ����� �Լ�(������ �׸�)

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,		   // ���� ���α׷��� ���� �ĺ� ��ȣ(�޸𸮿� �Ҵ�Ǵ� ��ü, �� ��ü, ����Ǵ� ���α׷��� ���α׷� �ν��Ͻ��� ����)
                     _In_opt_ HINSTANCE hPrevInstance, // ���� ����Ǿ��� �ν��Ͻ��� �ڵ� ��(���� null)
                     _In_ LPWSTR    lpCmdLine,	
                     _In_ int       nCmdShow)    // ������ â�� ��Ÿ��(��� / �ּ�ȭ ��� ��)�� �ش��ϴ� ���ڰ� 
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY230608, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY230608));

    MSG msg;
	msg.message = WM_NULL;

	CMainGame		MainGame;
	MainGame.Initialize();

	// GetTickCount : � ü���� ���۵� �ķ� �帥 �ð��� ���� ���·� ��ȯ�ϴ� �Լ�
	// 1 / 1000���� DWORD ���� ������ ��ȯ(�и� ������)

	DWORD	dwTime = GetTickCount();	// 30
	
    while (true)
    {
		// PeekMessage : �޼����� �о���� TRUE, ���� �޼����� ������ FALSE�� ��ȯ

		// PM_REMOVE	  : �޼����� �о�Ȱ� ���ÿ� �޼��� ť���� ����
		// PM_NOREMOVE    : �޼��� ť�� �޼����� �����ϴ����� �ľ�, �޼����� �о���� ���ؼ� GetMessage�� �ٽ� ȣ������� ��

		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (WM_QUIT == msg.message)
				break;

			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			
			if (dwTime + 10 < GetTickCount())
			{
				MainGame.Update();
				MainGame.Late_Update();
				MainGame.Render();

                MainGame.UpdateStage();
							
				dwTime = GetTickCount();
			}			
		}        
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;		// ������ â�� ���鶧 ���� ������ Ŭ���� ������ �����ϱ� ���� ����ü

    wcex.cbSize = sizeof(WNDCLASSEX);	// �ڱ� �ڽ��� ����� ����

    wcex.style          = CS_HREDRAW | CS_VREDRAW; // ���θ� �ٽ� �׸� | ���θ� �ٽ� �׸�
    wcex.lpfnWndProc    = WndProc; // �����ص� �Լ��� ȣ��Ǿ� �޼����� ó����
    wcex.cbClsExtra     = 0; // �����찡 Ư���� �������� ����ϴ� ������ ����
    wcex.cbWndExtra     = 0; // ������ ���� �����̸� ������� ���� ��� 0
    wcex.hInstance      = hInstance;		// �� ������ Ŭ������ ����ϴ� ���α׷��� ��ȣ
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY230608));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);	// ��� ��
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;	// ���� ������ �̸��� ����(�������̸� ������Ʈ �̸��� ��ġ���� ������ ���� ���� ����)
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); // ������ â ��ܿ� �ִ� ���� ������ ����� ����

    return RegisterClassExW(&wcex);		// ����ü ������� ������ �Ϸ��ѵ�, �Լ��� �Ű� ������ ������ ����ü�� �����ϰ� �ý��ۿ� ��Ͻ�Ű�� ��ũ��
}		

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   RECT	rc{ 0,0,WINCX, WINCY };

   // rc = rc + �⺻ ������â ��Ÿ�� + �޴��� ũ�� ��� ����
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW,FALSE);

   HWND hWnd = CreateWindowW(szWindowClass, // �ռ� ������ ������ Ŭ������ ������ Ŭ������ �̸��� �־��ش�,.
							   szTitle,     //������â ��ܿ� ����� ���ڿ��� �̸�
							   WS_OVERLAPPEDWINDOW, // ������� �ϴ� â�� ��Ÿ���� �����ϴ� �Ű� ����, WS_OVERLAPPEDWINDOW �⺻ ������ â ��� ���� 
							   CW_USEDEFAULT, 0, // â�� �����Ǵ� X,Y ��ǥ
							   rc.right - rc.left,
							   rc.bottom - rc.top, // ����, ���� ������
							   nullptr, // �θ� �����찡 �ִٸ� �θ� �������� �ڵ��� ����
							   nullptr, // �����쿡�� ����� �޴��� �ڵ��� ����
							   hInstance,  // �����츦 ����� ��ü, ���α׷��� �ڵ��� ����
							   nullptr); // �ü���� Ư���� �������� ����ϹǷ� �ǵ帱 �� ����

   if (!hWnd)
   {
      return FALSE;
   }

   g_hWnd = hWnd;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//


RECT			rc{100, 100, 200, 200};
list<RECT>		BulletList;


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// ������(â)�� �����ϴ� �� ���� ���̺귯��
	// 1. KERNEL : �޸𸮸� �����ϰ� ���α׷��� �����Ű�� ����� ���
	// 2. USER : ���� �������̽��� ������ â�� ����
	// 3. GDI : ȭ�� ó���� �׷����� ���
	
    switch (message)
    {
	
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �޴� ������ ���� �м��մϴ�.
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
			// DC : ��¿� ���� ������ ���� �ִ� ������ ����ü

            HDC hdc = BeginPaint(hWnd, &ps);
		
			/*Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

			for (auto& iter : BulletList)
			{
				Ellipse(hdc, iter.left, iter.top, iter.right, iter.bottom);

				iter.top	-= 10;
				iter.bottom -= 10;
			}*/
			
            EndPaint(hWnd, &ps);
        }
        break;

	case WM_KEYDOWN:

		switch (wParam)
		{
	/*	case VK_SPACE:
			BulletList.push_back(rc);
			break;*/

		case VK_ESCAPE:
			DestroyWindow(g_hWnd);
			break;
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

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
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


// �Լ� ȣ�� �Ծ� : �Լ��� ������ ����Ǹ� �Ҵ�Ǿ��� ���� �޸𸮸� �����ؾ� �ϴµ� 
// �Լ��� ȣ���� ȣ���(caller)���� ������ ���ΰ�, ȣ�� ���� ��ȣ����(callee)���� ������ ���ΰ��� ���� ���, �Ǵ� �Ծ�

// __cdecl   : c / c++����� �⺻ ȣ�� �Ծ�, ȣ���ڰ� ���� �޸𸮸� ����, '���� ���� �Լ�'�� �۵� ������ ���� ������ ���� �޸𸮸� ������ �� ����.
// __stdcall : win32 api �⺻ ȣ�� �Ծ�, ��ȣ���ڰ� ���� �޸𸮸� ����, '���� ���� �Լ�'�� �۵� ������ ���� ������ ���� �޸𸮸� ������ �� �ִ�.

// __fastcall : �Լ� ȣ���� ������ ó���ϱ� ���� �Ծ�, �������� �޸𸮿� �Լ� �ڵ带 �����Ͽ� �Լ� ȣ���� �������� �ٰŰ� ��
// __thiscall : this �����͸� �Ű� ���� ���·� �Ѱ� �޾��� �� ����ϴ� ȣ�� �Ծ�

// __cdecl�� ȣ������� ���� �޸𸮸� ������

