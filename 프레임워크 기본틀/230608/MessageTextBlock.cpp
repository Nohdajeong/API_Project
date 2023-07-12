#include "stdafx.h"
#include "MessageTextBlock.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

CMessageTextBlock::CMessageTextBlock()
{

}

CMessageTextBlock::~CMessageTextBlock()
{
    Release();
}

void CMessageTextBlock::Text_Change(SCENEID eScene)
{

	switch (eScene) {
	case FLOWEY:
		swprintf_s(szBuff, L"* 안녕! 나는 플라위야, 노란꽃 플라위!");
		swprintf_s(szPlayer, L"* 이건 원래 게임과는 다른 내용이야.");
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_SPACE)) {
			swprintf_s(szBuff, L"* 당연하지, 이건 모작이니까!");
			swprintf_s(szPlayer, L"* 쉬워보이지? 직접 해보면 알거야, 하하!");
		}
		break;

	case TORIEL:
		swprintf_s(szBuff, L"* 당신의 의지가 가득 차올랐다.");
		break;
	}
}

void CMessageTextBlock::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
    m_tInfo.fCX = 700.f;
    m_tInfo.fCY = 200.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Message.bmp", L"Message");

    m_eRender = UI;
}

int CMessageTextBlock::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMessageTextBlock::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == FLOWEY || CSceneMgr::Get_Instance()->Get_SceneID() == TORIEL)
		m_bDead = true;

	Text_Change(CSceneMgr::Get_Instance()->Get_SceneID());

}

void CMessageTextBlock::Render(HDC hDC)
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
	TextOut(hDC, (int)(m_tRect.left + 40), (int)(m_tInfo.fY), szPlayer, lstrlen(szPlayer));
}

void CMessageTextBlock::Release(void)
{
}