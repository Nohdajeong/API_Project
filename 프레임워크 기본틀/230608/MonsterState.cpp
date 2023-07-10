#include "stdafx.h"
#include "MonsterState.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "SceneMgr.h"
#include "CollisionMgr.h"

CMonsterState::CMonsterState()
    : m_iLevel(0), m_iCurHp(0), m_iMaxHp(0), m_dwTime(GetTickCount64())
{
}

CMonsterState::~CMonsterState()
{
	Release();
}

void CMonsterState::Initialize(void)
{
    CObj* pMonster = CObjMgr::Get_Instance()->Get_Monster();

    m_iMaxHp = (pMonster)->Get_MaxHp();
    m_iCurHp = (pMonster)->Get_Hp();
    m_iAttack = 1;

    m_tInfo.fX = (pMonster)->Get_Info().fX;
    m_tInfo.fY = (pMonster)->Get_Rect().top - 30.f;

    m_tInfo.fCX = 85.f;
    m_tInfo.fCY = 15.f;

    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/hp_base.bmp", L"hp_base");
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/hp_max.bmp", L"hp_max");

	m_eRender = UI;

}

int CMonsterState::Update(void)
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonsterState::Late_Update(void)
{
    if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_ATTACK ||
        CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_ATTACK)
        m_bDead = false;
    else
        m_bDead = true;

}

void CMonsterState::Render(HDC hDC)
{
    HDC     hBaseDC = CBmpMgr::Get_Instance()->Find_Img(L"hp_base");
    HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"hp_max");


    SetBkMode(hDC, 1);
    SetTextColor(hDC, RGB(255, 255, 255));

    swprintf_s(szBuff, L"%d", m_iCurHp);

    TextOut(hDC, m_tInfo.fX - 80.f, m_tInfo.fY - 10.f, szBuff, lstrlen(szBuff));

    GdiTransparentBlt(hDC,
        (int)m_tRect.left,
        (int)m_tRect.top,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hBaseDC,
        0,
        0,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        RGB(195, 134, 255));

    GdiTransparentBlt(hDC,
        (int)m_tRect.left,
        (int)m_tRect.top,
        (int)m_tInfo.fCX,
        (int)m_tInfo.fCY,
        hMemDC,
        0,
        0,
        (int)m_tInfo.fCX * (m_iCurHp / m_iMaxHp),
        (int)m_tInfo.fCY,
        RGB(195, 134, 255));

}

void CMonsterState::Release(void)
{
}
