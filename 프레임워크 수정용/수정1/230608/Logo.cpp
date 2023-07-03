#include "stdafx.h"
#include "Logo.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

CLogo::CLogo()
{
}

CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize()
{

	// MCIWndCreate : ��Ƽ�̵� ����ϱ� ���� ������ â�� �����ϴ� �Լ�

	m_hVideo = MCIWndCreate(g_hWnd, // �θ� �������� �ڵ�
							nullptr, // MCI�����츦 ����ϴ� �ν��Ͻ� �ڵ�
							WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR, // ������ ��� ����(WS_CHILD : �ڽ� â ����, WS_VISIBLE : �� ��� �׸���, MCIWNDF_NOPLAYBAR : �÷��̹ٸ� ������� ����)
							L"../Video/Wildlife.wmv"); // ����� ������ ���

	// MoveWindow : �������� ����� ũ�⸦ ����, �������� ���� ��� �������� ���� ũ���� ���
	MoveWindow(m_hVideo, 0, 0, WINCX, WINCY, FALSE);

	MCIWndPlay(m_hVideo);


	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Logo/Logo.bmp", L"Logo");
}

void CLogo::Update()
{
}

void CLogo::Late_Update()
{
	if (MCIWndGetLength(m_hVideo) <= MCIWndGetPosition(m_hVideo) 
		|| CKeyMgr::Get_Instance()->Key_Down(VK_RETURN))
	{
		CSceneMgr::Get_Instance()->Scene_Change(SC_MENU);
		return;
	}
}

void CLogo::Render(HDC hDC)
{
	//HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Logo");
	//BitBlt(hDC,	0, 0, WINCX, WINCY, hMemDC,	0, 0, SRCCOPY);
}

void CLogo::Release()
{
	MCIWndClose(m_hVideo);
}
