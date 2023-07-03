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

	// MCIWndCreate : 멀티미디어를 재생하기 위한 윈도우 창을 생성하는 함수

	m_hVideo = MCIWndCreate(g_hWnd, // 부모 윈도우의 핸들
							nullptr, // MCI윈도우를 사용하는 인스턴스 핸들
							WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR, // 윈도우 모양 설정(WS_CHILD : 자식 창 형태, WS_VISIBLE : 그 즉시 그리기, MCIWNDF_NOPLAYBAR : 플레이바를 출력하지 않음)
							L"../Video/Wildlife.wmv"); // 재생할 파일의 경로

	// MoveWindow : 동영상을 재생할 크기를 설정, 설정하지 않을 경우 동영상의 원래 크기대로 출력
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
