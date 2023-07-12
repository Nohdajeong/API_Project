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
		swprintf_s(szBuff2, L"* �ʴ� �̰��� ó���Ա���, �׷���?");
		if (m_dwTime + 2000 < GetTickCount64()) {
			swprintf_s(szBuff, L"* ������, ���� �˷��ٰ�!");
			swprintf_s(szBuff2, L"* ...����. ����� ���� ������ �ƴϾ���?");
		}
		if (m_dwTime + 4000 < GetTickCount64()) {
			swprintf_s(szBuff, L"* �׷� ��, ��¿ �� ����.");
			swprintf_s(szBuff2, L"* �� ������ ���⼭ ���̰ڳ�.");
		}
		if (m_dwTime + 6000 < GetTickCount64()) {
			swprintf_s(szBuff, L"* ��, ���غ����!");
			swprintf_s(szBuff2, L"* ���� �̷��� ������, ģ��!");
		}
		if (m_dwTime + 8000 < GetTickCount64()) {
			swprintf_s(szBuff, L"* �˾Ƽ� �� �غ����, ����!");
			swprintf_s(szBuff2, L" ");
		}

		break;

	case TORIEL:
		swprintf_s(szBuff, L"* (������ �׸��ڰ� ���ǲ�� �ھƿ�����,");
		swprintf_s(szBuff2, L"����� ������ �ھ� ������.)");

		if (m_dwTime + 2000 < GetTickCount64()) {
			swprintf_s(szBuff, L"* (ü���� ��� ȸ���Ǿ���.) ");
			swprintf_s(szBuff2, L" ");
		}

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
	Text_Change(CSceneMgr::Get_Instance()->Get_SceneID());

	if (CSceneMgr::Get_Instance()->Get_SceneID() == FLOWEY)
		if (m_dwTime + 10000 < GetTickCount64())
			m_bDead = true;

	if (CSceneMgr::Get_Instance()->Get_SceneID() == TORIEL)
		if (m_dwTime + 3000 < GetTickCount64())
			m_bDead = true;

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
	TextOut(hDC, (int)(m_tRect.left + 40), (int)(m_tInfo.fY), szBuff2, lstrlen(szBuff2));

}

void CMessageTextBlock::Release(void)
{
}