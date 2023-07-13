#include "stdafx.h"
#include "Flowey.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"
#include "MessageTextBlock.h"
#include "KeyMgr.h"

CFlowey::CFlowey()
{
}

CFlowey::~CFlowey()
{
	Release();
}

void CFlowey::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 500.f;
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_fRange = 100.f;


	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/NPC/Flowey.bmp", L"Flowey");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 400;
	m_tFrame.dwTime = (DWORD)GetTickCount64();

	m_eRender = GAMEOBJECT;

}

int CFlowey::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	m_pTarget = CObjMgr::Get_Instance()->Get_Player();

	if(Search(m_pTarget))
		if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
			CObjMgr::Get_Instance()->Add_Object(TEXTBOX, CAbstractFactory<CMessageTextBlock>::Create(400.f, 100.f));

	__super::Move_Frame();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CFlowey::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() != FLOWEY)
		Set_Dead();
}

void CFlowey::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Flowey");

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
		RGB(241, 95, 241));
}

void CFlowey::Release(void)
{
}

bool CFlowey::Search(CObj* _pTarget)
{
	if ((m_tInfo.fY + m_fRange) >= _pTarget->Get_Info().fY && (m_tInfo.fY - m_fRange) <= _pTarget->Get_Info().fY) {

		if (m_tInfo.fX > _pTarget->Get_Info().fX && (m_tInfo.fX - m_fRange) < _pTarget->Get_Info().fX)
			return true;
		else if (m_tInfo.fX < _pTarget->Get_Info().fX && (m_tInfo.fX + m_fRange) > _pTarget->Get_Info().fX)
			return true;
	}

	return false;
}
