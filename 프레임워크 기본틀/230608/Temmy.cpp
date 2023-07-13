#include "stdafx.h"
#include "Temmy.h"
#include "ScrollMgr.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "MessageQuizBlock.h"

CTemmy::CTemmy()
{
}

CTemmy::~CTemmy()
{
	Release();
}

void CTemmy::Initialize(void)
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 45.f;

	m_fRange = 50.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/NPC/Temmy.bmp", L"Temmy");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 400;
	m_tFrame.dwTime = (DWORD)GetTickCount64();

	m_eRender = GAMEOBJECT;

}

int CTemmy::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	m_pTarget = CObjMgr::Get_Instance()->Get_Player();

	if (Search(m_pTarget)) {
		if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
		{
			CObj* pObj = CAbstractFactory<CMessageQuizBlock>::Create(400.f, 100.f);
			pObj->Set_Target(this);
			CObjMgr::Get_Instance()->Add_Object(TEXTBOX, pObj);

		}
	}

	__super::Move_Frame();
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTemmy::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() != TORIEL)
		Set_Dead();
}

void CTemmy::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Temmy");

	GdiTransparentBlt(hDC,
		(int)m_tRect.left + iScrollX,
		(int)m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		0,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(196, 133, 255)); // 제거하고자 하는 색상
}

void CTemmy::Release(void)
{
}

bool CTemmy::Search(CObj* _pTarget)
{
	if ((m_tInfo.fY + m_fRange) >= _pTarget->Get_Info().fY && (m_tInfo.fY - m_fRange) <= _pTarget->Get_Info().fY) {

		if (m_tInfo.fX > _pTarget->Get_Info().fX && (m_tInfo.fX - m_fRange) < _pTarget->Get_Info().fX)
			return true;
		else if (m_tInfo.fX < _pTarget->Get_Info().fX && (m_tInfo.fX + m_fRange) > _pTarget->Get_Info().fX)
			return true;
	}

	return false;
}
