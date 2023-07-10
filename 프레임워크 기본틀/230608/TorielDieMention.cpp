#include "stdafx.h"
#include "TorielDieMention.h"
#include "SceneMgr.h"

CTorielDieMention::CTorielDieMention()
{

}

CTorielDieMention::~CTorielDieMention()
{
    Release();
}

void CTorielDieMention::Initialize(void)
{
    m_tInfo.fCX = 240.f;
    m_tInfo.fCY = 110.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Mention2.bmp", L"Mention2");

    m_eRender = EFFECT;
}

int CTorielDieMention::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_DIE) {
		swprintf_s(szBuff, L"�� ��������");
		swprintf_s(szBuff2, L"���ϱ���...");
		if (m_dwTime + 2000 < GetTickCount64()) {
			swprintf_s(szBuff, L"���⿡��");
			swprintf_s(szBuff2, L"������...");
		}
		if (m_dwTime + 4000 < GetTickCount64()) {
			swprintf_s(szBuff, L"�ִ��� �ָ�");
			swprintf_s(szBuff2, L"������...");
		}
		if (m_dwTime + 6000 < GetTickCount64()) {
			swprintf_s(szBuff, L"����Ѵ�.");
			swprintf_s(szBuff2, L"�� �ư���...");
		}
	}
	else if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_MERCY) {
		swprintf_s(szBuff, L"�׷�...");
		swprintf_s(szBuff2, L"�װ� �׷��ٸ�");
		if (m_dwTime + 2000 < GetTickCount64()) {
			swprintf_s(szBuff, L"��¿ ��");
			swprintf_s(szBuff2, L"������.");
		}
		if (m_dwTime + 4000 < GetTickCount64()) {
			swprintf_s(szBuff, L"�ʸ� ����...");
			swprintf_s(szBuff2, L"��� ����θ�.");
		}
		if (m_dwTime + 6000 < GetTickCount64()) {
			swprintf_s(szBuff, L"����Ѵ�.");
			swprintf_s(szBuff2, L"�� �ư���.");
		}
	}


    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CTorielDieMention::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_DIE ||
		CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_MERCY)
		m_bDead = false;
	else
		Set_Dead();

}

void CTorielDieMention::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Mention2");

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

	TextOut(hDC, (int)(m_tRect.left + 50), (int)(m_tInfo.fY - 30), szBuff, lstrlen(szBuff));
	TextOut(hDC, (int)(m_tRect.left + 50), (int)(m_tInfo.fY), szBuff2, lstrlen(szBuff2));
	TextOut(hDC, (int)(m_tRect.left + 50), (int)(m_tInfo.fY + 30), szBuff3, lstrlen(szBuff3));
}

void CTorielDieMention::Release(void)
{
}