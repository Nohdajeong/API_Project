#include "stdafx.h"
#include "PlayerState.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "PlayerS1.h"

CPlayerState::CPlayerState()
    : m_iLevel(0), m_iHp(0), m_iMaxHp(0)
{
}

CPlayerState::~CPlayerState()
{
	Release();
}

void CPlayerState::Initialize(void)
{
    CObj* pPlayer = CObjMgr::Get_Instance()->Get_BattlePlayer();

    m_iLevel = (pPlayer)->Get_States().iLevel;
    m_iHp = (pPlayer)->Get_States().iHp;
    m_iMaxHp = (pPlayer)->Get_States().iMaxHp;

	m_eRender = UI;

}

int CPlayerState::Update(void)
{
	return OBJ_NOEVENT;
}

void CPlayerState::Late_Update(void)
{
}

void CPlayerState::Render(HDC hDC)
{
	AddFontResourceA("NeoµÕ±Ù¸ð.ttf");
    SetBkMode(hDC, 1);
    SetTextColor(hDC, RGB(255, 255, 255));
    HFONT	hFont, oldFont;

    hFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("NeoµÕ±Ù¸ð"));
    oldFont = (HFONT)SelectObject(hDC, hFont);

    swprintf_s(szBuff, L"FRISK   LV %d   Hp %d/%d", m_iLevel, m_iHp, m_iMaxHp);

    TextOut(hDC, 70, 500, szBuff, lstrlen(szBuff));

}

void CPlayerState::Release(void)
{
}
