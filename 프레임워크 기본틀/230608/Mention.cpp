#include "stdafx.h"
#include "Mention.h"
#include "SceneMgr.h"

CMention::CMention()
{

}

CMention::~CMention()
{
    Release();
}

void CMention::Text_Change(SCENEID eScene)
{
	switch (eScene) {
	case MONSTER_PHASE:
		swprintf_s(szBuff, L"그만");
		swprintf_s(szBuff2, L"쳐다봐");
		swprintf_s(szBuff3, L"줄래?");
		break;
	case BOSS_PHASE:
		swprintf_s(szBuff, L"그런");
		swprintf_s(szBuff2, L"눈으로");
		swprintf_s(szBuff3, L"보지마.");
		break;
	}
}

void CMention::Initialize(void)
{
    m_tInfo.fCX = 120.f;
    m_tInfo.fCY = 220.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mention.bmp", L"Mention");

    m_eRender = EFFECT;
}

int CMention::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;


	Text_Change(CSceneMgr::Get_Instance()->Get_SceneID());

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMention::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_PHASE || 
		CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_PHASE)
		m_bDead = false;
	else
		m_bDead = true;

}

void CMention::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Mention");
	//Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	GdiTransparentBlt(hDC,
		(int)m_tRect.left,
		(int)m_tRect.top,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		0,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(195, 134, 255));


	SetBkMode(hDC, 1);
	SetTextColor(hDC, RGB(0, 0, 0));

	TextOut(hDC, (int)(m_tRect.left + 30), (int)(m_tInfo.fY - 60), szBuff, lstrlen(szBuff));
	TextOut(hDC, (int)(m_tRect.left + 30), (int)(m_tInfo.fY - 30), szBuff2, lstrlen(szBuff2));
	TextOut(hDC, (int)(m_tRect.left + 30), (int)(m_tInfo.fY), szBuff3, lstrlen(szBuff3));


}

void CMention::Release(void)
{
}