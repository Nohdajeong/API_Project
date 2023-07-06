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
		swprintf_s(szBuff, L"±×¸¸ ÃÄ´ÙºÁÁÙ·¡ ?");
		break;
	case BOSS_PHASE:
		swprintf_s(szBuff, L"* ±×¸¸ ÃÄ´ÙºÁÁÙ·¡?");
		break;
	}
}

void CMention::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 200.f;
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
	if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_ATTACK || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_ATTACK)
		m_bDead = false;
	else
		m_bDead = true;

}

void CMention::Render(HDC hDC)
{
	AddFontResourceA("NeoµÕ±Ù¸ð.ttf");

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Mention");

	GdiTransparentBlt(hDC,
		(int)m_tRect.left,
		(int)m_tRect.top,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		hMemDC,
		m_iDrawID * (int)m_tInfo.fCX,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 102, 255));

	SetBkMode(hDC, 1);
	SetTextColor(hDC, RGB(255, 255, 255));
	HFONT	hFont, oldFont;

	hFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("NeoµÕ±Ù¸ð"));
	oldFont = (HFONT)SelectObject(hDC, hFont);
	TextOut(hDC, (int)(m_tRect.left + 40), (int)(m_tInfo.fY - 50), szBuff, lstrlen(szBuff));
}

void CMention::Release(void)
{
}