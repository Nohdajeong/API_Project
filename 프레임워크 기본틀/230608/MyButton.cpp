#include "stdafx.h"
#include "MyButton.h"
#include "SceneMgr.h"
#include "KeyMgr.h"

CMyButton::CMyButton() : m_iDrawID(0)
{
}

CMyButton::~CMyButton()
{
    Release();
}

void CMyButton::Initialize(void)
{
    m_tInfo.fCX = 145.f;
    m_tInfo.fCY = 55.f;

    m_eRender = UI;
}

int CMyButton::Update(void)
{
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMyButton::Late_Update(void)
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_IDLE || CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_MATCH) {
			if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
			{
				if (!lstrcmp(L"Fight", m_pFrameKey))
					CSceneMgr::Get_Instance()->Scene_Change(MONSTER_ATTACK);

				else if (!lstrcmp(L"Act", m_pFrameKey))
					CSceneMgr::Get_Instance()->Scene_Change(MONSTER_ACT);

				else if (!lstrcmp(L"Item", m_pFrameKey))
					CSceneMgr::Get_Instance()->Scene_Change(MONSTER_ITEM);

				else if (!lstrcmp(L"Mercy", m_pFrameKey))
					CSceneMgr::Get_Instance()->Scene_Change(MONSTER_MERCY);

			}

			m_iDrawID = 1;
		}

		if (CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_IDLE || CSceneMgr::Get_Instance()->Get_SceneID() == BOSS_MATCH) {
			if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
			{
				if (!lstrcmp(L"Fight", m_pFrameKey))
					CSceneMgr::Get_Instance()->Scene_Change(BOSS_ATTACK);

				else if (!lstrcmp(L"Act", m_pFrameKey))
					CSceneMgr::Get_Instance()->Scene_Change(BOSS_ACT);

				else if (!lstrcmp(L"Item", m_pFrameKey))
					CSceneMgr::Get_Instance()->Scene_Change(BOSS_ITEM);

				else if (!lstrcmp(L"Mercy", m_pFrameKey))
					CSceneMgr::Get_Instance()->Scene_Change(BOSS_MERCY);

			}

			m_iDrawID = 1;
		}

	}
	else {
		m_iDrawID = 0;
	}

}

void CMyButton::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		(int)m_tRect.left, // 복사 받을 위치 X,Y 좌표
		(int)m_tRect.top,
		(int)m_tInfo.fCX,	// 복사 받을 가로, 세로 길이
		(int)m_tInfo.fCY,
		hMemDC,			// 비트맵 이미지를 담고 있는 DC
		m_iDrawID * (int)m_tInfo.fCX,					// 비트맵을 출력할 시작 X,Y좌표
		0,
		(int)m_tInfo.fCX,		// 출력할 비트맵의 가로, 세로 사이즈
		(int)m_tInfo.fCY,
		RGB(195, 134, 255)); // 제거하고자 하는 색상

}

void CMyButton::Release(void)
{
}