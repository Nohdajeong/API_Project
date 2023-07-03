#include "stdafx.h"
#include "MessageBlock.h"

CMessageBlock::CMessageBlock() : m_iDrawID(0)
{
}

CMessageBlock::~CMessageBlock()
{
    Release();
}

void CMessageBlock::Text_Change()
{
	switch (m_eScene)
	{
	case IDLE:
		swprintf_s(szBuff, L"* �轺�� ��Ÿ����!");
		break;

	case FIGHT:
		swprintf_s(szBuff, L"* ����!");
		break;

	case ACT:
		swprintf_s(szBuff, L"* �ൿ!");
		break;

	case ITEM:
		swprintf_s(szBuff, L"* ������!");
		break;

	case MERCY:
		swprintf_s(szBuff, L"* �ں�!");
		break;
		
	default:		
		swprintf_s(szBuff, L"* �̰� ����Ʈ!");
		break;


	}
}

void CMessageBlock::Initialize(void)
{
    m_tInfo.fCX = 700.f;
    m_tInfo.fCY = 200.f;

	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Message.bmp", L"Message");

    m_eRender = UI;

}

int CMessageBlock::Update(void)
{
	Text_Change();
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMessageBlock::Late_Update(void)
{
	//if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	//{
	//	if (!lstrcmp(L"Attack", m_pFrameKey))
	//		swprintf_s(szBuff, L"* ����");

	//	else if (!lstrcmp(L"Act", m_pFrameKey))
	//		swprintf_s(szBuff, L"* �ൿ");

	//	else if (!lstrcmp(L"Item", m_pFrameKey))
	//		swprintf_s(szBuff, L"* ������");

	//	else if (!lstrcmp(L"Mercy", m_pFrameKey))
	//		swprintf_s(szBuff, L"* �ں�");

	//	else if (!lstrcmp(L"Idle", m_pFrameKey))
	//		swprintf_s(szBuff, L"* ����");
	//}

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

	hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("Neo�ձٸ�"));
	oldFont = (HFONT)SelectObject(hDC, hFont);
	TextOut(hDC, (float)m_tRect.left + 40.f,(float) m_tInfo.fY - 50.f, szBuff, lstrlen(szBuff));
}

void CMessageBlock::Release(void)
{
}