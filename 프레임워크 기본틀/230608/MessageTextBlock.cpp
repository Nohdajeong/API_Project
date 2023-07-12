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
		swprintf_s(szBuff, L"* �ȳ�! ���� �ö�����, ����� �ö���!");
		swprintf_s(szPlayer, L"* �̰� ���� ���Ӱ��� �ٸ� �����̾�.");
		if (CKeyMgr::Get_Instance()->Key_Pressing(VK_SPACE)) {
			swprintf_s(szBuff, L"* �翬����, �̰� �����̴ϱ�!");
			swprintf_s(szPlayer, L"* ����������? ���� �غ��� �˰ž�, ����!");
		}
		break;

	case TORIEL:
		swprintf_s(szBuff, L"* ����� ������ ���� ���ö���.");
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