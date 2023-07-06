#include "stdafx.h"
#include "MessageBlock.h"
#include "SceneMgr.h"

CMessageBlock::CMessageBlock()
	: m_iDrawID(0), m_iCount(0), m_iAttack(0), m_iDefense(0)
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
		swprintf_s(szBuff, L"* �轺�� ��Ÿ����!");
		break;

	case MONSTER_IDLE:
		swprintf_s(szBuff, L"* �轺�� ����� �����ϰ� �ִ�.");
		break;

	case MONSTER_ATTACK:
		m_iDrawID = 1;
		break;

	case MONSTER_PHASE:
		m_iDrawID = 2;
		break;

	case MONSTER_ACT:
		swprintf_s(szBuff, L"* �轺 - Attack : %d, Defense : %d", m_iAttack, m_iDefense);
		break;

	case MONSTER_ITEM:
		swprintf_s(szBuff, L"* ���ͽ�īġ ���̸� �Ծ���.");
		if (m_dwTime + 1500 < GetTickCount64())
			swprintf_s(szBuff, L"* ü���� 5 ȸ���ߴ�.");
		break;

	case MONSTER_MERCY:
		swprintf_s(szBuff, L"* ����� �ں� ��Ǯ����.");
		if (m_dwTime + 1500 < GetTickCount64())
			swprintf_s(szBuff, L"* 0exp�� 0��带 ȹ���ߴ�.");
		break;

	case BOSS_MATCH:
		swprintf_s(szBuff, L"* �丮���� ��� ���� ���Ƽ���.");
		break;

	case BOSS_IDLE:
		swprintf_s(szBuff, L"* �丮���� �ƹ� ���� ���� �ʴ´�.");
		break;

	case BOSS_ATTACK:
		m_iDrawID = 1;
		break;

	case BOSS_PHASE:
		m_iDrawID = 2;
		break;

	case BOSS_ACT:
		swprintf_s(szBuff, L"* �丮�� - Attack : %d, Defense : %d", m_iAttack, m_iDefense);
		if (m_dwTime + 1500 < GetTickCount64())
			swprintf_s(szBuff, L"* �������� ����� �� �˰� �ִ�.");
		break;

	case BOSS_ITEM:
		swprintf_s(szBuff, L"* ���ͽ�īġ ���̸� �Ծ���.");
		if (m_dwTime + 1500 < GetTickCount64())
			swprintf_s(szBuff, L"* ü���� 5 ȸ���ߴ�.");
		break;

	case BOSS_MERCY:
		swprintf_s(szBuff, L"* ����� �ں� ��Ǯ����.");
		if (m_dwTime + 2000 < GetTickCount64())
			swprintf_s(szBuff, L"* �丮���� �����ϰ� �ִ�.");
		if (m_dwTime + 4000 < GetTickCount64())
			swprintf_s(szBuff, L"* ...");
		if (m_dwTime + 6000 < GetTickCount64())
			swprintf_s(szBuff, L"* ����� �ں�, ���� ������ ��������.");
		if (m_dwTime + 8000 < GetTickCount64())
			swprintf_s(szBuff, L"* 0exp�� 0��带 ȹ���ߴ�.");

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

	m_iAttack = pMonster->Get_States().iAttack;
	m_iDefense = pMonster->Get_States().iDefense;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Message.bmp", L"Message");

    m_eRender = UI;
}

int CMessageBlock::Update(void)
{
	Text_Change(CSceneMgr::Get_Instance()->Get_SceneID());

    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMessageBlock::Late_Update(void)
{
}

void CMessageBlock::Render(HDC hDC)
{
	AddFontResourceA("Neo�ձٸ�.ttf");

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Message");

	GdiTransparentBlt(hDC,
		(int)m_tRect.left, // ���� ���� ��ġ X,Y ��ǥ
		(int)m_tRect.top,
		(int)m_tInfo.fCX,	// ���� ���� ����, ���� ����
		(int)m_tInfo.fCY,
		hMemDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
		m_iDrawID * (int)m_tInfo.fCX,					// ��Ʈ���� ����� ���� X,Y��ǥ
		0,
		(int)m_tInfo.fCX,		// ����� ��Ʈ���� ����, ���� ������
		(int)m_tInfo.fCY,
		RGB(195, 134, 255)); // �����ϰ��� �ϴ� ����

	SetBkMode(hDC, 1);
	SetTextColor(hDC, RGB(255, 255, 255));
	HFONT	hFont, oldFont;

	hFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("Neo�ձٸ�"));
	oldFont = (HFONT)SelectObject(hDC, hFont);
	TextOut(hDC, (int)(m_tRect.left + 40), (int)(m_tInfo.fY - 50), szBuff, lstrlen(szBuff));
}

void CMessageBlock::Release(void)
{
}