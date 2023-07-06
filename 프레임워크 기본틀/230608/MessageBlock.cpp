#include "stdafx.h"
#include "MessageBlock.h"
#include "SceneMgr.h"

CMessageBlock::CMessageBlock()
	: m_iDrawID(0), m_iHp(0), m_iAttack(0), m_iDefense(0)
{

}

CMessageBlock::~CMessageBlock()
{
    Release();
}

void CMessageBlock::Text_Change(SCENEID eScene)
{
	switch (eScene) {
	case MONSTER_MATCH:
		swprintf_s(szBuff, L"* 룩스가 나타났다!");
		break;

	case MONSTER_IDLE:
		swprintf_s(szBuff, L"* 룩스는 당신을 응시하고 있다.");
		break;

	case MONSTER_ATTACK:
		m_iDrawID = 1;
		break;

	case MONSTER_PHASE:
		m_iDrawID = 2;
		break;

	case MONSTER_ACT:
		swprintf_s(szBuff, L"* 룩스 - ATK : %d, DEF : %d", m_iAttack, m_iDefense);
		break;

	case MONSTER_ITEM:
		swprintf_s(szBuff, L"* 버터스카치 파이를 먹었다.");
		if (m_dwTime + 1500 < GetTickCount64())
			swprintf_s(szBuff, L"* 체력을 5 회복했다.");
		break;

	case MONSTER_MERCY:
		swprintf_s(szBuff, L"* 당신은 자비를 베풀었다.");
		if (m_dwTime + 1500 < GetTickCount64())
			swprintf_s(szBuff, L"* 0exp와 0골드를 획득했다.");
		break;

	case BOSS_MATCH:
		swprintf_s(szBuff, L"* 토리엘이 당신 앞을 막아선다.");
		break;

	case BOSS_IDLE:
		swprintf_s(szBuff, L"* 토리엘은 아무 말도 하지 않는다.");
		break;

	case BOSS_ATTACK:
		m_iDrawID = 1;
		break;

	case BOSS_PHASE:
		m_iDrawID = 2;
		break;

	case BOSS_ACT:
		swprintf_s(szBuff, L"* 토리엘 - Attack : %d, Defense : %d", m_iAttack, m_iDefense);
		if (m_dwTime + 1500 < GetTickCount64())
			swprintf_s(szBuff, L"* 누구보다 당신을 잘 알고 있다.");
		break;

	case BOSS_ITEM:
		swprintf_s(szBuff, L"* 버터스카치 파이를 먹었다.");
		if (m_dwTime + 1500 < GetTickCount64())
			swprintf_s(szBuff, L"* 체력을 5 회복했다.");
		break;

	case BOSS_MERCY:
		swprintf_s(szBuff, L"* 당신은 자비를 베풀었다.");
		if (m_dwTime + 2000 < GetTickCount64())
			swprintf_s(szBuff, L"* 토리엘은 동요하고 있다.");
		if (m_dwTime + 4000 < GetTickCount64())
			swprintf_s(szBuff, L"* ...");
		if (m_dwTime + 6000 < GetTickCount64())
			swprintf_s(szBuff, L"* 당신의 자비가, 그의 마음을 움직였다.");
		if (m_dwTime + 8000 < GetTickCount64())
			swprintf_s(szBuff, L"* 0exp와 0골드를 획득했다.");

		break;

	}
}

void CMessageBlock::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
    m_tInfo.fCX = 700.f;
    m_tInfo.fCY = 200.f;

	CObj* pMonster = CObjMgr::Get_Instance()->Get_Monster();

	m_iHp = pMonster->Get_States().iHp;
	m_iAttack = pMonster->Get_States().iAttack;
	m_iDefense = pMonster->Get_States().iDefense;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Message.bmp", L"Message");

    m_eRender = UI;
}

int CMessageBlock::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMessageBlock::Late_Update(void)
{
	Text_Change(CSceneMgr::Get_Instance()->Get_SceneID());
}

void CMessageBlock::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Message");

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

	TextOut(hDC, (int)(m_tRect.left + 40), (int)(m_tInfo.fY - 50), szBuff, lstrlen(szBuff));
}

void CMessageBlock::Release(void)
{
}