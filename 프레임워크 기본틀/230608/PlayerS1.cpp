#include "stdafx.h"
#include "PlayerS1.h"
#include "AbstractFactory.h"
#include "ObjMgr.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SoundMgr.h"
#include "SceneMgr.h"

CPlayerS1::CPlayerS1() 
	  : m_ePreState(STATE_END), m_eCurState(IDLE)
{
}

CPlayerS1::~CPlayerS1()
{
	Release();
}


void CPlayerS1::Initialize(void)
{
	m_tInfo.fCX = 40.f;
	m_tInfo.fCY = 60.f;

	m_fSpeed = 5.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Player/Player_Down.bmp", L"Player_DOWN");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Player/Player_Left.bmp", L"Player_LEFT");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Player/Player_Right.bmp", L"Player_RIGHT");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Player/Player_Up.bmp", L"Player_UP");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Player/Stretch.bmp", L"Player_UP");
	
	m_pFrameKey = L"Player_UP";

	if (CSceneMgr::Get_Instance()->Get_SceneID() == RUIN)
		m_pFrameKey = L"Player_DOWN";

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 500;
	m_tFrame.dwTime = GetTickCount();

	m_eRender = GAMEOBJECT;

}

int CPlayerS1::Update(void)
{
	Key_Input();
	OffSet();
	Motion_Change();

	__super::Move_Frame();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayerS1::Late_Update(void)
{
}

void CPlayerS1::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	if (CSceneMgr::Get_Instance()->Get_SceneID() == RUIN || CSceneMgr::Get_Instance()->Get_SceneID() == FLOWEY || CSceneMgr::Get_Instance()->Get_SceneID() == TORIEL)	
		GdiTransparentBlt(hDC,
			(int)m_tRect.left + iScrollX, // 복사 받을 위치 X,Y 좌표
			(int)m_tRect.top + iScrollY,
			(int)m_tInfo.fCX,	// 복사 받을 가로, 세로 길이
			(int)m_tInfo.fCY,
			hMemDC,			// 비트맵 이미지를 담고 있는 DC
			m_tFrame.iFrameStart * (int)m_tInfo.fCX,					// 비트맵을 출력할 시작 X,Y좌표
			m_tFrame.iMotion * (int)m_tInfo.fCY,
			(int)m_tInfo.fCX,		// 출력할 비트맵의 가로, 세로 사이즈
			(int)m_tInfo.fCY,
			RGB(195, 134, 255)); // 제거하고자 하는 색상

}

void CPlayerS1::Release(void)
{
}

void CPlayerS1::Key_Input(void)
{
	float	fY = 0.f;

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
		m_pFrameKey = L"Player_LEFT";
		m_eCurState = WALK;
	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
		m_pFrameKey = L"Player_RIGHT";
		m_eCurState = WALK;
	}

	else if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
		m_pFrameKey = L"Player_UP";
		m_eCurState = WALK;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
		m_pFrameKey = L"Player_DOWN";
		m_eCurState = WALK;
	}

	else
		m_eCurState = IDLE;
}

void CPlayerS1::OffSet(void)
{
	int	iOffSetX = 400;
	int	iOffSetY = 300;


	int	iScrollX = int(CScrollMgr::Get_Instance()->Get_ScollX());
	int	iScrollY = int(CScrollMgr::Get_Instance()->Get_ScollY());

	if (iOffSetX > m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffSetX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);

	if (iOffSetY > m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(m_fSpeed);

	if (iOffSetY < m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(-m_fSpeed);

}

void CPlayerS1::Motion_Change(void)
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iMotion = 0;
			m_tFrame.dwSpeed = 250;
			m_tFrame.dwTime = GetTickCount();
			break;

		case WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 1;
			m_tFrame.dwSpeed = 250;
			m_tFrame.dwTime = GetTickCount();
			break;

		}

		m_ePreState = m_eCurState;
	}

}

void CPlayerS1::Set_Location(void)
{
}
