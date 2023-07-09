#include "stdafx.h"
#include "MyButton.h"
#include "SceneMgr.h"
#include "KeyMgr.h"
#include "SoundMgr.h"

float	g_fSound = 3.f;

CMyButton::CMyButton() 
	: m_iDrawID(0)
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
	if (m_bDead)
		return OBJ_DEAD;

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMyButton::Late_Update(void)
{
	if (CSceneMgr::Get_Instance()->Get_ScenePreID() == RUIN)
		Set_Dead();
	
	else {
		POINT	pt{};
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);

		if (PtInRect(&m_tRect, pt))
		{
			if (CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_IDLE || CSceneMgr::Get_Instance()->Get_SceneID() == MONSTER_MATCH) {
				if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
				{
					if (!lstrcmp(L"Fight", m_pFrameKey)) {
						CSceneMgr::Get_Instance()->Scene_Change(MONSTER_ATTACK);
					}
					else if (!lstrcmp(L"Act", m_pFrameKey)) {
						CSceneMgr::Get_Instance()->Scene_Change(MONSTER_ACT);
					}
					else if (!lstrcmp(L"Item", m_pFrameKey)) {
						CSceneMgr::Get_Instance()->Scene_Change(MONSTER_ITEM);
					}
					else if (!lstrcmp(L"Mercy", m_pFrameKey)) {
						CSceneMgr::Get_Instance()->Scene_Change(MONSTER_MERCY);
					}
				}

				m_iDrawID = 1;
				CSoundMgr::Get_Instance()->PlaySoundW(L"Select.wav", SOUND_EFFECT, g_fSound);
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
				CSoundMgr::Get_Instance()->PlaySoundW(L"Select.wav", SOUND_EFFECT, g_fSound);
			}
		}
		else {
			m_iDrawID = 0;
		}
	}

}

void CMyButton::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

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
		RGB(195, 134, 255));

}

void CMyButton::Release(void)
{
	CSoundMgr::Get_Instance()->StopSound(SOUND_BGM);
}