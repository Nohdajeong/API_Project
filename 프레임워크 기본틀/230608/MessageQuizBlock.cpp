#include "stdafx.h"
#include "MessageQuizBlock.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

CMessageQuizBlock::CMessageQuizBlock()
{

}

CMessageQuizBlock::~CMessageQuizBlock()
{
    Release();
}

void CMessageQuizBlock::Text_Change()
{
	if (m_pTarget->Get_Info().fX < 400.f) {
		if (m_pTarget->Get_Info().fY < 1000.f && m_pTarget->Get_Info().fY >= 900.f) {
			swprintf_s(szBuff, L"* ㅓ어아!!");
			swprintf_s(szBuff2, L"* 난 테미얌!!!");
			if (m_dwTime + 2000 < GetTickCount64())
			{
				swprintf_s(szBuff, L"* 구리고 요긴 내 틘구...");
				swprintf_s(szBuff2, L"* 테미!!!");

			}
		}
		else if (m_pTarget->Get_Info().fY < 900.f && m_pTarget->Get_Info().fY >= 800.f) {
			swprintf_s(szBuff, L"* ㅓ어아!!");
			swprintf_s(szBuff2, L"* 난 테미얌!!!");
			if (m_dwTime + 2000 < GetTickCount64())
			{
				swprintf_s(szBuff, L"* 내 틘구 잇디마!");
				swprintf_s(szBuff2, L" ");

			}
		}
		else if (m_pTarget->Get_Info().fY < 800.f && m_pTarget->Get_Info().fY >= 700.f) {
			swprintf_s(szBuff, L"* 안녕.");
			swprintf_s(szBuff2, L" ");
			if (m_dwTime + 2000 < GetTickCount64())
			{
				swprintf_s(szBuff, L"* 난 밥이야.");
				swprintf_s(szBuff2, L" ");

			}
		}
	}
	else {
		swprintf_s(szBuff, L"* (당신은 어떻게 하면 코딩을 잘할 수 있는지 물었다.)");
		swprintf_s(szBuff2, L" ");
		if (m_dwTime + 2000 < GetTickCount64())
		{
			swprintf_s(szBuff, L"* 잘하는 법?");
			swprintf_s(szBuff2, L"* 그냥 닥치고 해.");
		}
	}
}

void CMessageQuizBlock::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
    m_tInfo.fCX = 700.f;
    m_tInfo.fCY = 200.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Message.bmp", L"Message");

    m_eRender = UI;
}

int CMessageQuizBlock::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;


    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMessageQuizBlock::Late_Update(void)
{
	Text_Change();

	if (CSceneMgr::Get_Instance()->Get_SceneID() == TORIEL) {
		if (m_pTarget->Get_Info().fX < 400.f) {
			if (m_dwTime + 4000 < GetTickCount64())
				Set_Dead();
		}
		else
			if (m_dwTime + 6000 < GetTickCount64())
				Set_Dead();
	}
}

void CMessageQuizBlock::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Message");

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
	SetTextColor(hDC, RGB(255, 255, 255));

	TextOut(hDC, (int)(m_tRect.left + 40), (int)(m_tInfo.fY - 50), szBuff, lstrlen(szBuff));
	TextOut(hDC, (int)(m_tRect.left + 40), (int)(m_tInfo.fY), szBuff2, lstrlen(szBuff2));
	TextOut(hDC, (int)(m_tRect.left + 40), (int)(m_tInfo.fY + 50), szBuff3, lstrlen(szBuff3));


}

void CMessageQuizBlock::Release(void)
{
}