#include "stdafx.h"
#include "Mushroom.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"

CMushroom::CMushroom()
	: m_ePreState(STATE_END), m_eCurState(IDLE)
{
}

CMushroom::~CMushroom()
{
	Release();
}

void CMushroom::Initialize(void)
{
	m_tInfo.fX = 600.f;
	m_tInfo.fY = 900.f;
	m_tInfo.fCX = 40.f;
	m_tInfo.fCY = 64.f;

	m_fSpeed = 1.f;
	m_fRange = 100.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/NPC/mushroom.bmp", L"mushroom");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 400;
	m_tFrame.dwTime = (DWORD)GetTickCount64();

	m_eRender = GAMEOBJECT;

}

int CMushroom::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	m_pTarget = CObjMgr::Get_Instance()->Get_Player();

	if (Search(m_pTarget)) {

		m_eCurState = DANCE;
	}
	else m_eCurState = IDLE;

	Motion_Change();


	__super::Move_Frame();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMushroom::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() != TORIEL)
		Set_Dead();
}

void CMushroom::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"mushroom");

	GdiTransparentBlt(hDC,
		(int)m_tRect.left + iScrollX,
		(int)m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		m_tFrame.iFrameStart * (int)m_tInfo.fCX,
		m_tFrame.iMotion * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(195, 134, 255)); // 제거하고자 하는 색상
}

void CMushroom::Release(void)
{
}

void CMushroom::Motion_Change(void)
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
			m_tFrame.dwTime = (DWORD)GetTickCount64();
			break;

		case OPEN:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 4;
			m_tFrame.iMotion = 1;
			m_tFrame.dwSpeed = 250;
			m_tFrame.dwTime = (DWORD)GetTickCount64();
			break;

		case DANCE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = 2;
			m_tFrame.dwSpeed = 250;
			m_tFrame.dwTime = (DWORD)GetTickCount64();
			break;

		}

		m_ePreState = m_eCurState;
	}

}

bool CMushroom::Search(CObj* _pTarget)
{
	if ((m_tInfo.fY + m_fRange) >= _pTarget->Get_Info().fY && (m_tInfo.fY - m_fRange) <= _pTarget->Get_Info().fY) {

		if (m_tInfo.fX > _pTarget->Get_Info().fX && (m_tInfo.fX - m_fRange) < _pTarget->Get_Info().fX)
			return true;
		else if (m_tInfo.fX < _pTarget->Get_Info().fX && (m_tInfo.fX + m_fRange) > _pTarget->Get_Info().fX)
			return true;
	}

	return false;
}
